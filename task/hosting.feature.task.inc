<?php
/**
 * @file
 * Expose the task feature to hostmaster.
 */

/**
 * Implements hook_hosting_feature().
 */
function hosting_task_hosting_feature() {
  $features['task'] = array(
    'title' => t('Tasks'),
    'description' => t('API to provide support for tasks.'),
    'status' => HOSTING_FEATURE_REQUIRED,
    'module' => 'hosting_task',
    'node' => 'task',
    'group' => 'required',
    'role_permissions' => array(
      'aegir platform manager' => array(
        'administer tasks',
        'create lock task',
        'create unlock task',
        'create verify task',
        'access task logs',
        'cancel own tasks',
        'view own tasks',
        'retry failed tasks',
        'view task',
      ),
      'aegir client' => array(
        'create backup task',
        'create delete task',
        'create disable task',
        'create enable task',
        'create restore task',
        'create verify task',
        'access task logs',
        'view own tasks',
        'view task',
        'cancel own tasks',
      ),
    ),

  );
  return $features;
}
