<?php
/**
 * @file
 *   Expose the task feature to hostmaster.
 */

/**
 * Implementation of hook_hosting_feature().
 */
function hosting_task_hosting_feature() {
  $features['task'] = array(
    'title' => t('Tasks'),
    'description' => t('API to provide support for tasks.'),
    'status' => HOSTING_FEATURE_REQUIRED,
    'module' => 'hosting_task',
    'node' => 'task',
    'group' => 'required',
    );
  return $features;
}

