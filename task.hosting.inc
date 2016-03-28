<?php

/**
 * @file
 * Drush include for the Hosting module's hosting task command.
 */

/**
 * Log a message to the current task's node if possible, the screen otherwise.
 */
function _hosting_task_log($entry) {
  $task = drush_get_context('HOSTING_TASK');
  if ($task->vid) {
    hosting_task_log($task->vid, $entry['type'], $entry['message'], $entry['error'], $entry['timestamp']);
  }
  else {
    _hosting_task_log_print($entry);
  }
  if (drush_get_option('debug', FALSE)) {
    _hosting_task_log_print($entry);
  }
}

/**
 * Switch between Drush 8's OO logging and the older private function.
 */
function _hosting_task_log_print($entry) {
  if (function_exists('_drush_print_log')) {
    // Remove after dropping Drush 6 comaptibility.
    return _drush_print_log($entry);
  }
  else {
    $logger = new Drush\Log\Logger();
    return $logger->log($entry['type'], $entry['message'], $entry);
  }
}

/**
 * Validate hook for the hosting-task Drush command.
 *
 * We do some magic in this command to allow the user to run either a specifc
 * task by specifying a node id or chosen task type by specifying the type of
 * task, e.g. 'verify' or 'migrate'.
 *
 * @see drush_hosting_task()
 */
function drush_hosting_task_validate($id, $type = NULL) {
  drush_set_option('user', 1);
  drush_bootstrap(DRUSH_BOOTSTRAP_DRUPAL_LOGIN);
  if (is_numeric($id)) {
    $task = node_load($id);
  }
  elseif (is_string($id) && isset($type)) {
    $ref = hosting_context_load($id);
    if ($ref->nid) {
      $task = hosting_add_task($ref->nid, $type);
    }
  }

  if ($task->type == 'task') {
    $task->ref = node_load($task->rid);
    $task->options = array();
    $task->context_options = array(
      'context_type' => $task->ref->type,
      'master_url' => url('', array('absolute' => TRUE)),
      'root' => NULL,
      'uri' => NULL,
    );
    $task->args = array();
    $task->changed = REQUEST_TIME;
    $task->executed = REQUEST_TIME;
    /* if not already running, remove the task from the queue
     * this is to avoid concurrent task runs */
    if ($task->task_status == HOSTING_TASK_PROCESSING && !drush_get_option('force', FALSE)) {
      return drush_set_error('HOSTING_TASK_RUNNING', dt("This task is already running, use --force"));
    }
    if ($task->task_status != HOSTING_TASK_QUEUED && !drush_get_option('force', FALSE)) {
      return drush_set_error('HOSTING_TASK_NOT_QUEUED', dt("This task is not queued, use --force"));
    }
    $task->task_status = HOSTING_TASK_PROCESSING;
    $task->revision = TRUE;
    node_save($task);
    drush_set_context('HOSTING_TASK', $task);
    drush_set_context('DRUSH_LOG_CALLBACK', '_hosting_task_log');
    drush_log(dt("Task starts processing") . ': ' . $task->title, 'queue');

    // Load Task Info.
    $tasks_info = hosting_available_tasks($task->ref->type);

    // Find task type and pass through if it needs provision_save.
    if (isset($tasks_info[$task->task_type])) {
      $task->task_info = $tasks_info[$task->task_type];
    }
  }
  else {
    drush_set_error('HOSTING_INVALID_TASK', t("This task is not valid"));
  }

}

/**
 * Drush hosting task command.
 *
 * This is the main way that the frontend communicates with the backend. Tasks
 * correspond to backend drush commands, and the results and log of the command
 * are attached to the task for reference.
 *
 * @see drush_hosting_task_validate()
 * @see hook_hosting_TASK_OBJECT_context_options()
 */
function drush_hosting_task() {
  $task = &drush_get_context('HOSTING_TASK');
  $output = array();
  $mode = drush_get_option('debug', FALSE) ? 'GET' : 'POST';

  // Make sure argument order is correct.
  ksort($task->args);

  // If this task type needs it, run provision-save to create the named context.
  if (!empty($task->task_info['provision_save'])) {
    // Invoke hook_hosting_TASK_OBJECT_context_options()
    // We copy module_invoke_all() here because it doesn't pass by
    // reference and it breaks under PHP 5.3
    $hook = 'hosting_' . $task->ref->type . '_context_options';
    foreach (module_implements($hook) as $module) {
      $function = $module . '_' . $hook;
      call_user_func($function, $task);
    }

    drush_invoke_process('@none', 'provision-save', array('@' . $task->ref->hosting_name), $task->context_options, array('method' => $mode, 'integrate' => TRUE));
  }

  if (($task->ref->type == 'site' && $task->ref->site_status == HOSTING_SITE_DELETED)
    || ($task->ref->type == 'platform' && $task->ref->platform_status == HOSTING_PLATFORM_DELETED)) {

    // We're performing a task on a site that has been deleted...
    // d() will not be returning a site object.
    $alias = '@none';
  }
  else {
    $alias = $task->ref->hosting_name;
  }

  // Run the actual command. Adding alias here to work around Drush API.
  $output = provision_backend_invoke($alias, 'provision-' . $task->task_type, $task->args, $task->options, $mode);
  // Pass the drush output back to the HOOK_post_hosting_TASK_task() and
  // HOOK_hosting_TASK_task_rollback() hooks, as the $data argument.
  drush_set_context('HOSTING_DRUSH_OUTPUT', $output);

  // On succesful delete, remove the named context.
  if ($task->task_type === 'delete' && !drush_get_error()) {
    drush_invoke_process('@none', 'provision-save', array('@' . $task->ref->hosting_name), array('delete' => TRUE), array('method' => $mode, 'integrate' => TRUE));
  }

  // New revision is created at the beginning of function.
  $task->revision = FALSE;
  $task->delta = microtime(TRUE) - $task->executed;
  node_save($task);
}

/**
 * Rollback hook for the hosting-task Drush command.
 *
 * @see hook_hosting_TASK_TYPE_task_rollback()
 */
function drush_hosting_task_rollback() {
  $task = &drush_get_context('HOSTING_TASK');
  $hook = sprintf("hosting_%s_task_rollback", str_replace('-', '_', $task->task_type));
  drush_log(dt('Invoking :hook hooks.', array(':hook' => $hook)));
  module_invoke_all($hook, $task, drush_get_context('HOSTING_DRUSH_OUTPUT'));
}

/**
 * Post completion hook for the hosting-task Drush command.
 *
 * @see hook_post_hosting_TASK_TYPE_task()
 */
function drush_hosting_post_hosting_task($task) {
  $task = &drush_get_context('HOSTING_TASK');

  $hook = sprintf("post_hosting_%s_task", str_replace('-', '_', $task->task_type));
  drush_log(dt('Invoking :hook hooks.', array(':hook' => $hook)));
  module_invoke_all($hook, $task, drush_get_context('HOSTING_DRUSH_OUTPUT'));
}
