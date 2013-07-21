<?php
/**
 * @file
 *   Expose the hosting feature to hostmaster.
 */

/**
 * Implementation of hook_hosting_feature().
 */
function hosting_hosting_feature() {
  $features['hosting'] = array(
    'title' => t('Hosting system'),
    'description' => t('API to provide support for servers, platforms and sites.'),
    'status' => HOSTING_FEATURE_REQUIRED,
    'module' => 'hosting',
    'group' => 'required',
    );
  return $features;
}

