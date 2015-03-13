<?php
/**
 * @file
 * Register a Hosting feature for the Sign-up module.osting feature for
 * the Sign-up module.
 */

/**
 * Implements hook_hosting_feature().
 */
function hosting_signup_hosting_feature() {
  $features['signup'] = array(
    'title' => t('Sign up form'),
    'description' => t('Provides a simpler signup form that can be opened to anonymous users.'),
    'status' => HOSTING_FEATURE_DISABLED,
    'module' => 'hosting_signup',
    'group' => 'optional',
    'role_permissions' => array(
      'anonymous user' => array(
        'access hosting signup form',
      ),
    ),
  );
  return $features;
}
