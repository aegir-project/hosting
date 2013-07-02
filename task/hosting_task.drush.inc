<?php

/**
 * @file Drush hooks for the hosting_task module.
 */

/**
 * Implements hook_drush_init().
 */
function hosting_task_drush_init() {
  // Update a task's status after Drush operations are complete.
  register_shutdown_function('_hosting_task_update_status');
}
