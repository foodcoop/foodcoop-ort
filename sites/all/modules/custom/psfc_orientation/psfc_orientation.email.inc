<?php
/**
 * @file Email functions for PSFC Orientation module.
 */

function psfc_orientation_mail($key, &$message, $params) {
  $language = $message['language'];
  $variables = psfc_orientation_mail_tokens($params['node'], $language);
  $message['subject'] = _psfc_orientation_mail_text($key .'_subject', $language, $variables);
  $message['body'][] = _psfc_orientation_mail_text($key .'_body', $language, $variables);
}

function _psfc_orientation_mail_text($key, $language = NULL, $variables = array()) {
  $langcode = isset($language) ? $language->language : NULL;
  if ($admin_setting = variable_get('psfc_orientation_mail_'. $key, FALSE)) {
    // An admin setting overrides the default string.
    return strtr($admin_setting, $variables);
  }
  else {
    // No override, return default string.
    switch ($key) {
      case 'registration_confirmed_subject':
        return t('Orientation confirmation from !site', $variables, $langcode);
      case 'registration_confirmed_body':
        return t("Dear !username\n\nYou have registered for orientation.", $variables, $langcode);
      case 'registration_not_confirmed_subject':
        return t('Please confirm your orientation !site', $variables, $langcode);
      case 'registration_not_confirmed_body':
        return t("Dear !username\n\nsomeone registered for you for orientation. Please confirm.", $variables, $langcode);
      case 'registration_reminder_subject':
        return t('Reminder: Your PSFC orientation is coming up.', $variables, $langcode);
      case 'registration_reminder_body':
        return t("Dear !username\n\nYou are confirmed to attend a PSFC new member orientation.", $variables, $langcode);
      case 'registration_cancelled_subject':
        return t('Reminder: Your PSFC orientation has been cancelled.', $variables, $langcode);
      case 'registration_cancelled_body':
        return t("Dear !username\n\nYour scheduled PSFC new member orientation has been cancelled.", $variables, $langcode);
    }
  }
}

function psfc_orientation_mail_settings() {

  // E-mail settings.
  $form['email'] = array(
    '#type' => 'fieldset',
    '#title' => t('Orientation e-mail settings'),
    '#description' => t('The orientation module sends emails to ocmmunicate with people who register for orientations. These e-mails can be customized using the forms below.'),
  );
  // These email tokens are shared for all settings, so just define
  // the list once to help ensure they stay in sync.
  $email_token_help = t('Available variables are: ') .'!attendee_firstname, !attendee_lastname, !attendee_email, !attendee_confirmed_status, !orientation_description, !orientation_date, !orientation_link, !registered_on_date, !registerer, !site, !uri, !uri_brief, !login_uri';

  $form['email']['registration_confirmed'] = array(
    '#type' => 'fieldset',
    '#title' => t('Registration confirmed'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => t('When self-registering, or when a Coop admin registers someone for an orientation, it is not necessary to confirm.') .' '. $email_token_help,
  );
  $form['email']['registration_confirmed']['psfc_orientation_mail_registration_confirmed_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => _psfc_orientation_mail_text('registration_confirmed_subject'),
    '#maxlength' => 180,
  );
  $form['email']['registration_confirmed']['psfc_orientation_mail_registration_confirmed_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#default_value' => _psfc_orientation_mail_text('registration_confirmed_body'),
    '#rows' => 15,
  );
  $form['email']['registration_not_confirmed'] = array(
    '#type' => 'fieldset',
    '#title' => t('Registration not confirmed'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => t('When a person is registered for orientation by someone else (not a coop admin) it is necessary to confirm.') .' '. $email_token_help,
  );
  $form['email']['registration_not_confirmed']['psfc_orientation_mail_registration_not_confirmed_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => _psfc_orientation_mail_text('registration_not_confirmed_subject'),
    '#maxlength' => 180,
  );
  $form['email']['registration_not_confirmed']['psfc_orientation_mail_registration_not_confirmed_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#default_value' => _psfc_orientation_mail_text('registration_not_confirmed_body'),
    '#rows' => 15,
  );
  $form['email']['registration_reminder'] = array(
    '#type' => 'fieldset',
    '#title' => t('Upcoming orientation reminder'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => t('Notifies registrants that the orientation is soon.') .' '. $email_token_help,
  );
  $form['email']['registration_reminder']['psfc_orientation_mail_registration_reminder_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => _psfc_orientation_mail_text('registration_reminder_subject'),
    '#maxlength' => 180,
  );
  $form['email']['registration_reminder']['psfc_orientation_mail_registration_reminder_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#default_value' => _psfc_orientation_mail_text('registration_reminder_body'),
    '#rows' => 15,
  );
  $form['email']['registration_cancelled'] = array(
    '#type' => 'fieldset',
    '#title' => t('Registration cancelled'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => t('Notify registrants that their orientation session has been cancelled') .' '. $email_token_help,
  );
  $form['email']['registration_cancelled']['psfc_orientation_mail_registration_cancelled_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => _psfc_orientation_mail_text('registration_cancelled_subject'),
    '#maxlength' => 180,
  );
  $form['email']['registration_cancelled']['psfc_orientation_mail_registration_canceled_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#default_value' => _psfc_orientation_mail_text('registration_cancelled_body'),
    '#rows' => 15,
  );
  return system_settings_form($form);
}


function psfc_orientation_mail_tokens($node, $language) {
  global $base_url;
  $orientation = node_load($node->field_orientation_nid[0]['nid']);
  $tokens = array(
    '!attendee_firstname' => $node->field_firstname[0]['value'],
    '!attendee_lastname' => $node->field_lastname[0]['value'],
    '!attendee_email' => $node->field_email[0]['email'],
    '!attendee_confirmed_status' => $node->field_attendee_confirmed[0]['value'] ? t('Confirmed') : t('Not confirmed'),
    '!orientation_description' => $orientation->body,
    '!orientation_date' => $orientation->field_date[0]['value'],
    '!orientation_link' => l($orientation->title, $orientation->path),
    '!registered_on_date' => format_date($node->timestamp, 'medium', '', NULL, $language->language),
    '!registerer' => $node->name,
    '!site' => variable_get('site_name', 'Drupal'),
    '!uri' => $base_url,
    '!uri_brief' => preg_replace('!^https?://!', '', $base_url),
    '!login_uri' => url('user', array('absolute' => TRUE, 'language' => $language)),
  );
  return $tokens;
}
