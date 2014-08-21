<?php
/**
 * @file
 * psfc_orientation_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function psfc_orientation_features_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function psfc_orientation_features_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function psfc_orientation_features_node_info() {
  $items = array(
    'orientation' => array(
      'name' => t('Orientation'),
      'base' => 'node_content',
      'description' => t('A single instance of an coop orientation at a particular time'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'orientation_attendee' => array(
      'name' => t('Orientation Attendee'),
      'base' => 'node_content',
      'description' => t('A person who has signed up to attend a single orientation.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
