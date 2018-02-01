<?php
/**
 * @file
 * Site node form.
 */

/**
 * Helper function to generate form elements for the site form.
 */
function _hosting_site_field(&$form, $node, $item, $element, $filter_display = 'filter_xss', $editable = FALSE, $show_desc = TRUE) {
  $css_id = str_replace("_", "-", $item);

  $type = $element['#type'];

  if (!isset($node->nid) || $editable) {
    // Create it.
    if (($element['#type'] == 'radios') && !count($element['#options'])) {
      $form[$item] = array(
        '#type' => 'value',
        '#value' => !empty($element['#default_value']) ? $element['#default_value'] : NULL,
      );
    }
    else {
      $form[$item] = $element;
    }

    if ($show_desc) {
      // The text to display when there are no valid options to select.
      $form[$item . '_description'] = array(
        '#prefix' => "<div class='hosting-site-field-description' id='hosting-site-field-{$css_id}-description'>",
        '#suffix' => '</div>',
        '#type' => 'item',
        '#title' => $element['#title'],
        '#description' => isset($element['#description']) ? $element['#description'] : NULL,
        '#markup' => "<div class='placeholder'>" . $filter_display($element['#default_value']) . "</div>",
      );
      if (isset($element['#weight'])) {
        $form[$item . '_description']['#weight'] = $element['#weight'];
      }
    }
  }
  else {
    $type = 'display';

    if ($show_desc) {
      // Display it.
      $form['info'][$item] = array(
        '#type' => 'item',
        '#title' => $element['#title'],
        '#markup' => $filter_display($element['#default_value']),
        '#required' => FALSE,
      );

      if (isset($element['#weight'])) {
        $form['info'][$item]['#weight'] = $element['#weight'];
      }
    }

    $form[$item] = array(
      '#type' => 'hidden',
      '#value' => $element['#default_value'],
    );
  }

  $form[$item]['#hosting_site_field'] = $item;
  $form[$item]['#hosting_site_field_value'] = $element['#default_value'];
  $form[$item]['#prefix'] = "<div class='hosting-site-field hosting-site-field-{$type}' id='hosting-site-field-{$css_id}'>";
  $form[$item]['#suffix'] = "</div>";
}


/**
 * Pass in a site node and return an array of valid options for it's fields.
 *
 * Modules can define the hook_hosting_site_options_alter function to modify
 * which fields are available for selection.
 */
function hosting_site_available_options($node, $platform = NULL) {
  // Cast to object if it's an array.
  $node = (is_array($node)) ? (object) $node : clone $node;

  $return = array();

  $return['profile'] = array();
  $return['platform'] = array();
  $return['site_language'] = array();

  if (!hosting_feature('client')) {
    // Setting the return value of a text field to null,
    // will signal to the front end that the field needs to
    // be displayed, but is not editable.
    $return['client'] = NULL;
  }

  // Load up the user we'll use to check platform and profile access.
  $user = user_load($GLOBALS['user']->uid);

  // Install profiles.
  $profiles = hosting_get_profiles();
  $platform_profiles = array();
  foreach ($profiles as $id => $name) {

    // Trim down the list of profiles to those that are available and the user has access to
    // XXX This hack (next 22 lines) hides profiles that can't be accessed
    // Eventually we should lighten up the content of this callback.
    $result = db_query("SELECT l.nid
                        FROM {hosting_package_instance} i
                        JOIN {hosting_package} p
                        ON p.nid = i.package_id
                        JOIN {hosting_platform} l
                        ON l.nid = i.rid
                        WHERE i.package_id = :package_id
                        AND p.package_type = :package_type
                        AND l.status = :status;",
                        array(
                          ':package_id' => $id,
                          ':package_type' => 'profile',
                          ':status' => HOSTING_PLATFORM_ENABLED,
                        )
                      );
    if (is_null($platform)) {
      $allowed_plats = _hosting_get_allowed_platforms($user->uid);
    }
    else {
      $allowed_plats = array($platform => $platform);
    }
    $access_check = FALSE;

    foreach ($result as $row) {
      if (!is_null($platform) && array_key_exists($row->nid, $allowed_plats)) {
        $platform_profiles[$id] = $name;
      }
      elseif (array_key_exists($row->nid, $allowed_plats)) {
        $access_check = TRUE;
      }
      // Open access if no platform access has been set.
      // @todo move this into _hosting_get_allowed_platforms
      // @todo confirm this logic.
      elseif (!$unrestricted = db_query("SELECT cid
                                         FROM {hosting_platform_client_access}
                                         WHERE pid = :pid LIMIT 1",
                                         array(':pid' => $row->nid)
                                       )->fetchField()) {
        $access_check = TRUE;
      }
    }
    if (!$access_check) {
      unset($profiles[$id]);
    }
  }
  if (!is_null($platform)) {
    $profiles = $platform_profiles;
  }
  reset($profiles);
  $return['profile'] = array_keys($profiles);

  if (!isset($node->profile)) {
    $node->profile = hosting_get_default_profile($return['profile'][0]);
  }

  // Filter the available platforms based on which clients the user has access to.
  if (!is_null($platform)) {
    $node->profile = $return['profile'][0];
    $return['platform'] = array($platform);
  }
  else {
    $options = array();
    $platforms = hosting_get_profile_platforms($node->profile, isset($node->check_profile_migrations) ? $node->check_profile_migrations : FALSE);
    if (count($platforms)) {
      foreach ($platforms as $nid => $title) {
        $platform = node_load($nid);

        if ($platform->platform_status != HOSTING_PLATFORM_LOCKED || user_access('create sites on locked platforms')) {
          if (!isset($platform->clients) || count(array_intersect(array_keys($user->client_id), $platform->clients)) || $user->uid == 1) {
            $options[] = $nid;
          }
        }
      }

      $return['platform'] = $options;
    }
  }

  if (!isset($node->platform) || !in_array($node->platform, $return['platform'])) {
    $node->platform = $return['platform'][0];
  }

  $return['site_language'] = array_keys((array) hosting_get_profile_languages($node->profile, $node->platform));

  drupal_alter('hosting_site_options', $return, $node);

  return $return;
}


/**
 * Implements hook_form().
 */
function hosting_site_form($node, &$form_state) {
  $form['#node'] = $node;

  if (isset($node->nid)) {
    $form['info'] = array(
      '#prefix' => '<div class="clear-block" id="hosting-site-edit-info">',
      '#suffix' => '<br /></div>',
      '#weight' => -10,
    );
  }

  _hosting_site_field($form, $node, 'title', array(
    '#type' => 'textfield',
    '#title' => t('Domain name'),
    '#required' => TRUE,
    '#default_value' => isset($node->title) ? strtolower(trim($node->title)) : '',
    '#weight' => -10,
  ));

  $editable = ((!isset($node->client) || !isset($node->nid)) || user_access('administer sites')) && hosting_feature('client');
  $add_client_text = '';
  if (user_access('administer clients') || user_access('create client')) {
    $add_client_text = t('Click !here to add a new client.', array('!here' => l(t('here'), 'node/add/client', array('attributes' => array('target' => '_blank')))));
  }
  _hosting_site_field($form, $node, 'client', array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Client'),
    '#default_value' => _hosting_client_site_default($node),
    '#description' => t('The client to whom this site belongs.') . ' ' . $add_client_text,
    '#autocomplete_path' => 'hosting_client/autocomplete/client',
  ), 'filter_xss', $editable);

  // Install profiles.
  $profiles = hosting_get_profiles();
  foreach ($profiles as $id => $name) {
    $profile = hosting_package_instance_load(array('p.nid' => $id));
    $profiles[$id] = theme('hosting_site_profile', array('profile' => $profile, 'html' => TRUE));
  }
  natcasesort($profiles);
  reset($profiles);

  _hosting_site_field($form, $node, 'profile', array(
    '#type' => 'radios',
    '#title' => t('Install profile'),
    '#description' => t('The type of site to install.<br />
                           The profile selected here determines the list of supported platforms below.'),
    '#options' => $profiles,
    '#default_value' => isset($node->profile) ? $node->profile : hosting_get_default_profile(key($profiles)),
    '#required' => TRUE,
    '#attributes' => array('class' => array("hosting-site-form-profile-options")),
    '#ajax' => array(
      'callback' => 'hosting_site_platform_callback',
      'wrapper' => 'hosting-site-field-platform' ,
      'effect' => 'fade',
      'event' => 'change',
      'method' => 'replace',
    ),
  ), '_hosting_node_link');

  // Override the defaults if the profile has been changed.
  if (isset($form_state['values']['profile'])) {
    $selected_profile = $form_state['values']['profile'];
  }
  else {
    $selected_profile = hosting_package_instance_load(array('p.nid' => hosting_get_default_profile()))->nid;
  }

  // Load platforms for the selected profile.
  $platforms = hosting_get_profile_platforms($selected_profile);

  $q = drupal_get_query_parameters();
  if (isset($q['platform']) && is_numeric($q['platform'])) {
    $default_platform = $q['platform'];

    // Since platform is predetermined, limit the options based on the selected platform.
    $selected_profile = hosting_package_instance_load(array('platform' => $default_platform, 'package_type' => 'profile'))->nid;
    $platforms = hosting_get_profile_platforms($selected_profile);

    $form['profile']['#default_value'] = $selected_profile;
    $form['profile']['#options'] = hosting_get_profiles($default_platform);
    foreach ($form['profile']['#options'] as $id => &$name) {
      $profile = hosting_package_instance_load(array('p.nid' => $id));
      $name = theme('hosting_site_profile', array('profile' => $profile, 'html' => TRUE));
    }
    natcasesort($form['profile']['#options']);
    reset($form['profile']['#options']);

    // Set page title.
    drupal_set_title(t('Create site on platform @name', array('@name' => $platforms[$default_platform])));
  }
  else {
    $default_platform = NULL;
  }

  if (!array_key_exists($default_platform, $platforms)) {
    // Default to the first platform, if none was passed in the path.
    $default_platform = current(array_keys($platforms));
  }
  _hosting_site_field($form, $node, 'platform', array(
    '#type' => 'radios',
    '#title' => t('Platform'),
    '#required' => TRUE,
    '#description' => t('The platform you want the site to be hosted on.<br />
                          Not seeing a certain platform? Platforms shown are those that support the profile above.
                          If a different profile is selected, this list may change automatically.'),
    '#options' => $platforms,
    '#default_value' => isset($node->platform) ? $node->platform : $default_platform,
    '#ajax' => array(
      'callback' => 'hosting_site_language_callback',
      'wrapper' => 'hosting-site-field-site-language' ,
      'effect' => 'fade',
      'event' => 'change',
      'method' => 'replace',
    ),
  ), '_hosting_node_link');

  // Override the defaults if the profile has been changed.
  if (isset($form_state['values']['platform'])) {
    $selected_platform = $form_state['values']['platform'];
  }
  else {
    $selected_platform = NULL;
  }
  $languages = hosting_get_profile_languages($selected_profile, $selected_platform);
  _hosting_site_field($form, $node, 'site_language', array(
    '#type' => ((count($languages) > 10) ? 'select' : 'radios'),
    '#title' => t('Language'),
    '#description' => t('The language of site being installed.'),
    '#options' => $languages,
    '#required' => TRUE,
    '#default_value' => isset($node->site_language) ? $node->site_language : 'en',
    '#attributes' => array('class' => array("hosting-site-form-site-language-options")),
  ), '_hosting_language_name');

  _hosting_site_field($form, $node, 'db_server', array(
    '#type' => 'radios',
    '#title' => t('Database server'),
    '#required' => TRUE,
    '#description' => t('The database server the site will use to host its content.'),
    '#options' => hosting_get_servers('db'),
    '#default_value' => isset($node->db_server) ? $node->db_server : HOSTING_DEFAULT_DB_SERVER,
  ), '_hosting_node_link');

  foreach (array('verified', 'last_cron', 'site_status') as $extra_attribute) {
    $form["$extra_attribute"] = array(
      '#type' => 'value',
      '#value' => isset($node->$extra_attribute) ? $node->$extra_attribute : NULL,
    );
  }

  return $form;
}


/**
 * Ajax callback for the site profile field.
 */
function hosting_site_platform_callback($form, &$form_state) {
  return $form['platform'];
}

/**
 * Ajax callback for the site platform field.
 */
function hosting_site_language_callback($form, &$form_state) {
  return $form['site_language'];
}

/**
 * Implements hook_validate().
 */
function hosting_site_validate($node, &$form) {
  global $user;
  $valid_options = hosting_site_available_options($node);

  // Domain names are case-insensitive, set to lower case.
  $url = strtolower(trim($node->title));

  if (!_hosting_valid_fqdn($url)) {
    form_set_error('title', t("You have not specified a valid url for this site."));
  }

  $length = strlen($url);
  if ($length > HOSTING_MAX_ALIAS_LENGTH) {
    $long = $length - HOSTING_MAX_ALIAS_LENGTH;
    form_set_error("title", t('The url your provided is @long character(s) too long. Please shorten.', array('@long' => $long)));
  }

  if (isset($node->new_client) && !$node->new_client) {
    $client = hosting_get_client($node->client);
    if (!$node->client || !$client) {
      form_set_error('client', t('Please fill in a valid client'));
    }
    if (!user_access('administer clients') && !array_key_exists($client->nid, hosting_get_client_from_user($user->uid))) {
      form_set_error('client', t('Access denied to client @client', array('@client' => $client->title)));
    }
    $node->client = $client->nid;
  }

  // TODO: maybe we should allow creation of sites that conflict with HOSTING_SITE_DISABLED (which would then need to be renamed before being re-enabled)
  if (!hosting_domain_allowed($url, (array) $node)) {
    form_set_error('title', t("The domain name you have specified is already in use."));
  }

  // If the quota module is loaded and this is a new node, check
  // the site quota.
  if (empty($node->nid) && function_exists('hosting_site_quota_exceeded')) {
    $quota_error = hosting_site_quota_exceeded($node);
    if ($quota_error) {
      form_set_error('title', $quota_error);
    }
  }

  if (!in_array($node->profile, $valid_options['profile']) && !isset($node->nid)) {
    form_set_error('profile', t('Please choose a valid profile'));
  }

  if (!in_array($node->platform, $valid_options['platform']) && !isset($node->nid)) {
    form_set_error('platform', t('Please choose a valid platform'));
  }

  // Check that we are selecting a valid language for this profile,
  // but only when a new site is created.
  if (!in_array($node->site_language, $valid_options['site_language']) && empty($node->nid)) {
    form_set_error('site_language', t('Please fill in a valid language'));
  }

}

/**
 * Implements hook_form_alter().
 *
 * Hide the delete button on site nodes
 */
function hosting_site_form_alter(&$form, &$form_state, $form_id) {
  // Remove delete button from site edit form, unless the site's already been
  // deleted via the Delete task.
  if ($form_id == 'site_node_form') {
    $node = $form['#node'];
    if (isset($node->site_status) && $node->site_status !== HOSTING_SITE_DELETED) {
      $form['actions']['delete']['#type'] = 'hidden';
    }
  }
  if (array_key_exists('views_bulk_operations', $form)) {
    // Add our callback, so we can operate on the fully built form.
    $form['#after_build'][] = '_hosting_site_collapse_views_fieldset';
  }

  // On Delete task forms, if variable is set, set the --force option.
  if ($form_id == 'hosting_task_confirm_form' && $form['task']['#value'] == 'delete' && variable_get('hosting_delete_force', FALSE)) {
    $form['parameters']['force'] = array(
      '#type' => 'value',
      '#value' => 1,
    );
  }
}
