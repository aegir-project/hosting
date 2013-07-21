<?php
/**
 * @file
 *   Expose the site feature to hostmaster.
 */

/**
 * Implementation of hook_hosting_feature().
 */
function hosting_site_hosting_feature() {
  $features['site'] = array(
    'title' => t('Site administration'),
    'description' => t('Create and manage sites.'),
    'status' => HOSTING_FEATURE_REQUIRED,
    'module' => 'hosting_site',
    'node' => 'site',
    'group' => 'required',
  );
  return $features;
}

