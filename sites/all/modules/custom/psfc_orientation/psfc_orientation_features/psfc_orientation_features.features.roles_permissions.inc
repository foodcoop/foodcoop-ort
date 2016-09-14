<?php
/**
 * @file
 * psfc_orientation_features.features.roles_permissions.inc
 */

/**
 * Implements hook_default_roles_permissions().
 */
function psfc_orientation_features_default_roles_permissions() {
  $roles = array();

  // Exported role: administrator
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
    'permissions' => array(
      'access administration pages' => TRUE,
      'access all views' => TRUE,
      'access comments' => TRUE,
      'access content' => TRUE,
      'access content overview' => TRUE,
      'access contextual links' => TRUE,
      'access dashboard' => TRUE,
      'access overlay' => TRUE,
      'access site in maintenance mode' => TRUE,
      'access site reports' => TRUE,
      'access toolbar' => TRUE,
      'access user profiles' => TRUE,
      'administer actions' => TRUE,
      'administer blocks' => TRUE,
      'administer comments' => TRUE,
      'administer content types' => TRUE,
      'administer features' => TRUE,
      'administer field collections' => TRUE,
      'administer filters' => TRUE,
      'administer image styles' => TRUE,
      'administer menu' => TRUE,
      'administer modules' => TRUE,
      'administer nodes' => TRUE,
      'administer orientation attendance' => TRUE,
      'administer permissions' => TRUE,
      'administer psfc orientation' => TRUE,
      'administer search' => TRUE,
      'administer shortcuts' => TRUE,
      'administer site configuration' => TRUE,
      'administer software updates' => TRUE,
      'administer taxonomy' => TRUE,
      'administer themes' => TRUE,
      'administer unit tests' => TRUE,
      'administer url aliases' => TRUE,
      'administer users' => TRUE,
      'administer views' => TRUE,
      'block IP addresses' => TRUE,
      'bypass node access' => TRUE,
      'cancel account' => TRUE,
      'change own username' => TRUE,
      'create article content' => TRUE,
      'create orientation content' => TRUE,
      'create orientation_attendee content' => TRUE,
      'create page content' => TRUE,
      'create url aliases' => TRUE,
      'customize shortcut links' => TRUE,
      'delete any article content' => TRUE,
      'delete any orientation content' => TRUE,
      'delete any orientation_attendee content' => TRUE,
      'delete any page content' => TRUE,
      'delete own article content' => TRUE,
      'delete own orientation content' => TRUE,
      'delete own orientation_attendee content' => TRUE,
      'delete own page content' => TRUE,
      'delete revisions' => TRUE,
      'delete terms in 1' => TRUE,
      'edit any article content' => TRUE,
      'edit any orientation content' => TRUE,
      'edit any orientation_attendee content' => TRUE,
      'edit any page content' => TRUE,
      'edit own article content' => TRUE,
      'edit own comments' => TRUE,
      'edit own orientation content' => TRUE,
      'edit own orientation_attendee content' => TRUE,
      'edit own page content' => TRUE,
      'edit terms in 1' => TRUE,
      'manage features' => TRUE,
      'post comments' => TRUE,
      'revert revisions' => TRUE,
      'search content' => TRUE,
      'select account cancellation method' => TRUE,
      'sign up for psfc orientation' => TRUE,
      'skip comment approval' => TRUE,
      'switch shortcut sets' => TRUE,
      'use advanced search' => TRUE,
      'use text format filtered_html' => TRUE,
      'use text format full_html' => TRUE,
      'view own unpublished content' => TRUE,
      'view revisions' => TRUE,
      'view the administration theme' => TRUE,
    ),
  );

  // Exported role: orientation admin
  $roles['orientation admin'] = array(
    'name' => 'orientation admin',
    'weight' => 3,
    'permissions' => array(
      'administer orientation attendance' => TRUE,
      'administer psfc orientation' => TRUE,
      'administer users' => TRUE,
      'bypass node access' => TRUE,
      'sign up for psfc orientation' => TRUE,
    ),
  );

  // Exported role: pre-authorized
  $roles['pre-authorized'] = array(
    'name' => 'pre-authorized',
    'weight' => 4,
    'permissions' => array(
      'access content' => TRUE,
      'use text format filtered_html' => TRUE,
    ),
  );

  return $roles;
}
