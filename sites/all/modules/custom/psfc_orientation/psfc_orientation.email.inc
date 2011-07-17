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
        return t("Dear !username\n\nYou have been registered for you for orientation. Please confirm.", $variables, $langcode);
      case 'registration_reminder_subject':
        return t('Reminder: Your PSFC orientation is coming up.', $variables, $langcode);
      case 'registration_reminder_body':
        return t("Dear !username\n\nYou are registered to attend a PSFC new member orientation.", $variables, $langcode);
      case 'registration_cancelled_subject':
        return t('Reminder: Your PSFC orientation has been cancelled.', $variables, $langcode);
      case 'registration_cancelled_body':
        return t("Dear !attendee_firstname !attendee_lastname\n\nYour scheduled PSFC new member orientation has been cancelled.\n\n Thank you,\nThe Park Slope Food Coop", $variables, $langcode);
      case 'confirmation_window_missed_subject':
        return t('You failed to confirm your PSFC orientation.', $variables, $langcode);
      case 'confirmation_window_missed_body':           
        return t("Dear !attendee_firstname !attendee_lastname\n\nYour PSFC new member orientation reservation has been cancelled because you did not confirm.\n\n Thank you,\nThe Park Slope Food Coop", $variables, $langcode);
      case 'registration_coop_cancelled_subject':
        return t('Notice: Your PSFC orientation has been cancelled.', $variables, $langcode);
      case 'registration_coop_cancelled_body':
        return t("Dear !attendee_firstname !attendee_lastname\n\n\n\nUnfortunately, the Orientation that you were scheduled to attend on !orientation_date has been cancelled by the PSFC. We apologize for the inconvenience. Because the cancellation was at the Coop's request, we will expedite your placement in the earliest possible upcoming Orientation session that suits your schedule. For assistance re-registering, please contact the PSFC Membership Office at 718-622-0560.\n\n\n\nApologies,\n\nThe Park Slope Food Coop\n\n\n\n\n\nPlease DO NOT REPLY to this email. If you have any questions or need assistance contact the Coop Membership Office at 718-622-0560", $variables, $langcode);
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
  $email_token_help = t('Available variables are: ') .'!attendee_firstname, !attendee_lastname, !attendee_email, !attendee_confirmed_status, !orientation_description, !orientation_date, !orientation_date_short, !orientation_link, !confirm_link, !cancel_link, !registered_on_date, !registerer, !site, !uri, !uri_brief, !login_uri';

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
    '#description' => t('Reminder to registrants who cancelled their orientation themselves') .' '. $email_token_help,
  );
  $form['email']['registration_cancelled']['psfc_orientation_mail_registration_cancelled_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => _psfc_orientation_mail_text('registration_cancelled_subject'),
    '#maxlength' => 180,
  );
  $form['email']['registration_cancelled']['psfc_orientation_mail_registration_cancelled_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#default_value' => _psfc_orientation_mail_text('registration_cancelled_body'),
    '#rows' => 15,
  );

  $form['email']['registration_unconfirmed'] = array(
    '#type' => 'fieldset',
    '#title' => t('Registration not confirmed'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => t('Email to registrants who did not confirm their orientation') .' '. $email_token_help,
  );
  $form['email']['registration_unconfirmed']['psfc_orientation_mail_confirmation_window_missed_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => _psfc_orientation_mail_text('confirmation_window_missed_subject'),
    '#maxlength' => 180,
  );
  $form['email']['registration_unconfirmed']['psfc_orientation_mail_confirmation_window_missed_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#default_value' => _psfc_orientation_mail_text('confirmation_window_missed_body'),
    '#rows' => 15,
  );
  
  
  $form['email']['registration_coop_cancelled'] = array(
    '#type' => 'fieldset',
    '#title' => t('Registration cancelled by the coop'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => t('Notify registrants that their orientation session has been cancelled by the coop') .' '. $email_token_help,
  );
  $form['email']['registration_coop_cancelled']['psfc_orientation_mail_registration_coop_cancelled_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => _psfc_orientation_mail_text('registration_coop_cancelled_subject'),
    '#maxlength' => 180,
  );
  $form['email']['registration_coop_cancelled']['psfc_orientation_mail_registration_coop_cancelled_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#default_value' => _psfc_orientation_mail_text('registration_coop_cancelled_body'),
    '#rows' => 15,
  );
  return system_settings_form($form);
}


function psfc_orientation_mail_tokens($node, $language) {
  global $base_url;
  $orientation = node_load($node->field_orientation_nid[0]['nid']);
  // Get our timezone offset. This should account for daylight savings. The
  // offset is applied using format_date() below.
  $offset = date_offset_get(new DateTime);
  // Set runtime TZ to UTC.
  date_default_timezone_set($orientation->field_date[0]['timezone_db']);
  $tokens = array(
    '!attendee_firstname' => $node->field_firstname[0]['value'],
    '!attendee_lastname' => $node->field_lastname[0]['value'],
    '!attendee_email' => $node->field_email[0]['email'],
    '!attendee_confirmed_status' => $node->field_attendee_confirmed[0]['value'] ? t('Confirmed') : t('Not confirmed'),
    '!orientation_description' => $orientation->body,
    '!orientation_date' => format_date(strtotime($orientation->field_date[0]['value']), 'large', '', $offset),
    '!orientation_date_short' => format_date(strtotime($orientation->field_date[0]['value']), 'small', '', $offset),
    '!orientation_link' => l($orientation->title, $orientation->path),
    '!registered_on_date' => format_date($node->timestamp, 'medium', '', $offset, $language->language),
    '!registerer' => $node->name,
    '!confirm_link' => $node->confirm,
    '!cancel_link' => $node->cancel,
    '!site' => variable_get('site_name', 'Drupal'),
    '!uri' => $base_url,
    '!uri_brief' => preg_replace('!^https?://!', '', $base_url),
    '!login_uri' => url('user', array('absolute' => TRUE, 'language' => $language)),
  );
// Set runtime TZ back to NY.
  date_default_timezone_set('America/New_York');
  return $tokens;
}

/**
 * Send orientaion reminder emails.
 */
function psfc_orientation_send_reminders() {
  $time = (2 * 24 * 60 * 60); // 2 days
  
	// Get all orientation nodes where email reminders haven't been sent and 
  // orientation date within 2 days.
  $result = db_query("SELECT o.nid from {node} n LEFT JOIN {content_type_orientation} o ON n.nid = o.nid
    WHERE n.type = 'orientation' AND o.field_reminders_value = 0 AND (UNIX_TIMESTAMP(o.field_date_value) - UNIX_TIMESTAMP()) < %d", $time);

  while ($oid = db_result($result)) {
    // Load orienation node.
    $node = node_load($oid);

    //Send emails
    $attendees = psfc_orientation_get_all_attendee_nodes($node->nid);
    if (count($attendees)) {
      foreach ($attendees as $attendee) {
        $account = user_load($attendee->field_userid[0]['uid']);
        $recipient = $account->mail;

        // We only need the node params. The confirm and cancel links are added
        // in nodeapi.
        $params['node'] = $attendee;

        drupal_mail('psfc_orientation', 'registration_reminder', $recipient, language_default(), $params);
        
        // XXX: adding additional watchdog for purposes of testing
		watchdog('psfc_orientation', "Mailing ".$recipient, array('@title' => $node->title),WATCHDOG_NOTICE);
      }
      // Mark as emails sent only if we actually sent any.
      $node->field_reminders[0]['value'] = 1;
      node_save($node);
      watchdog('psfc_orientation', 'Email reminders sent for: @title', array('@title' => $node->title), WATCHDOG_NOTICE);
    }
  }
}