<?php
/**
 * @file
 * Provide a default view listing packages.
 */

/**
 * Implements hook_views_default_views().
 */
function hosting_package_views_default_views() {
  $views = array();

  // Exported view: hosting_package_list
  $view = new view();
  $view->name = 'hosting_package_list';
  $view->description = 'A list of packages present on a site or platform.';
  $view->tag = 'hosting_package';
  $view->base_table = 'hosting_package_instance';
  $view->human_name = 'Hosting Package List';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = '[status]';
  $handler->display->display_options['style_options']['columns'] = array(
    'status' => 'status',
    'status_1' => 'status_1',
    'title' => 'title',
    'version' => 'version',
    'package_type' => 'package_type',
  );
  $handler->display->display_options['style_options']['default'] = 'status_1';
  $handler->display->display_options['style_options']['info'] = array(
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'status_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'version' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'package_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  /* Relationship: Hosting Package Instance: Package ID */
  $handler->display->display_options['relationships']['package_id']['id'] = 'package_id';
  $handler->display->display_options['relationships']['package_id']['table'] = 'hosting_package_instance';
  $handler->display->display_options['relationships']['package_id']['field'] = 'package_id';
  /* Relationship: Hosting Package Instance: Reference ID */
  $handler->display->display_options['relationships']['rid']['id'] = 'rid';
  $handler->display->display_options['relationships']['rid']['table'] = 'hosting_package_instance';
  $handler->display->display_options['relationships']['rid']['field'] = 'rid';
  /* Field: Class */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'hosting_package_instance';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['ui_name'] = 'Class';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['status_mode'] = 'class';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'package_id';
  $handler->display->display_options['fields']['title']['label'] = 'Package';
  $handler->display->display_options['fields']['title']['element_class'] = 'hosting-status';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = '[hosting-status]';
  /* Field: Hosting Package Instance: Version */
  $handler->display->display_options['fields']['version']['id'] = 'version';
  $handler->display->display_options['fields']['version']['table'] = 'hosting_package_instance';
  $handler->display->display_options['fields']['version']['field'] = 'version';
  $handler->display->display_options['fields']['version']['label'] = 'Release';
  /* Field: Hosting Package: Type */
  $handler->display->display_options['fields']['package_type']['id'] = 'package_type';
  $handler->display->display_options['fields']['package_type']['table'] = 'hosting_package';
  $handler->display->display_options['fields']['package_type']['field'] = 'package_type';
  $handler->display->display_options['fields']['package_type']['relationship'] = 'package_id';
  $handler->display->display_options['fields']['package_type']['label'] = 'Package type';
  /* Sort criterion: Hosting Package Instance: Status */
  $handler->display->display_options['sorts']['status']['id'] = 'status';
  $handler->display->display_options['sorts']['status']['table'] = 'hosting_package_instance';
  $handler->display->display_options['sorts']['status']['field'] = 'status';
  $handler->display->display_options['sorts']['status']['order'] = 'DESC';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'package_id';
  /* Contextual filter: Hosting Package Instance: Reference ID */
  $handler->display->display_options['arguments']['rid']['id'] = 'rid';
  $handler->display->display_options['arguments']['rid']['table'] = 'hosting_package_instance';
  $handler->display->display_options['arguments']['rid']['field'] = 'rid';
  $handler->display->display_options['arguments']['rid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['rid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['rid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['rid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['rid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['rid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['rid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['rid']['validate_options']['types'] = array(
    'platform' => 'platform',
    'site' => 'site',
  );
  /* Filter criterion: Hosting Package: Type */
  $handler->display->display_options['filters']['package_type']['id'] = 'package_type';
  $handler->display->display_options['filters']['package_type']['table'] = 'hosting_package';
  $handler->display->display_options['filters']['package_type']['field'] = 'package_type';
  $handler->display->display_options['filters']['package_type']['relationship'] = 'package_id';
  $handler->display->display_options['filters']['package_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['package_type']['expose']['operator_id'] = 'package_type_op';
  $handler->display->display_options['filters']['package_type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['package_type']['expose']['operator'] = 'package_type_op';
  $handler->display->display_options['filters']['package_type']['expose']['identifier'] = 'package_type';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_packages');
  $handler->display->display_options['display_description'] = 'Display a list of packages for a hosted site or platform. Note that we alter this view and the exposed form.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = '[status]';
  $handler->display->display_options['style_options']['columns'] = array(
    'status' => 'status',
    'title' => 'title',
    'version' => 'version',
    'package_type' => 'package_type',
    'site_count' => 'site_count',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'version' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'package_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'site_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Hosting Package Instance: Package ID */
  $handler->display->display_options['relationships']['package_id']['id'] = 'package_id';
  $handler->display->display_options['relationships']['package_id']['table'] = 'hosting_package_instance';
  $handler->display->display_options['relationships']['package_id']['field'] = 'package_id';
  /* Relationship: Hosting Package Instance: Reference ID */
  $handler->display->display_options['relationships']['rid']['id'] = 'rid';
  $handler->display->display_options['relationships']['rid']['table'] = 'hosting_package_instance';
  $handler->display->display_options['relationships']['rid']['field'] = 'rid';
  $handler->display->display_options['relationships']['rid']['label'] = 'site/platform';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Class */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'hosting_package_instance';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['ui_name'] = 'Class';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['status_mode'] = 'class';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'package_id';
  $handler->display->display_options['fields']['title']['label'] = 'Package';
  $handler->display->display_options['fields']['title']['element_class'] = 'hosting-status';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = '[hosting-status]';
  /* Field: Hosting Package Instance: Version */
  $handler->display->display_options['fields']['version']['id'] = 'version';
  $handler->display->display_options['fields']['version']['table'] = 'hosting_package_instance';
  $handler->display->display_options['fields']['version']['field'] = 'version';
  $handler->display->display_options['fields']['version']['label'] = 'Release';
  /* Field: Hosting Package: Type */
  $handler->display->display_options['fields']['package_type']['id'] = 'package_type';
  $handler->display->display_options['fields']['package_type']['table'] = 'hosting_package';
  $handler->display->display_options['fields']['package_type']['field'] = 'package_type';
  $handler->display->display_options['fields']['package_type']['relationship'] = 'package_id';
  $handler->display->display_options['fields']['package_type']['label'] = 'Package type';
  /* Field: Hosting Package Instance: Site count */
  $handler->display->display_options['fields']['site_count']['id'] = 'site_count';
  $handler->display->display_options['fields']['site_count']['table'] = 'hosting_package_instance';
  $handler->display->display_options['fields']['site_count']['field'] = 'site_count';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'rid';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Hosting Package Instance: Reference ID */
  $handler->display->display_options['arguments']['rid']['id'] = 'rid';
  $handler->display->display_options['arguments']['rid']['table'] = 'hosting_package_instance';
  $handler->display->display_options['arguments']['rid']['field'] = 'rid';
  $handler->display->display_options['arguments']['rid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['rid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['rid']['title'] = '<span class="label">[type]</span> %1';
  $handler->display->display_options['arguments']['rid']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['rid']['breadcrumb'] = 'Packages';
  $handler->display->display_options['arguments']['rid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['rid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['rid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['rid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['rid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['rid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['rid']['validate_options']['types'] = array(
    'platform' => 'platform',
    'site' => 'site',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'package_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Package name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'package';
  /* Filter criterion: Hosting Package: Type */
  $handler->display->display_options['filters']['package_type']['id'] = 'package_type';
  $handler->display->display_options['filters']['package_type']['table'] = 'hosting_package';
  $handler->display->display_options['filters']['package_type']['field'] = 'package_type';
  $handler->display->display_options['filters']['package_type']['relationship'] = 'package_id';
  $handler->display->display_options['filters']['package_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['package_type']['expose']['operator_id'] = 'package_type_op';
  $handler->display->display_options['filters']['package_type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['package_type']['expose']['operator'] = 'package_type_op';
  $handler->display->display_options['filters']['package_type']['expose']['identifier'] = 'package_type';
  /* Filter criterion: Hosting Package Instance: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'hosting_package_instance';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['path'] = 'node/%/packages';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Packages';
  $handler->display->display_options['menu']['weight'] = '1';

  /* Display: Block: Sites */
  $handler = $view->new_display('block', 'Block: Sites', 'block_sites');
  $handler->display->display_options['display_description'] = 'Display a list of sites on which a package is enabled or available.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = '[status]';
  $handler->display->display_options['style_options']['columns'] = array(
    'status' => 'status',
    'title' => 'title',
    'version' => 'version',
    'title_1' => 'title_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'version' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
    ),
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'These sites have the <em>%1</em> package enabled.';
  $handler->display->display_options['header']['area']['format'] = '1';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No sites have the <em>%1</em> package enabled.';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['empty']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Hosting Package Instance: Package ID */
  $handler->display->display_options['relationships']['package_id']['id'] = 'package_id';
  $handler->display->display_options['relationships']['package_id']['table'] = 'hosting_package_instance';
  $handler->display->display_options['relationships']['package_id']['field'] = 'package_id';
  /* Relationship: Hosting Package Instance: Reference ID */
  $handler->display->display_options['relationships']['rid']['id'] = 'rid';
  $handler->display->display_options['relationships']['rid']['table'] = 'hosting_package_instance';
  $handler->display->display_options['relationships']['rid']['field'] = 'rid';
  $handler->display->display_options['relationships']['rid']['required'] = TRUE;
  /* Relationship: Hosting Site: Platform */
  $handler->display->display_options['relationships']['platform']['id'] = 'platform';
  $handler->display->display_options['relationships']['platform']['table'] = 'hosting_site';
  $handler->display->display_options['relationships']['platform']['field'] = 'platform';
  $handler->display->display_options['relationships']['platform']['relationship'] = 'rid';
  $handler->display->display_options['relationships']['platform']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Class */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'hosting_package_instance';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['ui_name'] = 'Class';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['status_mode'] = 'class';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'rid';
  $handler->display->display_options['fields']['title']['label'] = 'Site';
  $handler->display->display_options['fields']['title']['element_class'] = 'hosting-status';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = '[hosting-status]';
  /* Field: Hosting Package Instance: Version */
  $handler->display->display_options['fields']['version']['id'] = 'version';
  $handler->display->display_options['fields']['version']['table'] = 'hosting_package_instance';
  $handler->display->display_options['fields']['version']['field'] = 'version';
  $handler->display->display_options['fields']['version']['label'] = 'Release';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'platform';
  $handler->display->display_options['fields']['title_1']['label'] = 'Platform';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'package_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'package' => 'package',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Hosting Package Instance: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'hosting_package_instance';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  /* Filter criterion: Hosting Site: Status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'hosting_site';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'rid';
  $handler->display->display_options['filters']['status_1']['value'] = array(
    1 => '1',
    -1 => '-1',
  );
  $handler->display->display_options['block_description'] = 'Hosting package: Sites';

  $views[$view->name] = $view;

  return $views;
}
