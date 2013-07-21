<?php
/**
 * @file
 *   Expose the client feature to hostmaster.
 */

/**
 * @file hosting.feature.client.inc
 * Register this module as an Aegir feature.
 */

/**
 * Implements hook_hosting_feature().
 */
function hosting_client_hosting_feature() {
  $features['client'] = array(
    'title' => t('Clients'),
    'description' => t('Track and manage ownership of hosted sites, and access to platforms.'),
    'status' => HOSTING_FEATURE_ENABLED,
    'module' => 'hosting_client',
    'node' => 'client',
    'group' => 'required',
  );
  return $features;
}
