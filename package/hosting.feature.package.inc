<?php
/**
 * @file
 *   Expose the package feature to hostmaster.
 */

/**
 * Implementation of hook_hosting_feature().
 */
function hosting_package_hosting_feature() {
  $features['package'] = array(
    'title' => t('Package management'),
    'description' => t('Keep track of which packages have been installed, and their versions.'),
    'status' => HOSTING_FEATURE_REQUIRED,
    'module' => 'hosting_package',
    'node' => 'package',
    'group' => 'required',
    );
  return $features;
}

