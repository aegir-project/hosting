<?php

/**
 * @file
 *   Drush include for the Hosting module's hosting pause command.
 */

/**
 * Make sure Aegir is ready to be upgraded.
 */
function drush_hosting_pause_validate($url) {
  // Wait for the task queue to be processed and tasks to complete.
  while (hosting_task_count() + hosting_task_count_running() > 0) {
    drush_log(dt('Waiting for the task queue to be processed and tasks to complete.'), 'message');
    sleep(1);
  }
}

/**
 * Drush command to pause the Aegir frontend queues.
 *
 * This is really just deleting the crontab.
 */
function drush_hosting_pause($url) {
  // wipe out cron entry
  exec('crontab -r');
}
