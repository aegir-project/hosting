<?php
/**
 * @file
 */

/**
 * Implementation of hook_views_default_views().
 */
function hosting_package_views_default_views() {
  $views = array();

  // Exported view: hosting_package_list
  $view = new view;
  $view->name = 'hosting_package_list';
  $view->description = 'Display a list of packages for a hosted site';
  $view->tag = '';
  $view->base_table = 'hosting_package_instance';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view package';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
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
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Hosting Package Instance: Package ID */
  $handler->display->display_options['relationships']['package_id']['id'] = 'package_id';
  $handler->display->display_options['relationships']['package_id']['table'] = 'hosting_package_instance';
  $handler->display->display_options['relationships']['package_id']['field'] = 'package_id';
  $handler->display->display_options['relationships']['package_id']['required'] = 0;
  /* Field: Class */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'hosting_package_instance';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['ui_name'] = 'Class';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['status']['status_mode'] = 'class';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'package_id';
  $handler->display->display_options['fields']['title']['label'] = 'Package';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_class'] = 'hosting-status';
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = '[hosting-status]';
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Hosting Package Instance: Version */
  $handler->display->display_options['fields']['version']['id'] = 'version';
  $handler->display->display_options['fields']['version']['table'] = 'hosting_package_instance';
  $handler->display->display_options['fields']['version']['field'] = 'version';
  $handler->display->display_options['fields']['version']['label'] = 'Release';
  $handler->display->display_options['fields']['version']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['version']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['version']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['version']['alter']['external'] = 0;
  $handler->display->display_options['fields']['version']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['version']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['version']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['version']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['version']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['version']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['version']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['version']['alter']['html'] = 0;
  $handler->display->display_options['fields']['version']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['version']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['version']['hide_empty'] = 0;
  $handler->display->display_options['fields']['version']['empty_zero'] = 0;
  $handler->display->display_options['fields']['version']['hide_alter_empty'] = 1;
  /* Field: Hosting Package: Type */
  $handler->display->display_options['fields']['package_type']['id'] = 'package_type';
  $handler->display->display_options['fields']['package_type']['table'] = 'hosting_package';
  $handler->display->display_options['fields']['package_type']['field'] = 'package_type';
  $handler->display->display_options['fields']['package_type']['relationship'] = 'package_id';
  $handler->display->display_options['fields']['package_type']['label'] = 'Package type';
  $handler->display->display_options['fields']['package_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['package_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['package_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['package_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['package_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['package_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['package_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['package_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['package_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['package_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['package_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['package_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['package_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['package_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['package_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['package_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['package_type']['hide_alter_empty'] = 1;
  /* Sort criterion: Hosting Package Instance: Status */
  $handler->display->display_options['sorts']['status']['id'] = 'status';
  $handler->display->display_options['sorts']['status']['table'] = 'hosting_package_instance';
  $handler->display->display_options['sorts']['status']['field'] = 'status';
  $handler->display->display_options['sorts']['status']['order'] = 'DESC';
  /* Sort criterion: Node: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'package_id';
  /* Argument: Hosting Package Instance: Reference ID */
  $handler->display->display_options['arguments']['rid']['id'] = 'rid';
  $handler->display->display_options['arguments']['rid']['table'] = 'hosting_package_instance';
  $handler->display->display_options['arguments']['rid']['field'] = 'rid';
  $handler->display->display_options['arguments']['rid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['rid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['rid']['title'] = 'Packages on %1';
  $handler->display->display_options['arguments']['rid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['rid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['rid']['validate_type'] = 'node';
  $handler->display->display_options['arguments']['rid']['validate_options']['types'] = array(
    'platform' => 'platform',
    'site' => 'site',
  );
  $handler->display->display_options['arguments']['rid']['validate_options']['access'] = 0;
  $handler->display->display_options['arguments']['rid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['rid']['not'] = 0;
  /* Filter: Hosting Package: Type */
  $handler->display->display_options['filters']['package_type']['id'] = 'package_type';
  $handler->display->display_options['filters']['package_type']['table'] = 'hosting_package';
  $handler->display->display_options['filters']['package_type']['field'] = 'package_type';
  $handler->display->display_options['filters']['package_type']['relationship'] = 'package_id';
  $handler->display->display_options['filters']['package_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['package_type']['expose']['operator'] = 'package_type_op';
  $handler->display->display_options['filters']['package_type']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['package_type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['package_type']['expose']['identifier'] = 'package_type';
  $handler->display->display_options['filters']['package_type']['expose']['reduce'] = 0;
  /* Filter: Hosting Package Instance: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'hosting_package_instance';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['reduce'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_packages');
  $handler->display->display_options['path'] = 'node/%/packages';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Packages';
  $handler->display->display_options['menu']['weight'] = '1';

  /* Display: Block: Sites */
  $handler = $view->new_display('block', 'Block: Sites', 'block_1');
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
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Hosting Package Instance: Package ID */
  $handler->display->display_options['relationships']['package_id']['id'] = 'package_id';
  $handler->display->display_options['relationships']['package_id']['table'] = 'hosting_package_instance';
  $handler->display->display_options['relationships']['package_id']['field'] = 'package_id';
  $handler->display->display_options['relationships']['package_id']['required'] = 0;
  /* Relationship: Hosting Package Instance: Reference ID */
  $handler->display->display_options['relationships']['rid']['id'] = 'rid';
  $handler->display->display_options['relationships']['rid']['table'] = 'hosting_package_instance';
  $handler->display->display_options['relationships']['rid']['field'] = 'rid';
  $handler->display->display_options['relationships']['rid']['required'] = 1;
  /* Relationship: Hosting Site: Platform */
  $handler->display->display_options['relationships']['platform']['id'] = 'platform';
  $handler->display->display_options['relationships']['platform']['table'] = 'hosting_site';
  $handler->display->display_options['relationships']['platform']['field'] = 'platform';
  $handler->display->display_options['relationships']['platform']['relationship'] = 'rid';
  $handler->display->display_options['relationships']['platform']['required'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Class */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'hosting_package_instance';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['ui_name'] = 'Class';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['status']['status_mode'] = 'class';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'rid';
  $handler->display->display_options['fields']['title']['label'] = 'Site';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_class'] = 'hosting-status';
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = '[hosting-status]';
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Hosting Package Instance: Version */
  $handler->display->display_options['fields']['version']['id'] = 'version';
  $handler->display->display_options['fields']['version']['table'] = 'hosting_package_instance';
  $handler->display->display_options['fields']['version']['field'] = 'version';
  $handler->display->display_options['fields']['version']['label'] = 'Release';
  $handler->display->display_options['fields']['version']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['version']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['version']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['version']['alter']['external'] = 0;
  $handler->display->display_options['fields']['version']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['version']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['version']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['version']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['version']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['version']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['version']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['version']['alter']['html'] = 0;
  $handler->display->display_options['fields']['version']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['version']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['version']['hide_empty'] = 0;
  $handler->display->display_options['fields']['version']['empty_zero'] = 0;
  $handler->display->display_options['fields']['version']['hide_alter_empty'] = 1;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'platform';
  $handler->display->display_options['fields']['title_1']['label'] = 'Platform';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Node: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'package_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['validate_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'package' => 'package',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = 0;
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter: Hosting Package Instance: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'hosting_package_instance';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['reduce'] = 0;

  $views[$view->name] = $view;

  return $views;
}

