<?php

/**
 * @file
 * Drush hooks for the hosting_task module.
 */

/**
 * Implements hook_drush_init().
 *
 * This function registers a shutdown function to update the task status after
 * drush completes it's run.
 *
 * The call to register_shutdown_function() is needed to ensure we get a status
 * update no matter what happens with drush.
 */
function hosting_task_drush_init() {
  // Update a task's status after Drush operations are complete.
  register_shutdown_function('hosting_task_drush_update_status');
}

/**
 * Shutdown function to catch any task status.
 */
function hosting_task_drush_update_status() {
  $task = drush_get_context('HOSTING_TASK');
  if (!empty($task)) {
    $task_code = hosting_task_update_status($task);
    $message = _hosting_parse_error_code($task_code);

    // Translate status int to drush log type.
    switch ($task_code) {
      case HOSTING_TASK_SUCCESS:
        $drush_message_type = 'success';
        break;

      case HOSTING_TASK_WARNING:
        $drush_message_type = 'warning';
        break;

      case HOSTING_TASK_ERROR:
        $drush_message_type = 'error';
        break;

      default:
        $drush_message_type = 'info';
        break;
    }
    drush_log(dt('Updated task status to "!log"', array('!log' => $message)), $drush_message_type);
  }
}
