<?php
/**
 * @file
 *   Expose the subdirs feature to hostmaster.
 */

/**
 * Implementation of hook_hosting_feature().
 */
function hosting_subdirs_hosting_feature() {
  $features['subdirs'] = array(
    'title' => t('Site subdirectories'),
    'description' => t('Subdirectory multisite support.'),
    'status' => HOSTING_FEATURE_DISABLED,
    'module' => 'hosting_subdirs',
    'group' => 'experimental'
    );
  return $features;
}

