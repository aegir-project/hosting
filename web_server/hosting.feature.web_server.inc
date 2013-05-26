<?php
/**
 * @file
 *   Expose the web_server feature to hostmaster.
 */

/**
 * Implementation of hook_hosting_feature().
 */
function hosting_web_server_hosting_feature() {
  $features['web_server'] = array(
    'title' => t('Web servers'),
    'description' => t('API to provide support for web servers.'),
    'status' => HOSTING_FEATURE_REQUIRED,
    'module' => 'hosting_web_server',
    'group' => 'required',
    );
  return $features;
}

