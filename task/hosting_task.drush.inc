<?php

/**
 * @file Update a task's status after Drush operations are complete.
 */

/**
 * Implements hook_drush_exit().
 */
function hosting_task_drush_exit() {
  $task = drush_get_context('HOSTING_TASK');
  if ($task->vid) {
    $update = HOSTING_TASK_SUCCESS;
    $log = 'success';
    $result = db_query('SELECT type FROM {hosting_task_log} WHERE vid = %d', $task->vid);
    while ($status = db_result($result)) {
      if ($status == 'error') {
        $update = HOSTING_TASK_ERROR;
        $log = $status;
      }
      // Don't override a pre-existing error
      elseif ($update != HOSTING_TASK_ERROR && $status == 'warning') {
        $update = HOSTING_TASK_WARNING;
        $log = $status;
      }
    }
    db_query('UPDATE {hosting_task} SET task_status=%d WHERE vid = %d', $update, $task->vid);
    drush_log(dt('Updated task status to "!log"', array('!log' => $log)), $log);
  }
}
