<?php


/**
 * @file
 * The hosting feature definition for server data example.
 */

/**
 * Register a hosting feature with Aegir.
 *
 * This will be used to generate the 'admin/hosting' page.
 *
 * @return array
 *   associative array indexed by feature key.
 */
function hosting_server_data_hosting_feature() {
  $features['server_data'] = array(
    'title' => t('Server data example'),
    'description' => t('Example implementation of saving data into a server context.'),
    'status' => HOSTING_FEATURE_DISABLED,
    'module' => 'hosting_server_data',
    'group' => 'experimental',
  );
  return $features;
}
