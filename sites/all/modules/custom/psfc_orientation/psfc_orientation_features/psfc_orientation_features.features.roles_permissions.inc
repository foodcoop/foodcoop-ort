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

  // Exported role: orientation admin
  $roles['orientation admin'] = array(
    'name' => 'orientation admin',
    'weight' => 3,
    'permissions' => array(
      'access content overview' => TRUE,
      'access print' => TRUE,
      'access toolbar' => TRUE,
      'access user profiles' => TRUE,
      'administer content types' => TRUE,
      'administer nodes' => TRUE,
      'administer orientation attendance' => TRUE,
      'administer permissions' => TRUE,
      'administer psfc orientation' => TRUE,
      'administer users' => TRUE,
      'delete revisions' => TRUE,
      'revert revisions' => TRUE,
      'search content' => TRUE,
      'use advanced search' => TRUE,
      'view own unpublished content' => TRUE,
      'view revisions' => TRUE,
    ),
  );

  // Exported role: orientation staff
  $roles['orientation staff'] = array(
    'name' => 'orientation staff',
    'weight' => 4,
    'permissions' => array(
      'access content' => TRUE,
      'access content overview' => TRUE,
      'access print' => TRUE,
      'access toolbar' => TRUE,
      'administer orientation attendance' => TRUE,
      'administer psfc orientation' => TRUE,
      'delete revisions' => TRUE,
      'revert revisions' => TRUE,
      'use text format filtered_html' => TRUE,
      'view own unpublished content' => TRUE,
      'view revisions' => TRUE,
    ),
  );

  // Exported role: pre-authorized
  $roles['pre-authorized'] = array(
    'name' => 'pre-authorized',
    'weight' => 5,
    'permissions' => array(
      'access content' => TRUE,
      'use text format filtered_html' => TRUE,
    ),
  );

  return $roles;
}
