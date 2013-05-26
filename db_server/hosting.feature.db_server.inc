<?php
/**
 * @file
 *   Expose the db_server feature to hostmaster.
 */

/**
 * Implementation of hook_hosting_feature().
 */
function hosting_db_server_hosting_feature() {
  $features['db_server'] = array(
    'title' => t('Database servers'),
    'description' => t('API to provide support for database servers.'),
    'status' => HOSTING_FEATURE_REQUIRED,
    'module' => 'hosting_server',
    'group' => 'required',
    );
  return $features;
}

