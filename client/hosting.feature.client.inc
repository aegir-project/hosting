<?php
/**
 * @file
 *   Expose the client feature to hostmaster.
 */

/**
 * Implementation of hook_hosting_feature().
 */
function hosting_client_hosting_feature() {
  $features['client'] = array(
      'title' => t('Clients'),
      'description' => t('Track and manage ownership of hosted sites, and access to platforms.'),
      'status' => HOSTING_FEATURE_REQUIRED,
      'module' => 'hosting_client',
      'node' => 'client',
      'group' => 'required',
    );
  return $features;
}
