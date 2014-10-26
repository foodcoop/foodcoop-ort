<?php
/**
 * @file
 * psfc_orientation_features.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function psfc_orientation_features_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '2',
  );

  // Exported role: orientation admin.
  $roles['orientation admin'] = array(
    'name' => 'orientation admin',
    'weight' => '3',
  );

  // Exported role: pre-authorized.
  $roles['pre-authorized'] = array(
    'name' => 'pre-authorized',
    'weight' => '4',
  );

  return $roles;
}
