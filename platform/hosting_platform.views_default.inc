<?php
/**
 * @file
 */

/**
 * Implementation of hook_views_default_views().
 */
function hosting_platform_views_default_views() {
  $views = array();

  // Exported view: hosting_platform_list
  $view = new view;
  $view->name = 'hosting_platform_list';
  $view->description = 'Display a list of platforms in aegir';
  $view->tag = 'hosting_platform';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Platforms';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view platform';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'bulk';
  $handler->display->display_options['style_options']['row_class'] = '[status]';
  $handler->display->display_options['style_options']['columns'] = array(
    'status' => 'status',
    'title' => 'title',
    'release' => 'release',
    'title_1' => 'title_1',
    'verified' => 'verified',
    'sites' => 'sites',
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
    'release' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'verified' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'sites' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['style_options']['operations'] = array(
    'node_assign_owner_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'views_bulk_operations_delete_node_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'node_mass_update-a27b9efabcd054685a549378b174ad11' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'system_message_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'views_bulk_operations_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'views_bulk_operations_script_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'node_make_sticky_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'node_make_unsticky_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'node_mass_update-c4d3b28efb86fd703619a50b74d43794' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'hosting_platform_op_delete' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'label' => 'Delete',
    ),
    'hosting_platform_op_lock' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'label' => 'Lock',
    ),
    'hosting_platform_op_unlock' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'label' => 'Unlock',
    ),
    'hosting_platform_op_verify' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'label' => 'Verify',
    ),
    'node_promote_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'node_mass_update-14de7d028b4bffdf2b4a266562ca18ac' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'node_mass_update-9c585624b9b3af0b4687d5f97f35e047' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'node_publish_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'system_goto_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'node_unpromote_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'node_mass_update-8ce21b08bb8e773d10018b484fe4815e' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'node_save_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'system_send_email_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'hosting_site_op_backup' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'hosting_site_op_delete' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'hosting_site_op_disable' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'hosting_site_op_enable' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'hosting_site_op_login_reset' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'hosting_site_op_verify' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'node_mass_update-0ccad85c1ebe4c9ceada1aa64293b080' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'node_unpublish_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
  );
  $handler->display->display_options['style_options']['execution_type'] = '1';
  $handler->display->display_options['style_options']['display_type'] = '0';
  $handler->display->display_options['style_options']['display_result'] = 0;
  $handler->display->display_options['style_options']['merge_single_action'] = 1;
  $handler->display->display_options['style_options']['hide_selector'] = 0;
  $handler->display->display_options['style_options']['preserve_selection'] = 1;
  /* Relationship: Hosting Platform: Web Server */
  $handler->display->display_options['relationships']['web_server']['id'] = 'web_server';
  $handler->display->display_options['relationships']['web_server']['table'] = 'hosting_platform';
  $handler->display->display_options['relationships']['web_server']['field'] = 'web_server';
  $handler->display->display_options['relationships']['web_server']['required'] = 0;
  /* Field: Class */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'hosting_platform';
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
  $handler->display->display_options['fields']['title']['label'] = 'Platform';
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
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Hosting Platform: Release */
  $handler->display->display_options['fields']['release']['id'] = 'release';
  $handler->display->display_options['fields']['release']['table'] = 'hosting_platform';
  $handler->display->display_options['fields']['release']['field'] = 'release';
  $handler->display->display_options['fields']['release']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['release']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['release']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['release']['alter']['external'] = 0;
  $handler->display->display_options['fields']['release']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['release']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['release']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['release']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['release']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['release']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['release']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['release']['alter']['html'] = 0;
  $handler->display->display_options['fields']['release']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['release']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['release']['hide_empty'] = 0;
  $handler->display->display_options['fields']['release']['empty_zero'] = 0;
  $handler->display->display_options['fields']['release']['hide_alter_empty'] = 1;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'web_server';
  $handler->display->display_options['fields']['title_1']['label'] = 'Server';
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
  /* Field: Hosting Platform: Verified Date */
  $handler->display->display_options['fields']['verified']['id'] = 'verified';
  $handler->display->display_options['fields']['verified']['table'] = 'hosting_platform';
  $handler->display->display_options['fields']['verified']['field'] = 'verified';
  $handler->display->display_options['fields']['verified']['label'] = 'Verified';
  $handler->display->display_options['fields']['verified']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['verified']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['verified']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['verified']['alter']['external'] = 0;
  $handler->display->display_options['fields']['verified']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['verified']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['verified']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['verified']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['verified']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['verified']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['verified']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['verified']['alter']['html'] = 0;
  $handler->display->display_options['fields']['verified']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['verified']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['verified']['hide_empty'] = 0;
  $handler->display->display_options['fields']['verified']['empty_zero'] = 0;
  $handler->display->display_options['fields']['verified']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['verified']['date_format'] = 'time ago';
  /* Field: Hosting Platform: Sites */
  $handler->display->display_options['fields']['sites']['id'] = 'sites';
  $handler->display->display_options['fields']['sites']['table'] = 'hosting_platform';
  $handler->display->display_options['fields']['sites']['field'] = 'sites';
  $handler->display->display_options['fields']['sites']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['sites']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['sites']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['sites']['alter']['external'] = 0;
  $handler->display->display_options['fields']['sites']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['sites']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['sites']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['sites']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['sites']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['sites']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['sites']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['sites']['alter']['html'] = 0;
  $handler->display->display_options['fields']['sites']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['sites']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['sites']['hide_empty'] = 0;
  $handler->display->display_options['fields']['sites']['empty_zero'] = 0;
  $handler->display->display_options['fields']['sites']['hide_alter_empty'] = 1;
  /* Sort criterion: Node: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Argument: Node: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'platform' => 'platform',
  );
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter: Hosting Platform: Status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'hosting_platform';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['operator'] = '!=';
  $handler->display->display_options['filters']['status_1']['value']['value'] = '-2';
  $handler->display->display_options['filters']['status_1']['allow_null'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_platforms');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view platform';
  $handler->display->display_options['path'] = 'hosting/platforms';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Platforms';
  $handler->display->display_options['menu']['description'] = 'List of platforms';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'primary-links';

  /* Display: Block: Server */
  $handler = $view->new_display('block', 'Block: Server', 'block_server');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Node: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'web_server';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;

  $views[$view->name] = $view;

  return $views;
}

