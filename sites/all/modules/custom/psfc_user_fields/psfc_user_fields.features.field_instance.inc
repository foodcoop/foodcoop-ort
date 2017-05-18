<?php
/**
 * @file
 * psfc_user_fields.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function psfc_user_fields_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_fullname-field_firstname'.
  $field_instances['field_collection_item-field_fullname-field_firstname'] = array(
    'bundle' => 'field_fullname',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_firstname',
    'label' => 'First Name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_fullname-field_lastname'.
  $field_instances['field_collection_item-field_fullname-field_lastname'] = array(
    'bundle' => 'field_fullname',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_lastname',
    'label' => 'Last Name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'user-user-field_fullname'.
  $field_instances['user-user-field_fullname'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'fences_wrapper' => 'div',
    'field_name' => 'field_fullname',
    'label' => 'Name',
    'required' => 0,
    'settings' => array(
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'user-user-field_membernumber'.
  $field_instances['user-user-field_membernumber'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'user',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_membernumber',
    'label' => 'Member number',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('First Name');
  t('Last Name');
  t('Member number');
  t('Name');

  return $field_instances;
}
