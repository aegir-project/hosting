<?php


/**
 * @file
 * The hosting feature definition for the task garbage collection.
 */

/**
 * Register a hosting feature with Aegir.
 *
 * This will be used to generate the 'admin/hosting' page.
 *
 * @return array
 *   associative array indexed by feature key.
 */
function hosting_task_gc_hosting_feature() {
  $features['task_gc'] = array(
    // Title to display in form.
    'title' => t('Task garbage collection'),
    'description' => t('Cleanup task records for deleted sites.'),
    // Initial status.
    'status' => HOSTING_FEATURE_DISABLED,
    // Module to enable/disable alongside feature.
    'module' => 'hosting_task_gc',
    // Which group to display in ( null , experimental ).
    'group' => 'experimental',
  );
  return $features;
}
