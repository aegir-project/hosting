<?php
/**
 * @file
 */

/**
 * Implementation of hook_views_default_views().
 */
function hosting_task_views_default_views() {
  $views = array();

  // Exported view: hosting_task_list
  $view = new view;
  $view->name = 'hosting_task_list';
  $view->description = 'Display a list of tasks in aegir';
  $view->tag = 'hosting_task';
  $view->base_table = 'node';
  $view->human_name = 'Hosting tasks list';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Queues';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'More tasks';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access task logs';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = '[task_status]';
  $handler->display->display_options['style_options']['columns'] = array(
    'task_status' => 'task_status',
    'title' => 'title',
    'task_type' => 'task_type',
    'created' => 'created',
    'executed' => 'executed',
    'delta' => 'delta',
    'view_node' => 'view_node',
  );
  $handler->display->display_options['style_options']['default'] = 'executed';
  $handler->display->display_options['style_options']['info'] = array(
    'task_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'task_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
    ),
    'executed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
    ),
    'delta' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Hosting Task: Reference ID */
  $handler->display->display_options['relationships']['rid']['id'] = 'rid';
  $handler->display->display_options['relationships']['rid']['table'] = 'hosting_task';
  $handler->display->display_options['relationships']['rid']['field'] = 'rid';
  $handler->display->display_options['relationships']['rid']['required'] = 0;
  /* Field: Hosting Task: Status */
  $handler->display->display_options['fields']['task_status']['id'] = 'task_status';
  $handler->display->display_options['fields']['task_status']['table'] = 'hosting_task';
  $handler->display->display_options['fields']['task_status']['field'] = 'task_status';
  $handler->display->display_options['fields']['task_status']['label'] = '';
  $handler->display->display_options['fields']['task_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['task_status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['task_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['task_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['status_mode'] = 'class';
  $handler->display->display_options['fields']['task_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['task_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['task_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['task_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['task_status']['hide_alter_empty'] = 1;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'rid';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Hosting Task: Type */
  $handler->display->display_options['fields']['task_type']['id'] = 'task_type';
  $handler->display->display_options['fields']['task_type']['table'] = 'hosting_task';
  $handler->display->display_options['fields']['task_type']['field'] = 'task_type';
  $handler->display->display_options['fields']['task_type']['label'] = 'Task';
  $handler->display->display_options['fields']['task_type']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['task_type']['alter']['text'] = '[task_type]: [title]';
  $handler->display->display_options['fields']['task_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['task_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['task_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['task_type']['element_class'] = 'hosting-status';
  $handler->display->display_options['fields']['task_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['task_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['task_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['task_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['task_type']['hide_alter_empty'] = 1;
  /* Field: Node: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Actions';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['link_class'] = 'hosting-button-enabled hosting-button-log hosting-button-dialog';
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_class'] = 'hosting-actions';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Sort criterion: Node: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Sort criterion: Hosting Task: Executed */
  $handler->display->display_options['sorts']['executed']['id'] = 'executed';
  $handler->display->display_options['sorts']['executed']['table'] = 'hosting_task';
  $handler->display->display_options['sorts']['executed']['field'] = 'executed';
  $handler->display->display_options['sorts']['executed']['order'] = 'DESC';
  /* Sort criterion: Hosting Task: Default */
  $handler->display->display_options['sorts']['hosting_task_default_1']['id'] = 'hosting_task_default_1';
  $handler->display->display_options['sorts']['hosting_task_default_1']['table'] = 'hosting_task';
  $handler->display->display_options['sorts']['hosting_task_default_1']['field'] = 'hosting_task_default';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'task' => 'task',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Node: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Sort criterion: Hosting Task: Executed */
  $handler->display->display_options['sorts']['executed']['id'] = 'executed';
  $handler->display->display_options['sorts']['executed']['table'] = 'hosting_task';
  $handler->display->display_options['sorts']['executed']['field'] = 'executed';
  $handler->display->display_options['sorts']['executed']['order'] = 'DESC';
  /* Sort criterion: Hosting Task: Default */
  $handler->display->display_options['sorts']['hosting_task_default_1']['id'] = 'hosting_task_default_1';
  $handler->display->display_options['sorts']['hosting_task_default_1']['table'] = 'hosting_task';
  $handler->display->display_options['sorts']['hosting_task_default_1']['field'] = 'hosting_task_default';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_tasks');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = '[task_status]';
  $handler->display->display_options['style_options']['columns'] = array(
    'task_status' => 'task_status',
    'title' => 'title',
    'task_type' => 'task_type',
    'timestamp' => 'timestamp',
    'delta' => 'delta',
    'view_node' => 'view_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'task_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'task_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
    ),
    'delta' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
    ),
    'view_node' => array(
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Hosting Task: Status */
  $handler->display->display_options['fields']['task_status']['id'] = 'task_status';
  $handler->display->display_options['fields']['task_status']['table'] = 'hosting_task';
  $handler->display->display_options['fields']['task_status']['field'] = 'task_status';
  $handler->display->display_options['fields']['task_status']['label'] = '';
  $handler->display->display_options['fields']['task_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['task_status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['task_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['task_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['status_mode'] = 'class';
  $handler->display->display_options['fields']['task_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['task_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['task_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['task_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['task_status']['hide_alter_empty'] = 1;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'rid';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
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
  /* Field: Hosting Task: Type */
  $handler->display->display_options['fields']['task_type']['id'] = 'task_type';
  $handler->display->display_options['fields']['task_type']['table'] = 'hosting_task';
  $handler->display->display_options['fields']['task_type']['field'] = 'task_type';
  $handler->display->display_options['fields']['task_type']['label'] = 'Task';
  $handler->display->display_options['fields']['task_type']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['task_type']['alter']['text'] = '[task_type]: [title]';
  $handler->display->display_options['fields']['task_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['task_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['task_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['task_type']['element_class'] = 'hosting-status';
  $handler->display->display_options['fields']['task_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['task_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['task_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['task_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['task_type']['hide_alter_empty'] = 1;
  /* Field: Node revision: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Scheduled';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['timestamp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['timestamp']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  /* Field: Hosting Task: Execution time */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'hosting_task';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delta']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delta']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delta']['alter']['external'] = 0;
  $handler->display->display_options['fields']['delta']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['delta']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['delta']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['delta']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delta']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delta']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delta']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delta']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delta']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['delta']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['delta']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delta']['empty_zero'] = 0;
  $handler->display->display_options['fields']['delta']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['delta']['granularity'] = '2';
  /* Field: Node: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Actions';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['link_class'] = 'hosting-button-enabled hosting-button-log hosting-button-dialog';
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_class'] = 'hosting-actions';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  $handler->display->display_options['path'] = 'hosting/queues/tasks';
  $views[$view->name] = $view;

  // Exported view: hosting_task_log
  $view = new view;
  $view->name = 'hosting_task_log';
  $view->description = 'List of Hosting tasks that have run on a given Aegir entity';
  $view->tag = '';
  $view->base_table = 'node_revisions';
  $view->human_name = 'Task Log';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['css_class'] = 'view-hosting-task-list';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access task logs';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = '[task_status]';
  $handler->display->display_options['style_options']['columns'] = array(
    'task_status' => 'task_status',
    'nid' => 'nid',
    'vid' => 'vid',
    'title_1' => 'title_1',
    'timestamp' => 'timestamp',
    'executed' => 'executed',
    'delta' => 'delta',
    'rid' => 'rid',
    'task_type' => 'task_type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'task_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'vid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'timestamp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'executed' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'delta' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'rid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'task_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Hosting Task: Reference ID */
  $handler->display->display_options['relationships']['rid']['id'] = 'rid';
  $handler->display->display_options['relationships']['rid']['table'] = 'hosting_task';
  $handler->display->display_options['relationships']['rid']['field'] = 'rid';
  /* Field: Hosting Task: Status */
  $handler->display->display_options['fields']['task_status']['id'] = 'task_status';
  $handler->display->display_options['fields']['task_status']['table'] = 'hosting_task';
  $handler->display->display_options['fields']['task_status']['field'] = 'task_status';
  $handler->display->display_options['fields']['task_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['task_status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['task_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['task_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['task_status']['alter']['status_mode'] = 'class';
  $handler->display->display_options['fields']['task_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['task_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['task_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['task_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['task_status']['hide_alter_empty'] = 1;
  /* Field: Node: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Node revision: Vid */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  $handler->display->display_options['fields']['vid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['vid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['vid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['vid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['vid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['vid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['vid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['vid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['vid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['vid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['vid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['vid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['vid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['vid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['vid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['vid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['vid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['vid']['hide_alter_empty'] = 1;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'rid';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Hosting Task: Type */
  $handler->display->display_options['fields']['task_type']['id'] = 'task_type';
  $handler->display->display_options['fields']['task_type']['table'] = 'hosting_task';
  $handler->display->display_options['fields']['task_type']['field'] = 'task_type';
  $handler->display->display_options['fields']['task_type']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['task_type']['alter']['text'] = '[task_type]: [title]';
  $handler->display->display_options['fields']['task_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['task_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['task_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['task_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['task_type']['element_class'] = 'hosting-status';
  $handler->display->display_options['fields']['task_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['task_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['task_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['task_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['task_type']['hide_alter_empty'] = 1;
  /* Field: Hosting Task: Executed */
  $handler->display->display_options['fields']['executed']['id'] = 'executed';
  $handler->display->display_options['fields']['executed']['table'] = 'hosting_task';
  $handler->display->display_options['fields']['executed']['field'] = 'executed';
  $handler->display->display_options['fields']['executed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['executed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['executed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['executed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['executed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['executed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['executed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['executed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['executed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['executed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['executed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['executed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['executed']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['executed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['executed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['executed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['executed']['hide_alter_empty'] = 1;
  /* Field: Hosting Task: Execution time */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'hosting_task';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delta']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delta']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delta']['alter']['external'] = 0;
  $handler->display->display_options['fields']['delta']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['delta']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['delta']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['delta']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delta']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delta']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delta']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delta']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delta']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['delta']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['delta']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delta']['empty_zero'] = 0;
  $handler->display->display_options['fields']['delta']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['delta']['granularity'] = '2';
  /* Field: View link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'View link';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/[nid]/revisions/[vid]/view';
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'hosting-button-enabled hosting-button-log hosting-button-dialog';
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_class'] = 'hosting-actions';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Sort criterion: Node revision: Updated date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'node_revisions';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Argument: Hosting Task: Reference ID */
  $handler->display->display_options['arguments']['rid']['id'] = 'rid';
  $handler->display->display_options['arguments']['rid']['table'] = 'hosting_task';
  $handler->display->display_options['arguments']['rid']['field'] = 'rid';
  $handler->display->display_options['arguments']['rid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['rid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['rid']['title'] = 'Task log for %1';
  $handler->display->display_options['arguments']['rid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['rid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['rid']['validate_type'] = 'node';
  $handler->display->display_options['arguments']['rid']['validate_options']['types'] = array(
    'platform' => 'platform',
    'server' => 'server',
    'site' => 'site',
  );
  $handler->display->display_options['arguments']['rid']['validate_options']['access'] = 1;
  $handler->display->display_options['arguments']['rid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['rid']['not'] = 0;
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'task' => 'task',
  );
  /* Filter: Hosting Task: Status */
  $handler->display->display_options['filters']['task_status']['id'] = 'task_status';
  $handler->display->display_options['filters']['task_status']['table'] = 'hosting_task';
  $handler->display->display_options['filters']['task_status']['field'] = 'task_status';
  $handler->display->display_options['filters']['task_status']['value'] = array(
    1 => '1',
    2 => '2',
    3 => '3',
  );
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'rid';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'platform' => 'platform',
    'server' => 'server',
    'site' => 'site',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'node/%/tasks';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Task log';
  $handler->display->display_options['menu']['description'] = 'A log of all tasks run on this entity';
  $handler->display->display_options['menu']['weight'] = '0';

  $views[$view->name] = $view;

  return $views;
}



