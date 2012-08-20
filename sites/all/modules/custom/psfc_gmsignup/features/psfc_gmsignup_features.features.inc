<?php
/**
 * @file
 * psfc_gmsignup_features.features.inc
 */

/**
 * Implements hook_views_api().
 */
function psfc_gmsignup_features_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function psfc_gmsignup_features_node_info() {
  $items = array(
    'general_meeting' => array(
      'name' => t('General Meeting'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'general_meeting_attendee' => array(
      'name' => t('General Meeting Attendee'),
      'base' => 'node_content',
      'description' => t('member attending GM'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
