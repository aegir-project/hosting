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
    $depends_on = isset($info['dependencies']['features']) ? $info['dependencies']['features'] : FALSE;
    if ($depends_on) {
      $description .= theme('hosting_feature_dependencies', $depends_on, 'Depends on', $features);
    }
    // Gather relying features and their statuses
    $required_by = isset($info['dependencies']['reverse']) ? $info['dependencies']['reverse'] : FALSE;
    if ($required_by) {
      $description .= theme('hosting_feature_dependencies', $required_by, 'Required by', $features);
    }

    // Disable checkbox for required features.
    $locked = FALSE;
    if ($info['status'] == HOSTING_FEATURE_REQUIRED) {
      $locked = TRUE;
    }
    elseif ($required_by) {
      foreach ($required_by as $mod => $feat) {
        $locked = $features[$feat]['enabled'] ? TRUE : $locked;
      }
    }

    $element = array(
      '#type' => 'checkbox',
      '#title' => $info['title'],
      '#description' => $description,
      '#default_value' => $info['status'] == HOSTING_FEATURE_REQUIRED ? HOSTING_FEATURE_REQUIRED : hosting_feature($feature),
      '#required' => $info['status'] == HOSTING_FEATURE_REQUIRED,
      '#disabled' => $locked,
    );

    // Add another fieldset based on contrib module package.
    $package = FALSE;
    if ($info['package'] != 'Hosting') {
      $package = array(
        '#type' => 'fieldset',
        '#title' => $info['package'],
        '#collapsed' => FALSE,
        '#collapsible' => TRUE,
      );
    }
    if ($package) {
      if ($info['group'] == 'required') {
        if (!isset($required[$info['package']])) {
          $required[$info['package']] = $package;
        }
        $required[$info['package']]['hosting_feature_' . $feature] = $element;
      }
      elseif ($info['group'] == 'optional') {
        if (!isset($optional[$info['package']])) {
          $optional[$info['package']] = $package;
        }
        $optional[$info['package']]['hosting_feature_' . $feature] = $element;
      }
      else {
        if (!isset($experimental[$info['package']])) {
          $experimental[$info['package']] = $package;
        }
        $experimental[$info['package']]['hosting_feature_' . $feature] = $element;
      }
    }
    // This feature is in the 'Hosting' module package
    else {
      if ($info['group'] == 'required') {
        $required['hosting_feature_' . $feature] = $element;
      }
      elseif ($info['group'] == 'optional') {
        $optional['hosting_feature_' . $feature] = $element;
      }
      else {
        $experimental['hosting_feature_' . $feature] = $element;
      }
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
  // Get form values, filtering out irrelevant entries.
  $values = array_filter($form_state['values'], 'is_int');

  $features = hosting_get_features();

  // List of features currently enabled.
  $enabled = array();
  // List of features to enable.
  $enable = array();
  // List of features to disable.
  $disable = array();

  foreach ($features as $feature => $info) {
    $value = $values['hosting_feature_' . $feature];
    $current = $info['enabled'];
    if ($current) {
      $enabled[$features[$feature]['module']] = $features[$feature]['title'];
      if (!$value) {
        $disable[$features[$feature]['module']] = $features[$feature]['title'];
      }
    }
    elseif ($value) {
      $enable[$features[$feature]['module']] = $features[$feature]['title'];
      // Add dependencies to enable
      if (count($info['dependencies']['features'])){
        foreach ($info['dependencies']['features'] as $module_dep => $feature_dep) {
          $enable[$module_dep] = $features[$feature_dep]['title'];
        }
      }
    }
  }

  // Remove any features we're about to enable from those to disable.
  $disable = array_diff_assoc($disable, $enable);
  // Remove any features already enabled from those to enable.
  $enable = array_diff_assoc($enable, $enabled);

  include_once('includes/install.inc');

  // Enable the feature(s).
  if (count($enable)) {
    drupal_set_message(t("Enabling %feature feature!plural.", array(
      '%feature' => implode(", ", $enable),
      '!plural' => count($enable) > 1 ? 's' : '',
    )));
    drupal_install_modules(array_keys($enable));
    foreach ($enable as $module => $feature) {
      if (function_exists($callback = $features[$feature]['enable'])) {
        $callback();
      }
      variable_set('hosting_feature_' . $feature, HOSTING_FEATURE_ENABLED);
    }
  }

  // Disable the feature(s).
  if (count($disable)) {
    drupal_set_message(t("Disabling %feature feature!plural.", array(
      '%feature' => implode(", ", $disable),
      '!plural' => count($disable) > 1 ? 's' : '',
    )));
    module_disable(array_keys($disable));
    foreach ($disable as $module => $feature) {
      if (function_exists($callback = $features[$feature]['disable'])) {
        $callback();
      }
      variable_set('hosting_feature_' . $feature, HOSTING_FEATURE_DISABLED);
    }
  }

  // Rebuild schema.
  drupal_get_schema(NULL, TRUE);

  // Rebuild menu.
  menu_rebuild();

  // Record the enabled features in /var/aegir/.drush/drushrc.php
  hosting_add_task(hosting_get_hostmaster_nid(), 'verify');

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

    // Add module dependencies, package and enabled status
    $module_cache = module_rebuild_cache();
    $modules = array();
    foreach ($features as $feature => $info) {
      $features[$feature]['enabled'] = $module_cache[$info['module']]->status;
      $features[$feature]['package'] = $module_cache[$info['module']]->info['package'];
      $features[$feature]['dependencies']['modules'] = $module_cache[$info['module']]->info['dependencies'];
      // Generate a list of features keyed by module name
      $modules[$info['module']] = $feature;
    }

    // Add Hosting feature dependencies, keyed by module
    foreach ($features as $feature => $info) {
      foreach ($info['dependencies']['modules'] as $dependency) {
        if (array_key_exists($dependency, $modules) && in_array($modules[$dependency], array_keys($features))) {
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

/**
 * Theme function to display Hosting feature dependencies.
 */
function theme_hosting_feature_dependencies($dependencies, $prefix, $features) {
  $return = "<div class=\"admin-required\">$prefix:";
  $last = end($dependencies);
  reset($dependencies);
  foreach ($dependencies as $module => $require) {
    $return .= ' ' . $features[$require]['title'];
    $enabled = $features[$require]['enabled'] ? 'enabled' : 'disabled';
    $return .= " (<span class=\"admin-$enabled\">";
    $return .= $enabled;
    $return .= '</span>)';
    $return .= $require == $last ? '.</div>' : ',';
  }

  return $return;
}
