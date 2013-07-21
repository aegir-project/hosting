<?php
/**
 * @file
 *   Expose the platform feature to hostmaster.
 */

/**
 * Implementation of hook_hosting_feature().
 */
function hosting_platform_hosting_feature() {
  $features['platform'] = array(
    'title' => t('Platform administration'),
    'description' => t('Create and manage platforms.'),
    'status' => HOSTING_FEATURE_REQUIRED,
    'module' => 'hosting_platform',
    'node' => 'platform',
    'group' => 'required',
  );
  return $features;
}

