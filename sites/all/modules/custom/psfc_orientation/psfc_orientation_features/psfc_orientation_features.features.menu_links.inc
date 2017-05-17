<?php
/**
 * @file
 * psfc_orientation_features.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function psfc_orientation_features_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_administer-psfc-orientation:admin/psfc/orientation.
  $menu_links['navigation_administer-psfc-orientation:admin/psfc/orientation'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'admin/psfc/orientation',
    'router_path' => 'admin/psfc/orientation',
    'link_title' => 'PSFC Orientation Administration',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage users who want to attend an orientation',
      ),
      'identifier' => 'navigation_administer-psfc-orientation:admin/psfc/orientation',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Administer PSFC Orientation');

  return $menu_links;
}
