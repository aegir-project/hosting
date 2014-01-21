<?php


/**
 * @file
 *   The hosting feature definition for site data example.
 */

/**
 * Register a hosting feature with Aegir.
 *
 * This will be used to generate the 'admin/hosting' page.
 *
 * @return
 *  associative array indexed by feature key.
 */
function hosting_site_data_hosting_feature() {
  $features['site_data'] = array(
    'title' => t('Site data example'),
    'description' => t('Example implementation of saving data into a site context.'),
    'status' => HOSTING_FEATURE_DISABLED,
    'module' => 'hosting_site_data',
    'group' => 'experimental'
    );
  return $features;
}
