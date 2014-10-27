<?php
/**
 * @file
 * Expose the platform feature to hostmaster.
 */

/**
 * Implements hook_hosting_feature().
 */
function hosting_platform_hosting_feature() {
  $features['platform'] = array(
    'title' => t('Platform administration'),
    'description' => t('Create and manage platforms.'),
    'status' => HOSTING_FEATURE_REQUIRED,
    'module' => 'hosting_platform',
    'node' => 'platform',
    'group' => 'required',
    'role_permissions' => array(
      'aegir platform manager' => array(
        'administer platforms',
        'create platform',
        'delete platform',
        'edit platform',
        'view locked platforms',
        'view platform',
        'create sites on locked platforms',
      ),
      'aegir client' => array(
        'view platform',
      ),
    ),

  );
  return $features;
}
