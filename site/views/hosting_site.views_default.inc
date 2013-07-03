<?php
/**
 * @file
 */

/**
 * Implementation of hook_views_default_views().
 */
function hosting_site_views_default_views() {
  $views = array();

  // Exported view: hosting_site_list
  $view = new view;
  $view->name = 'hosting_site_list';
  $view->description = 'Display a list of sites hosted in aegir';
  $view->tag = 'hosting_site';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Sites';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view site';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 25;
  $handler->display->display_options['style_plugin'] = 'bulk';
  $handler->display->display_options['style_options']['row_class'] = '[status]';
  $handler->display->display_options['style_options']['columns'] = array(
    'status' => 'status',
    'title' => 'title',
    'title_3' => 'title_3',
    'created' => 'created',
    'title_2' => 'title_2',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'status' => array(
      'sortable' => 0,
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
    'title_3' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title_2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'hosting_platform_op_lock' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'hosting_platform_op_unlock' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
    ),
    'hosting_platform_op_verify' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'label' => '',
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
      'selected' => 1,
      'skip_confirmation' => 1,
      'label' => 'Backup',
    ),
    'hosting_site_op_delete' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'label' => 'Delete',
    ),
    'hosting_site_op_disable' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'label' => 'Disable',
    ),
    'hosting_site_op_enable' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'label' => 'Enable',
    ),
    'hosting_site_op_login_reset' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'label' => 'Reset Password',
    ),
    'hosting_site_op_verify' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'label' => 'Verify',
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
  $handler->display->display_options['exposed_block'] = TRUE;
  /* Relationship: Hosting Site: Install Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'hosting_site';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['required'] = 0;
  /* Relationship: Hosting Site: Platform */
  $handler->display->display_options['relationships']['platform']['id'] = 'platform';
  $handler->display->display_options['relationships']['platform']['table'] = 'hosting_site';
  $handler->display->display_options['relationships']['platform']['field'] = 'platform';
  /* Relationship: Hosting Site: Client */
  $handler->display->display_options['relationships']['client']['id'] = 'client';
  $handler->display->display_options['relationships']['client']['table'] = 'hosting_site';
  $handler->display->display_options['relationships']['client']['field'] = 'client';
  /* Field: Class */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'hosting_site';
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
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'hosting-status';
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title_3']['id'] = 'title_3';
  $handler->display->display_options['fields']['title_3']['table'] = 'node';
  $handler->display->display_options['fields']['title_3']['field'] = 'title';
  $handler->display->display_options['fields']['title_3']['relationship'] = 'profile';
  $handler->display->display_options['fields']['title_3']['label'] = 'Profile';
  $handler->display->display_options['fields']['title_3']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_3']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_3']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title_3']['link_to_node'] = 1;
  /* Field: Node: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'platform';
  $handler->display->display_options['fields']['title_2']['label'] = 'Platform';
  $handler->display->display_options['fields']['title_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['title_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['title_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_2']['link_to_node'] = 1;
  /* Sort criterion: Hosting Site: Status */
  $handler->display->display_options['sorts']['status']['id'] = 'status';
  $handler->display->display_options['sorts']['status']['table'] = 'hosting_site';
  $handler->display->display_options['sorts']['status']['field'] = 'status';
  $handler->display->display_options['sorts']['status']['order'] = 'DESC';
  /* Sort criterion: Node: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'site' => 'site',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter: Hosting Site: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'hosting_site';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['operator'] = 'not in';
  $handler->display->display_options['filters']['status']['value'] = array(
    -2 => '-2',
  );
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  /* Filter: Node: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Site';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['case'] = 1;
  /* Filter: Node: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['relationship'] = 'profile';
  $handler->display->display_options['filters']['title_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['operator'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['title_1']['expose']['label'] = 'Profile';
  $handler->display->display_options['filters']['title_1']['expose']['identifier'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['expose']['optional'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['single'] = TRUE;
  $handler->display->display_options['filters']['title_1']['case'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Empty text: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No sites have been created. <a href="/node/add/site">Click here</a> to add one.';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['path'] = 'hosting/sites';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Sites';
  $handler->display->display_options['menu']['description'] = 'List of sites';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'primary-links';

  /* Display: Block: Platform */
  $handler = $view->new_display('block', 'Block: Platform', 'block_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view platform';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Empty text: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No sites have been created on this platform. <a href="/node/!1/platform-add-site">Click here</a> to add one.';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['empty']['area']['tokenize'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Node: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'platform';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['validate_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'platform' => 'platform',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = 0;
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'site' => 'site',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter: Hosting Site: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'hosting_site';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['operator'] = 'not in';
  $handler->display->display_options['filters']['status']['value'] = array(
    -2 => '-2',
  );
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';

  /* Display: Block: Profile */
  $handler = $view->new_display('block', 'Block: Profile', 'block_profile');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view package';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Empty text: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No sites have been created using this profile. <a href="/node/add/site">Click here</a> to add a site.';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Node: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'profile';
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
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'site' => 'site',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter: Hosting Site: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'hosting_site';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['operator'] = 'not in';
  $handler->display->display_options['filters']['status']['value'] = array(
    -2 => '-2',
  );
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';

  /* Display: Block: Client */
  $handler = $view->new_display('block', 'Block: Client', 'block_client');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view client';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Empty text: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No sites have been created for this client. <a href="/node/!1/site/add">Click here</a> to add one.';
  $handler->display->display_options['empty']['area']['format'] = '1';
  $handler->display->display_options['empty']['area']['tokenize'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Node: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'client';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['validate_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'client' => 'client',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = 0;
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'site' => 'site',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter: Hosting Site: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'hosting_site';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['operator'] = 'not in';
  $handler->display->display_options['filters']['status']['value'] = array(
    -2 => '-2',
  );
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';

  $views[$view->name] = $view;

  return $views;
}

