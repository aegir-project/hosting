<?php

/**
 * @file
 * Site nodeapi implementations.
 */

/**
 * Implements hook_node_info().
 */
function hosting_site_node_info() {
  $types["site"] = array(
    "type" => 'site',
    "name" => 'Site',
    'base' => 'hosting_site',
    "has_title" => TRUE,
    "title_label" => 'Domain name',
    "description" => hosting_node_help("site"),
    "has_body" => 0,
    "body_label" => '',
    "min_word_count" => 0,
  );
  return $types;
}

/**
 * Implements hook_view().
 */
function hosting_site_view($node, $view_mode, $langcode = NULL) {
  hosting_set_breadcrumb($node);
  $node->content['info']['#prefix'] = '<div id="hosting-site-info" class="hosting-info-list">';
  if ($node->site_status == HOSTING_SITE_ENABLED) {
    $node->content['info']['link'] = array(
      '#markup' => _hosting_site_goto_link($node),
      '#weight' => -10,
    );
  }

  if (is_numeric($node->client)) {
    $node->content['info']['client'] = array(
      '#type' => 'item',
      '#title' => t('Client'),
      '#markup' => _hosting_node_link($node->client),
      '#weight' => 5,
    );
  }

  $node->content['info']['verified'] = array(
    '#type' => 'item',
    '#title' => t('Verified'),
    '#markup' => hosting_format_interval($node->verified),
  );

  $node->content['info']['platform'] = array(
    '#type' => 'item',
    '#title' => t('Platform'),
    '#markup' => _hosting_node_link($node->platform),
  );

  if ($node->profile) {
    $node->content['info']['profile'] = array(
      '#type' => 'item',
      '#title' => t('Install profile'),
      '#markup' => _hosting_node_link($node->profile),
    );
  }
  if ($node->site_language) {
    $node->content['info']['site_language'] = array(
      '#type' => 'item',
      '#title' => t('Language'),
      '#markup' => _hosting_language_name($node->site_language),
    );
  }

  if ($node->nid) {
    $node->content['info']['status'] = array(
      '#type' => 'item',
      '#title' => t('Status'),
      '#markup' => _hosting_site_status($node),
    );
  }

  if ($node->db_server) {
    $node->content['info']['db_server'] = array(
      '#type' => 'item',
      '#title' => t('Database server'),
      '#markup' => _hosting_node_link($node->db_server),
    );
  }

  if ($node->db_name) {
    $node->content['info']['db_name'] = array(
      '#type' => 'item',
      '#title' => t('Database name'),
      '#markup' => check_plain($node->db_name),
    );
  }

  $node->content['info']['#suffix'] = '</div>';

  if ($node->nid) {
    $node->content['tasks_view'] = array(
      '#type' => 'item',
      '#markup' => hosting_task_table($node),
      '#prefix' => '<div id="hosting-task-list">',
      '#suffix' => '</div>',
      '#weight' => 10,
    );
    $settings['hostingTaskRefresh'] = array(
      'nid' => $node->nid,
      'changed' => $node->changed,
    );
    drupal_add_js($settings, array('type' => 'setting', 'scope' => JS_DEFAULT));

    drupal_add_js(drupal_get_path('module', 'hosting_task') . '/hosting_task.js');
  }
  return $node;
}

/**
 * Implements hook_field_extra_fields().
 */
function hosting_site_field_extra_fields() {
  $return['node']['site'] = array(
    'display' => array(
      'info' => array(
        'label' => t('Aegir Site Information'),
        'description' => t('Detailed information about this site.'),
        'weight' => 0,
      ),
      'tasks_view' => array(
        'label' => t('Aegir Site Tasks'),
        'description' => t('List of available tasks.'),
        'weight' => 1,
      ),
    ),
  );

  return $return;
}

/**
 * Implements hook_entity_property_info().
 */
function hosting_site_entity_property_info() {
  $info['node']['bundles']['site']['properties'] = array(
    'client' => array(
      'label' => t('Client'),
      'description' => t('The client that owns the site.'),
      'type' => 'node',
      'bundle' => 'client',
    ),
    'db_server' => array(
      'label' => t('Database server'),
      'description' => t('The database server for the site.'),
      'type' => 'node',
      'bundle' => 'server',
    ),
    'db_name' => array(
      'label' => t('Database name'),
      'description' => t('The name of the database on the database server for the site.'),
      'type' => 'text',
    ),
    'platform' => array(
      'label' => t('Platform'),
      'description' => t('The platform the site is on.'),
      'type' => 'node',
      'bundle' => 'platform',
    ),
    'profile' => array(
      'label' => t('Profile'),
      'description' => t('The install profile used to install the site.'),
      'type' => 'node',
      'bundle' => 'package',
    ),
    'site_language' => array(
      'label' => t('Site language'),
      'description' => t('The language of the site.'),
      'type' => 'text',
    ),
    'last_cron' => array(
      'label' => t('Last cron run time'),
      'description' => t('The date of the last cron run time for the site.'),
      'type' => 'date',
    ),
    'cron_key' => array(
      'label' => t('Cron key'),
      'description' => t('The cron key for the site.'),
      'type' => 'text',
    ),
    'site_status' => array(
      'label' => t('Site status'),
      'description' => t('The status of the site, e.g. enabled, deleted etc.'),
      'type' => 'integer',
      'options list' => 'hosting_site_status_codes_labels',
    ),
    'verified' => array(
      'label' => t('Last verification time'),
      'description' => t('The date of the time the site was verified.'),
      'type' => 'date',
    ),
  );

  return $info;
}

/**
 * Implements hook_nodeapi_delete_revision().
 */
function hosting_nodeapi_site_delete_revision(&$node) {
  db_delete('hosting_site')
    ->condition('vid', $node->vid)
    ->execute();
}

/**
 * Implements hook_delete().
 */
function hosting_site_delete($node) {
  db_delete('hosting_site')
    ->condition('nid', $node->nid)
    ->execute();
  db_delete('hosting_package_instance')
    ->condition('rid', $node->nid)
    ->execute();
  hosting_context_delete($node->nid);
  hosting_task_delete_related_tasks($node->nid);
}

/**
 * Implements hook_nodeapi().
 */
function hosting_site_nodeapi_site_presave(&$node) {
  // Domain names are case-insensitive.
  $node->title = strtolower(trim($node->title));
}

/**
 * Implements hook_insert().
 */
function hosting_site_insert(&$node) {
  $client = hosting_get_client($node->client);
  $node->client = $client->nid;
  $node->site_language = isset($node->site_language) ? $node->site_language : 'en';
  // If the cron_key is set use it, otherwise generate a new one.
  $node->cron_key = isset($node->cron_key) ? $node->cron_key : '';
  // Ensure that the last_cron value is set.
  $node->last_cron = isset($node->last_cron) ? $node->last_cron : 0;
  // Provide a dummy profile, e.g. for hosting-import.
  $node->profile = isset($node->profile) ? $node->profile : 0;

  // If platform NID is not defined, but platform data is available,
  // create the platform.
  if (empty($node->platform)
    && !empty($node->platform_node)
    && !empty($node->platform_node->publish_path)
  ) {

    // If a platform exists for the given path, use that.
    $existing_platform_nid = db_select('hosting_platform', 'p')
      ->condition('publish_path', $node->platform_node->publish_path)
      ->condition('status', HOSTING_PLATFORM_ENABLED)
      ->fields('p', array('nid'))
      ->execute()
      ->fetchField();

    // Use the existing platform NID.
    if ($existing_platform_nid) {
      $node->platform = $existing_platform_nid;
    }
    // Or prepare a new one.
    else {

      // If platform_status hasn't been explicitly set,
      // assume platform status matches site status:
      // If developer creates a site node that's disabled,
      // the platform should be too.
      if (!isset($node->platform_node->platform_status) && isset($node->site_status)) {
        $node->platform_node->platform_status = $node->site_status;
      }

      // If web_server hasn't been explicity set, use hostmaster's web server.
      if (!isset($node->platform_node->web_server)) {
        $hostmaster = hosting_context_load('hostmaster');
        $hostmaster_platform = node_load($hostmaster->platform);
        $node->platform_node->web_server = $hostmaster_platform->web_server;
      }

      // If platform title has not been set, generate one from the site title.
      if (empty($node->platform_node->title)) {
        $node->platform_node->title = 'platform_' . preg_replace("/[!\W]/", "", $node->title);
      }

      // If platform UID has not been set, use site UID.
      if (empty($node->platform_node->uid)) {
        $node->platform_node->uid = $node->uid;
      }

      $node->platform_node->type = 'platform';
      if ($node->platform_node = node_submit($node->platform_node)) {
        node_save($node->platform_node);
      }
      $node->platform = $node->platform_node->nid;
    }

    // If db_server hasn't been explicity set, use hostmaster's web server.
    if (!isset($node->db_server)) {
      $hostmaster = hosting_context_load('hostmaster');
      $node->db_server = $hostmaster->db_server;
    }
  }

  // If there is no platform NID and no publish path, throw an exception.
  if (empty($node->platform) && empty($node->platform_node->publish_path)) {
    throw new Exception('Site nodes require either platform or platform_node->publish_path property');
  }

  $id = db_insert('hosting_site')
    ->fields(array(
      'vid' => $node->vid,
      'nid' => $node->nid,
      'client' => $node->client,
      'db_server' => $node->db_server,
      'db_name' => isset($node->db_name) ? $node->db_name : '',
      'platform' => $node->platform,
      'profile' => $node->profile,
      'language' => $node->site_language,
      'last_cron' => $node->last_cron,
      'cron_key' => $node->cron_key,
      'status' => isset($node->site_status) ? $node->site_status : HOSTING_SITE_QUEUED,
      'verified' => isset($node->verified) ? $node->verified : 0,
    ))
    ->execute();

}

/**
 * Implements hook_node_insert().
 */
function hosting_site_node_insert($node) {
  if ($node->type == "site") {
    if ((empty($node->old_vid))) {
      hosting_context_register($node->nid, isset($node->hosting_name) ? $node->hosting_name : $node->title);
      if (isset($node->import)) {
        hosting_add_task($node->nid, 'import');
      }
      else {
        hosting_add_task($node->nid, 'install');
      }
    }
  }
}

/**
 * Implements hook_update().
 */
function hosting_site_update(&$node) {
  // If this is a new node or we're adding a new revision.
  if (!empty($node->revision)) {
    hosting_site_insert($node);
  }
  else {
    $client = hosting_get_client($node->client);
    $node->client = $client->nid;
    if ($node->site_status == HOSTING_SITE_DELETED) {
      $node->no_verify = TRUE;
    }

    db_update('hosting_site')
      ->fields(array(
        'client' => $node->client,
        'db_server' => $node->db_server,
        'db_name' => $node->db_name,
        'platform' => $node->platform,
        'last_cron' => $node->last_cron,
        'cron_key' => $node->cron_key,
        'status' => $node->site_status,
        'profile' => $node->profile,
        'language' => $node->site_language,
        'verified' => $node->verified,
      ))
      ->condition('vid', $node->vid)
      ->execute();
    
    // If platform_node is passed in the site node, save it.
    if (isset($node->platform_node->nid)) {
      node_save($node->platform_node);
    }
  }
}

/**
 * Implements hook_node_update().
 */
function hosting_site_node_update($node) {
  if ($node->type == "site") {
    if ((isset($node->no_verify) && $node->no_verify) == FALSE) {
      hosting_add_task($node->nid, 'verify');
    }
  }
}

/**
 * Implements hook_load().
 */
function hosting_site_load($nodes) {
  foreach ($nodes as $nid => &$node) {
    $additions = db_query(
      'SELECT  client, db_server, db_name, platform, profile, web_server, publish_path,
        language AS site_language, last_cron, cron_key, s.status AS site_status,
        p.status AS platform_status, s.verified, p.verified as platform_verified
      FROM {hosting_site} s
        LEFT JOIN {hosting_platform} p ON s.platform = p.nid
      WHERE s.vid = :vid',
      array(':vid' => $node->vid)
    )->fetch();
    foreach ($additions as $property => &$value) {
      $node->$property = is_numeric($value) ? (int) $value : $value;
    }
  }

  // Create a "servers" array based on our two base servers.
  $node->servers['web'] = node_load($node->web_server);
  $node->servers['db'] = node_load($node->db_server);
}
