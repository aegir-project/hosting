<?php
/**
 * @file
 *   Hosting package views integration.
 */

/**
 * Implementation of hook_views_handlers().
 */
function hosting_package_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'hosting_package') . '/views',
    ),
    'handlers' => array(
      // field handlers
      'views_handler_field_hosting_package_status' => array(
        'parent' => 'views_handler_field_hosting_site_status',
      ),
      'views_handler_field_hosting_package_site_count' => array(
        'parent' => 'views_handler_field',
      ),
      // filter handlers
      'views_handler_filter_hosting_package_status' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      // sort handlers
      'views_handler_sort_hosting_package_site_count' => array(
        'parent' => 'views_handler_sort',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data().
 */
function hosting_package_views_data() {
  // Hosting package.
  $data['hosting_package']['table'] = array(
    'group' => 'Hosting Package',
    'title' => 'Package',
    'join' => array(
      'node' => array(
        'left_field' => 'vid',
         'field' => 'vid',
      ),
    ),
  );

  $data['hosting_package']['package_type'] = array(
    'title' => t('Type'),
    'help' => t('The package type.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_in_operator',
      'options callback' => '_hosting_package_types',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );


  // Hosting package instance.
  $data['hosting_package_instance']['table']['group'] = t('Hosting Package Instance');

  $data['hosting_package_instance']['table']['base'] = array(
    'field' => 'filename',
    'title' => t('Hosting package instances'),
    'help' => t('Hosting package instances'),
  );

  $data['hosting_package_instance']['iid'] = array(
    'title' => t('Instance ID'),
    'help' => t('The package instance ID.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['hosting_package_instance']['rid'] = array(
    'title' => t('Reference ID'),
    'help' => t('The package instance reference ID.'),
    'field' => array(
      'handler' => 'views_handler_field_node',
      'click sortable' => TRUE,
    ),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'node',
      'base field' => 'nid',
      'label' => t('site'),
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_node_nid',
    ),
  );

  $data['hosting_package_instance']['site_count'] = array(
    'title' => t('Site count'),
    'help' => t('A count of sites using a package.'),
    'field' => array(
      'field' => 'platform',
      'handler' => 'views_handler_field_hosting_package_site_count',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_hosting_package_site_count',
    ),
  );

  $data['hosting_package_instance']['package_id'] = array(
    'title' => t('Package ID'),
    'help' => t('The package ID.'),
    'field' => array(
      'handler' => 'views_handler_field_node',
      'click sortable' => TRUE,
    ),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'node',
      'base field' => 'nid',
      'label' => t('package'),
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_node_nid',
    ),
  );

  $data['hosting_package_instance']['filename'] = array(
    'title' => t('File'),
    'help' => t('The package instance file.'),
    'field' => array(
      'handler' => 'views_handler_field_file',
      'click sortable' => TRUE,
     ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['hosting_package_instance']['schema_version'] = array(
    'title' => t('Schema version'),
    'help' => t('The package instance schema version.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['hosting_package_instance']['version'] = array(
    'title' => t('Version'),
    'help' => t('The package instance version.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['hosting_package_instance']['version_code'] = array(
    'title' => t('Version code'),
    'help' => t('The package instance version code.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['hosting_package_instance']['status'] = array(
    'title' => t('Status'),
    'help' => t('The status of the package instance.'),
    'field' => array(
      'handler' => 'views_handler_field_hosting_package_status',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_hosting_package_status',
      'label' => t('Status'),
      'type' => 'on-off',
      // use boolean_field = 1 instead of boolean_field <> 0 in WHERE statment
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}


/**
 * Implementation of hook_views_plugins
 */
function hosting_package_views_plugins() {
  $plugins = array(
    'access' => array(
      'parent' => array(
        'no ui' => TRUE,
        'handler' => 'views_plugin_access',
        'parent' => '',
      ),
      'package' => array(
        'title' => t('Hosting package'),
        'help' => t('Manage package access.'),
        'handler' => 'views_plugin_access_hosting_package',
        'path' => drupal_get_path('module', 'hosting_package') . '/views',
      ),
    ),
  );

  return $plugins;
}

/**
 * Views access callback.
 *
 * @param $type
 *   The display plugin.
 * @param $display
 *   The display ID (machine_name).
 * @param $account
 *   The current user.
 */
function hosting_package_views_access($type, $display, $account = NULL) {
  switch ($type) {
    case 'page':
      $path = explode('/', drupal_get_normal_path($_GET['q']));
      $nid = $path['1'];
      if (is_numeric($nid)) {
        $node = node_load($nid);
        if (!is_null($account) && (!user_access('view package', $account) || !node_access('view', $node, $account))) {
          return FALSE;
        }
        switch ($display) {
          case 'page_packages_site':
            return $node->type == 'site' && $node->site_status != -2;
            break;
          case 'page_packages_platform':
            return $node->type == 'platform' && $node->platform_status != -2;
            break;
        }
      }
      break;
    case 'block':
      if ($node = menu_get_object()) {
        return $node->type == 'package' && $node->package_type != 'profile';
      }
      break;
    default:
      return FALSE;
  }

  return FALSE;
}
