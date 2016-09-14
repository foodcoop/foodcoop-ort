<?php
/**
 * @file
 * psfc_orientation_features.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function psfc_orientation_features_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-psfc-orientation.
  $menus['menu-psfc-orientation'] = array(
    'menu_name' => 'menu-psfc-orientation',
    'title' => 'PSFC Orientation',
    'description' => 'Menu guiding users through the process of becoming a member.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Menu guiding users through the process of becoming a member.');
  t('PSFC Orientation');

  return $menus;
}
