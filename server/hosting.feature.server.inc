<?php
/**
 * @file
 *   Expose the server feature to hostmaster.
 */

/**
 * Implementation of hook_hosting_feature().
 */
function hosting_server_hosting_feature() {
  $features['server'] = array(
    'title' => t('Server administration'),
    'description' => t('Manage multiple servers.'),
    'status' => HOSTING_FEATURE_REQUIRED,
    'module' => 'hosting_server',
    'node' => 'server',
    'group' => 'required',
    );
  return $features;
}

