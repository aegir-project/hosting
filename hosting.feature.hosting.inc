<?php
/**
 * @file
 * Expose the hosting feature to hostmaster.
 */

/**
 * Implements hook_hosting_feature().
 */
function hosting_hosting_feature() {
  $features['hosting'] = array(
    'title' => t('Hosting system'),
    'description' => t('API to provide support for servers, platforms and sites.'),
    'status' => HOSTING_FEATURE_REQUIRED,
    'module' => 'hosting',
    'group' => 'required',
    // Normally Hosting features will assign their own permissions to various
    // roles. This module defines these roles, and thus assigns permissions
    // from Drupal core and contrib modules as well. Since it only provides
    // administrator-level permissions, and the aegir_administrator role is
    // automatically assigned all permissions defined in Hosting features, none
    // are assigned explicitely here.
    'role_permissions' => array(
      'aegir administrator' => array(
        'access administration menu',
        'access content',
        'view revisions',
        'access user profiles',
      ),
      'aegir platform manager' => array(
        'access content',
  //      'search content',
  //      'use advanced search',
        'view revisions',
      ),
      'aegir account manager' => array(
        'access content',
        'access user profiles',
      ),
      'aegir client' => array(
        'access content',
        'view revisions',
      ),
    ),
  );
  return $features;
}
