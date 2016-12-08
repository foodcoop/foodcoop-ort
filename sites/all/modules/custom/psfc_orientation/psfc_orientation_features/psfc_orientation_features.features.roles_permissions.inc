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
      'administer orientation attendance' => TRUE,
      'administer psfc orientation' => TRUE,
      'administer users' => TRUE,
      'bypass node access' => TRUE,
      'use text format psfc_html_filter' => TRUE,
    ),
  );

  // Exported role: orientation staff
  $roles['orientation staff'] = array(
    'name' => 'orientation staff',
    'weight' => 5,
    'permissions' => array(
      'access content' => TRUE,
      'access content overview' => TRUE,
      'access overlay' => TRUE,
      'access print' => TRUE,
      'administer orientation attendance' => TRUE,
      'create orientation content' => TRUE,
      'create orientation_attendee content' => TRUE,
      'delete any orientation content' => TRUE,
      'delete any orientation_attendee content' => TRUE,
      'delete own orientation content' => TRUE,
      'delete own orientation_attendee content' => TRUE,
      'edit any orientation content' => TRUE,
      'edit any orientation_attendee content' => TRUE,
      'edit own orientation content' => TRUE,
      'edit own orientation_attendee content' => TRUE,
      'use text format filtered_html' => TRUE,
      'view own unpublished content' => TRUE,
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
