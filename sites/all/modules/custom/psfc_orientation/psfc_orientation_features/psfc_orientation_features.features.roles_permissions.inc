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
