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
  $view = new view();
  $view->name = 'hosting_task_list';
  $view->description = 'Display a list of tasks in Aegir';
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
  /* Relationship: Hosting Task: Reference ID */
  $handler->display->display_options['relationships']['rid']['id'] = 'rid';
  $handler->display->display_options['relationships']['rid']['table'] = 'hosting_task';
  $handler->display->display_options['relationships']['rid']['field'] = 'rid';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['task_status']['id'] = 'task_status';
  $handler->display->display_options['fields']['task_status']['table'] = 'hosting_task';
  $handler->display->display_options['fields']['task_status']['field'] = 'task_status';
  $handler->display->display_options['fields']['task_status']['label'] = '';
  $handler->display->display_options['fields']['task_status']['exclude'] = TRUE;
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
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_tasks');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['task_status']['id'] = 'task_status';
  $handler->display->display_options['fields']['task_status']['table'] = 'hosting_task';
  $handler->display->display_options['fields']['task_status']['field'] = 'task_status';
  $handler->display->display_options['fields']['task_status']['label'] = '';
  $handler->display->display_options['fields']['task_status']['exclude'] = TRUE;
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
  $handler->display->display_options['path'] = 'hosting/queues/tasks';

  $views[$view->name] = $view;

  return $views;
}


