<?php
function psfc_orientation_additional_attendees_form(&$form_state) {
  $form = array();
  $values = &$form_state['post'];
  $form['additional_attendee_1'] = array(
    '#type' => 'fieldset',
    '#title' => t('Additional Attendee 1'),
    '#weight' => 5,
    '#collapsible' => FALSE,
    '#weight' => -2,
  );
  $form['additional_attendee_1']['first_name_1'] = array(
    '#type' => 'textfield',
    '#title' => t('First Name'),
    '#size' => 30,
    '#maxlength' => 128,
    '#default_value' =>  (filter_xss($values['first_name_1'])) ? $values['first_name_1'] : '',
  );
  $form['additional_attendee_1']['last_name_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Last Name'),
    '#size' => 30,
    '#maxlength' => 128,
    '#default_value' =>  (filter_xss($values['last_name_1'])) ? $values['last_name_1'] : '',
  );
  $form['additional_attendee_1']['email_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#size' => 30,
    '#maxlength' => 128,
    '#default_value' =>  (filter_xss($values['email_1'])) ? $values['email_1'] : '',
  );
  $form['additional_attendee_2'] = array(
    '#type' => 'fieldset',
    '#title' => t('Additional Attendee 2'),
    '#weight' => 5,
    '#collapsible' => FALSE,
    '#weight' => -1,
  );
  $form['additional_attendee_2']['first_name_2'] = array(
    '#type' => 'textfield',
    '#title' => t('First Name'),
    '#size' => 30,
    '#maxlength' => 128,
    '#default_value' =>  (filter_xss($values['first_name_2'])) ? $values['first_name_2'] : '',
  );
  $form['additional_attendee_2']['last_name_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Last Name'),
    '#size' => 30,
    '#maxlength' => 128,
    '#default_value' =>  (filter_xss($values['last_name_2'])) ? $values['last_name_2'] : '',

  );
  $form['additional_attendee_2']['email_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#size' => 30,
    '#maxlength' => 128,
    '#default_value' =>  (filter_xss($values['email_2'])) ? $values['email_2'] : '',
  );

 $form['submit'] = array('#type' => 'submit', '#value' => t('Proceed'));
  return $form;
}

function psfc_orientation_additional_attendees_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  if ($values['first_name_1'] != '') {
    if (!drupal_validate_utf8($values['first_name_1'])) {
      form_set_error('first_name_1', t('Invalid first name entry.'));
    }
    if (!$values['last_name_1']) {
      form_set_error('last_name_1', t('You must provide a last name for your first attendee.'));
    }
    if (!$values['email_1']) {
      form_set_error('email_1', t('You must provide a valid email address for your first attendee'));
    }
  }

  if ($values['last_name_1']  != '') {
    if (!drupal_validate_utf8($values['last_name_1'])) {
      form_set_error('last_name_1', t('Invalid last name entry.'));
    }
    if (!$values['first_name_1']) {
      form_set_error('first_name_1', t('You must provide a first name for your first attedee.'));
    }
    if (!$values['email_1']) {
      form_set_error('email_1', t('You must provide a valid email address for your first attendee'));
    }
  }

  if ($values['email_1'] != '') {
    if (!valid_email_address($values['email_1'])) {
      form_set_error('email_1', t('You must provide a valid email address for your first attendee'));
    }
  }

  if ($values['first_name_2'] != '') {
    if (!drupal_validate_utf8($values['first_name_2'])) {
      form_set_error('first_name_2', t('Invalid first name entry.'));
    }
    if (!$values['last_name_2']) {
      form_set_error('last_name_2', t('You must provide a last name for your second attendee.'));
    }
    if (!$values['email_2']) {
      form_set_error('email_2', t('You must provide a valid email address for your second attendee'));
    }
  }

  if ($values['last_name_2']  != '') {
    if (!drupal_validate_utf8($values['last_name_2'])) {
      form_set_error('last_name_2', t('Invalid last name entry.'));
    }
    if (!$values['first_name_2']) {
      form_set_error('first_name_2', t('You must provide a first name for your second attendee.'));
    }
    if (!$values['email_2']) {
      form_set_error('email_2', t('You must provide a valid email address for your second attendee'));
    }
  }

  if ($values['email_2'] != '') {
    if (!valid_email_address($values['email_2'])) {
      form_set_error('email_2', t('You must provide a valid email address for your seconde attendee.'));
    }
  }

}
