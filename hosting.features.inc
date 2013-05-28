<?php
/**
 * @file
 *   Include for functionality related to Hosting module features.
 */

/**
 * This hosting feature is disabled.
 */
define('HOSTING_FEATURE_DISABLED', 0);

/**
 * This hosting feature is enabled.
 */
define('HOSTING_FEATURE_ENABLED', 1);

/**
 * This hosting feature is required.
 */
define('HOSTING_FEATURE_REQUIRED', 2);


/**
 * Determine whether a specific feature of the hosting system is turned on.
 *
 * @param $feature
 *   The feature to check the status of, e.g. "client" or "platform".
 * @return
 *    TRUE if the feature is enabled, FALSE if it is disabled.
 */
function hosting_feature($feature) {
  static $features = array();

  if (!sizeof($features)) {
    $features = hosting_get_features();
  }
  if (isset($features[$feature]['status']) && ($features[$feature]['status'] == HOSTING_FEATURE_REQUIRED)) {
    $return = module_exists($features[$feature]['module']) ? HOSTING_FEATURE_REQUIRED : HOSTING_FEATURE_DISABLED;
  }
  elseif (isset($features[$feature]['module'])) {
    $return = (module_exists($features[$feature]['module'])) ? HOSTING_FEATURE_ENABLED : HOSTING_FEATURE_DISABLED;
  }
  else {
    $return = variable_get('hosting_feature_' . $feature, !empty($features[$feature]['status']));
  }
  return $return;
}

/**
 * The Hosting features form.
 *
 * This returns a form with any known Hosting features grouped and listed. It
 * allows administrators to enable or disable the features.
 *
 * @return
 *   A drupal form.
 *
 * @see hosting_features_form_submit()
 */
function hosting_features_form() {
  $optional = array(
    '#type' => 'fieldset',
    '#title' => t('Optional system features'),
    '#description' => t('You may choose any of the additional system features from the list below.'),
    '#collapsible' => FALSE,
  );

  $required = array(
    '#type' => 'fieldset',
    '#title' => t('Required system features'),
    '#collapsed' => TRUE,
    '#collapsible' => TRUE,
    '#weight' => -10,
    '#description' => t("These features are central to Aegir's functionality, and thus cannot be disabled."),
  );

  $experimental = array(
    '#type' => 'fieldset',
    '#title' => t('Experimental'),
    '#collapsed' => TRUE,
    '#collapsible' => TRUE,
    '#description' => t('Features marked experimental have not been completed to a satisfactory level to be considered production ready, so use at your own risk.'),
  );

  $features = hosting_get_features(TRUE);
  foreach ($features as $feature => $info) {
    $description = $info['description'];
    // Gather dependencies and their statuses
    if (isset($info['dependencies']['features'])) {
      $description .= "<div class=\"admin-dependencies\">Depends on:";
      $last = end($info['dependencies']['features']);
      reset($info['dependencies']['features']);
      foreach ($info['dependencies']['features'] as $module => $dependency) {
        $description .= ' ' . $features[$dependency]['title'];
        $enabled = $features[$dependency]['enabled'] ? 'enabled' : 'disabled';
        $description .= " (<span class=\"admin-$enabled\">";
        $description .= $enabled;
        $description .= '</span>)';
        $description .= $dependency == $last ? '.</div>' : ',';
      }
    }
    // Gather relying features and their statuses
    if (isset($info['dependencies']['reverse'])) {
      $description .= "<div class=\"admin-required\">Required by:";
      $last = end($info['dependencies']['reverse']);
      reset($info['dependencies']['reverse']);
      foreach ($info['dependencies']['reverse'] as $module => $require) {
        $description .= ' ' . $features[$require]['title'];
        $enabled = $features[$require]['enabled'] ? 'enabled' : 'disabled';
        $description .= " (<span class=\"admin-$enabled\">";
        $description .= $enabled;
        $description .= '</span>)';
        $description .= $rely == $last ? '.</div>' : ',';
      }
    }
    $element = array(
      '#type' => 'checkbox',
      '#title' => $info['title'],
      '#description' => $description,
      '#default_value' => $info['status'] == HOSTING_FEATURE_REQUIRED ? 1 : hosting_feature($feature),
      '#required' => $info['status'] == HOSTING_FEATURE_REQUIRED,
      '#disabled' => $info['status'] == HOSTING_FEATURE_REQUIRED,
    );
    if ($info['group'] == 'required') {
      $required['hosting_feature_' . $feature] = $element;
    }
    elseif ($info['group'] == 'experimental') {
      $experimental['hosting_feature_' . $feature] = $element;
    }
    else {
      $optional['hosting_feature_' . $feature] = $element;
    }

  }
  $form['required'] = $required;
  $form['optional'] = $optional;
  $form['experimental'] = $experimental;
  $form['#submit'][] = 'hosting_features_form_submit';
  return system_settings_form($form);
}

/**
 * Submit callback for the Hosting features form.
 *
 * We process the submitted values and enable any features that the user has
 * requested. This may involve enabling a module and their dependencies and/or
 * calling a specified callback function.
 *
 * @param $form
 *   The built form.
 * @param $form_state
 *   The current form state.
 *   
 * @see hosting_features_form()
 * @see hook_hosting_feature()
 */
function hosting_features_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $features = hosting_get_features(TRUE);
  $module_cache = module_rebuild_cache();
  foreach ($features  as $feature => $info) {
    $value = $values['hosting_feature_' . $feature];
    $current = hosting_feature($feature);
    if ((!$current) && $value) {
      if ($module = $features[$feature]['module']) {
        include_once('includes/install.inc');

        $modules = array($module);

        // Gather any dependencies to enable
        foreach ($module_cache[$module]->info['dependencies'] as $dependency) {
          if (!module_exists($dependency)) {
            $modules[] = $dependency;
          }
        }

        // Enable the module(s).
        drupal_set_message(t("Enabling %module module!plural", array(
          '%module' => implode(", ", $modules),
          '!plural' => count($modules) > 1 ? 's' : '',
        )));
        drupal_install_modules($modules);
      }
      if (function_exists($callback = $features[$feature]['enable'])) {
        $callback();
      }
    }
    if ($current && !$value) {
      $dependencies = array();
      if ($module = $features[$feature]['module']) {
        $modules = array($module);
        $files = module_rebuild_cache();
        foreach ($files as $dependency => $file) {
          if (isset($file->info['dependencies']) && is_array($file->info['dependencies'])) {
            if (in_array($module, $file->info['dependencies']) && $file->status) {
              $dependencies[] = $dependency;
            }
          }
        }

        if ($dependencies) {
          form_set_error('', t("You cannot disable %module because %dep depends on it", array('%module' => $module, '%dep' => implode(', ', $dependencies))));
        }
        else {
          drupal_set_message(t("Disabling %module module", array('%module' => implode(",", $modules))));
          // turn off module
          module_disable($modules);
          if (function_exists($callback = $features[$feature]['disable'])) {
            $callback();
          }
        }
      }
    }
    #print("$feature $current $value $module <br />");
  }
  // Rebuild schema.
  drupal_get_schema(NULL, TRUE);

  // Rebuild menu.
  menu_rebuild();
}

/**
 * Get a listing of all known Hosting features.
 *
 * @param $refresh
 *   (optional) Pass in TRUE to force the list of features to be rebuilt and not
 *   returned from the cache.
 * @return
 *   An array of Hosting features.
 *
 * @see hook_hosting_feature()
 */
function hosting_get_features($refresh = FALSE) {
  $cache = cache_get('hosting_features');

  if (empty($cache->data) || $refresh) {
    ## include any optional hosting.feature.*.inc files
    $files = drupal_system_listing("hosting\.feature\.[a-zA-Z_]*\.inc$", "modules");
    if (sizeof($files)) {
      foreach ($files as $name => $info) {
        include_once($info->filename);
      }
    }
    $functions = get_defined_functions();
    foreach ($functions['user'] as $function) {
      if (preg_match('/_hosting_feature$/', $function)) {
        $hooks[] = $function;
      }
    }
    $features = array();
    foreach ($hooks as $func) {
      $features = array_merge($features, $func());
    }
    // Add module dependencies and enabled status
    $module_cache = module_rebuild_cache();
    foreach ($features as $feature => $info) {
      $features[$feature]['enabled'] = $module_cache[$info['module']]->status;
      $features[$feature]['dependencies']['modules'] = $module_cache[$info['module']]->info['dependencies'];
    }
    // Generate a list of features keyed by module name
    $modules = array();
    foreach ($features as $feature => $info) {
      $modules[$info['module']] = $feature;
    }
    // Add Hosting feature dependencies, keyed by module
    foreach ($features as $feature => $info) {
      foreach ($info['dependencies']['modules'] as $dependency) {
        $feature_name = $modules[$dependency];
        if (in_array($feature_name, array_keys($features))) {
          $features[$feature]['dependencies']['features'][$dependency] = $modules[$dependency];
          $features[$modules[$dependency]]['dependencies']['reverse'][$info['module']] = $feature;
        }
      }
    }

    cache_set('hosting_features', $features);
    return $features;
  }
  else {
    return $cache->data;
  }
}

/**
 * Determine which node types are provided by Hosting features.
 * 
 * @param $refresh
 *   (optional) Pass in TRUE to force the list of node types to be rebuilt and
 *   not returned from the cache.
 * @return
 *   An array of node types keyed by the Hosting feature that provides them.
 */
function hosting_feature_node_types($refresh = FALSE) {
  static $types;

  if (!is_array($types) || $refresh) {
    $features = hosting_get_features($refresh);
    foreach ($features as $feature => $info) {
      if (!empty($info['node'])) {
        $types[$feature] = $info['node'];
      }
    }
  }
  return $types;
}
