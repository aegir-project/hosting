<?php
/**
 * @file
 * Provide a default view listing tasks.
 */

/**
 * Implements hook_views_default_views().
 */
function hosting_task_views_default_views() {
  $views = array();

  // Exported view: hosting_task_list
  $view = new view();
  $view->name = 'hosting_task_list';
  $view->description = 'Display a list of tasks in Aegir.';
  $view->tag = 'hosting_task';
  $view->base_table = 'node';
  $view->human_name = 'Hosting Task list';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Task queue';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
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
    'nid' => 'nid',
    'executed' => 'executed',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'task_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'task_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'executed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Hosting Task: Reference ID */
  $handler->display->display_options['relationships']['rid']['id'] = 'rid';
  $handler->display->display_options['relationships']['rid']['table'] = 'hosting_task';
  $handler->display->display_options['relationships']['rid']['field'] = 'rid';
  /* Field: Hosting Task: Status */
  $handler->display->display_options['fields']['task_status']['id'] = 'task_status';
  $handler->display->display_options['fields']['task_status']['table'] = 'hosting_task';
  $handler->display->display_options['fields']['task_status']['field'] = 'task_status';
  $handler->display->display_options['fields']['task_status']['label'] = '';
  $handler->display->display_options['fields']['task_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['task_status']['alter']['status_mode'] = 'class';
  $handler->display->display_options['fields']['task_status']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'rid';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  /* Field: Hosting Task: Type */
  $handler->display->display_options['fields']['task_type']['id'] = 'task_type';
  $handler->display->display_options['fields']['task_type']['table'] = 'hosting_task';
  $handler->display->display_options['fields']['task_type']['field'] = 'task_type';
  $handler->display->display_options['fields']['task_type']['label'] = 'Task';
  $handler->display->display_options['fields']['task_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['task_type']['alter']['text'] = '[task_type]: [title]';
  $handler->display->display_options['fields']['task_type']['element_class'] = 'hosting-status';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Actions';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'hosting/task/[nid]';
  $handler->display->display_options['fields']['nid']['alter']['link_class'] = 'hosting-button-enabled hosting-button-log hosting-button-dialog';
  $handler->display->display_options['fields']['nid']['element_class'] = 'hosting-actions';
  /* Field: Hosting Task: Executed */
  $handler->display->display_options['fields']['executed']['id'] = 'executed';
  $handler->display->display_options['fields']['executed']['table'] = 'hosting_task';
  $handler->display->display_options['fields']['executed']['field'] = 'executed';
  $handler->display->display_options['fields']['executed']['exclude'] = TRUE;
  $handler->display->display_options['fields']['executed']['date_format'] = 'long';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Sort criterion: Hosting Task: Default */
  $handler->display->display_options['sorts']['hosting_task_default']['id'] = 'hosting_task_default';
  $handler->display->display_options['sorts']['hosting_task_default']['table'] = 'hosting_task';
  $handler->display->display_options['sorts']['hosting_task_default']['field'] = 'hosting_task_default';
  /* Sort criterion: Hosting Task: Executed */
  $handler->display->display_options['sorts']['executed']['id'] = 'executed';
  $handler->display->display_options['sorts']['executed']['table'] = 'hosting_task';
  $handler->display->display_options['sorts']['executed']['field'] = 'executed';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'task' => 'task',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Task queue';

  /* Display: Page: Global */
  $handler = $view->new_display('page', 'Page: Global', 'page_global');
  $handler->display->display_options['display_description'] = 'The global task queue.';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = '[task_status]';
  $handler->display->display_options['style_options']['columns'] = array(
    'task_status' => 'task_status',
    'title' => 'title',
    'task_type' => 'task_type',
    'created' => 'created',
    'executed' => 'executed',
    'delta' => 'delta',
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'task_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'task_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'executed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delta' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
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
  $handler->display->display_options['fields']['task_status']['alter']['status_mode'] = 'class';
  $handler->display->display_options['fields']['task_status']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'rid';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_class'] = 'hosting-status';
  /* Field: Hosting Task: Type */
  $handler->display->display_options['fields']['task_type']['id'] = 'task_type';
  $handler->display->display_options['fields']['task_type']['table'] = 'hosting_task';
  $handler->display->display_options['fields']['task_type']['field'] = 'task_type';
  $handler->display->display_options['fields']['task_type']['label'] = 'Task';
  $handler->display->display_options['fields']['task_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['task_type']['alter']['text'] = '[task_type]: [title]';
  $handler->display->display_options['fields']['task_type']['element_class'] = 'hosting-status';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  /* Field: Hosting Task: Executed */
  $handler->display->display_options['fields']['executed']['id'] = 'executed';
  $handler->display->display_options['fields']['executed']['table'] = 'hosting_task';
  $handler->display->display_options['fields']['executed']['field'] = 'executed';
  $handler->display->display_options['fields']['executed']['date_format'] = 'time ago';
  /* Field: Hosting Task: Execution time */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'hosting_task';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['granularity'] = '2';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Actions';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'hosting/task/[nid]';
  $handler->display->display_options['fields']['nid']['alter']['link_class'] = 'hosting-button-enabled hosting-button-log hosting-button-dialog';
  $handler->display->display_options['fields']['nid']['element_class'] = 'hosting-actions';
  $handler->display->display_options['path'] = 'hosting/tasks';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Tasks';
  $handler->display->display_options['menu']['description'] = 'A list of all queued and run tasks.';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page: Contextual */
  $handler = $view->new_display('page', 'Page: Contextual', 'page_contextual');
  $handler->display->display_options['display_description'] = 'The task queue for a site, platform or server.';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = '[task_status]';
  $handler->display->display_options['style_options']['columns'] = array(
    'task_status' => 'task_status',
    'title' => 'title',
    'task_type' => 'task_type',
    'created' => 'created',
    'executed' => 'executed',
    'delta' => 'delta',
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'task_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'task_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'executed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delta' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Hosting Task: Status */
  $handler->display->display_options['fields']['task_status']['id'] = 'task_status';
  $handler->display->display_options['fields']['task_status']['table'] = 'hosting_task';
  $handler->display->display_options['fields']['task_status']['field'] = 'task_status';
  $handler->display->display_options['fields']['task_status']['label'] = '';
  $handler->display->display_options['fields']['task_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['task_status']['alter']['status_mode'] = 'class';
  $handler->display->display_options['fields']['task_status']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'rid';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_class'] = 'hosting-status';
  /* Field: Hosting Task: Type */
  $handler->display->display_options['fields']['task_type']['id'] = 'task_type';
  $handler->display->display_options['fields']['task_type']['table'] = 'hosting_task';
  $handler->display->display_options['fields']['task_type']['field'] = 'task_type';
  $handler->display->display_options['fields']['task_type']['label'] = 'Task';
  $handler->display->display_options['fields']['task_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['task_type']['alter']['text'] = '[task_type]: [title]';
  $handler->display->display_options['fields']['task_type']['element_class'] = 'hosting-status';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  /* Field: Hosting Task: Executed */
  $handler->display->display_options['fields']['executed']['id'] = 'executed';
  $handler->display->display_options['fields']['executed']['table'] = 'hosting_task';
  $handler->display->display_options['fields']['executed']['field'] = 'executed';
  $handler->display->display_options['fields']['executed']['date_format'] = 'time ago';
  /* Field: Hosting Task: Execution time */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'hosting_task';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['granularity'] = '2';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Actions';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'hosting/task/[nid]';
  $handler->display->display_options['fields']['nid']['alter']['link_class'] = 'hosting-button-enabled hosting-button-log hosting-button-dialog';
  $handler->display->display_options['fields']['nid']['element_class'] = 'hosting-actions';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'rid';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'rid';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = '<span class="label">[type]</span> %1';
  $handler->display->display_options['arguments']['nid']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['breadcrumb'] = 'Tasks';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'platform' => 'platform',
    'server' => 'server',
    'site' => 'site',
  );
  $handler->display->display_options['path'] = 'node/%/tasks';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Tasks';
  $handler->display->display_options['menu']['description'] = 'A list of all tasks run on this item.';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'Tasks';
  $handler->display->display_options['tab_options']['description'] = 'All tasks for this item.';
  $handler->display->display_options['tab_options']['weight'] = '0';

  $views[$view->name] = $view;

  return $views;
}
