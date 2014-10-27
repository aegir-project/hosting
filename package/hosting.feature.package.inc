<?php
/**
 * @file
 * Expose the package feature to hostmaster.
 */

/**
 * Implements hook_hosting_feature().
 */
function hosting_package_hosting_feature() {
  $features['package'] = array(
    'title' => t('Package management'),
    'description' => t('Keep track of which packages have been installed, and their versions.'),
    'status' => HOSTING_FEATURE_REQUIRED,
    'module' => 'hosting_package',
    'node' => 'package',
    'group' => 'required',
    'role_permissions' => array(
      'aegir platform manager' => array(
        'view package',
      ),
      'aegir client' => array(
        'view package',
      ),
    ),
  );
  return $features;
}
