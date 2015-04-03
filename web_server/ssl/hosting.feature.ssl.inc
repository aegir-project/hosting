<?php
/**
 * @file
 * Register this module as a Hosting feature.
 */

/**
 * Implements hook_hosting_feature().
 */
function hosting_ssl_hosting_feature() {
  $features['ssl'] = array(
    'title' => t('SSL support'),
    'description' => t('Provides a service to expose a site encrypted by SSL certificates.'),
    'status' => HOSTING_FEATURE_DISABLED,
    'module' => 'hosting_ssl',
    'group' => 'optional',
    'role_permissions' => array(
      'aegir client' => array(
        'create ssl certificate',
      ),
    ),
    'enable' => 'hosting_ssl_feature_enable_callback',

  );
  return $features;
}
