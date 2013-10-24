<?php
/**
 * @file Hosting task views integration.
 */

/**
 * Implements hook_views_handlers().
 */
function hosting_task_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'hosting_task'),
    ),
    'handlers' => array(
      'hosting_task_handler_field_hosting_task_status' => array(
        'parent' => 'views_handler_field',
      ),
      'hosting_task_handler_filter_hosting_task_status' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      'hosting_task_handler_filter_hosting_task_type' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      'hosting_task_handler_sort_hosting_task_default' => array(
        'parent' => 'views_handler_sort',
      ),
    ),
  );
}

/**
 * Implements hook_views_data().
 */
function hosting_task_views_data() {
  $data['hosting_task']['table'] = array(
    'group' => 'Hosting Task',
    'title' => 'Task',
    'join' => array(
      'node' => array(
        'left_field' => 'vid',
        'field' => 'vid',
      ),
      'node_revisions' => array(
        'left_field' => 'vid',
        'field' => 'vid',
      ),
    ),
  );

  $data['hosting_task']['task_type'] = array(
    'title' => t('Type'),
    'help' => t('The type of task.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'hosting_task_handler_filter_hosting_task_type',
    ),
  );

  $data['hosting_task']['rid'] = array(
    'title' => t('Reference ID'),
    'help' => t('The referenced ID for the task.'),
    'field' => array(
      'handler' => 'views_handler_field_node',
      'click sortable' => TRUE,
    ),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'node',
      'base field' => 'nid',
      'label' => t('Reference'),
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_node_nid',
    ),
  );

  $data['hosting_task']['task_status'] = array(
    'title' => t('Status'),
    'help' => t('Current status of the task.'),
    'field' => array(
      'handler' => 'hosting_task_handler_field_hosting_task_status',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'hosting_task_handler_filter_hosting_task_status',
    ),
  );

  $data['hosting_task']['executed'] = array(
    'title' => t('Executed'),
    'help' => t('Date this task was executed.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
  );

  $data['hosting_task']['delta'] = array(
    'title' => t('Execution time'),
    'help' => t('Time this task took.'),
    'field' => array(
      'handler' => 'views_handler_field_time_interval',
      'click sortable' => TRUE,
    ),
  );

  $data['hosting_task']['hosting_task_default'] = array(
    'title' => t('Default'),
    'help' => t('The default sort order for tasks.'),
    'sort' => array(
      'handler' => 'hosting_task_handler_sort_hosting_task_default',
    ),
  );

  return $data;
}


