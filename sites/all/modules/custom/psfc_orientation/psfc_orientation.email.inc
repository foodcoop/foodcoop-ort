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
  $options = array();
  if(!is_null($langcode)) {
    $options['langcode'] = $langcode;
  }
  if ($admin_setting = variable_get('psfc_orientation_mail_'. $key, FALSE)) {
    // An admin setting overrides the default string.
    return strtr($admin_setting, $variables);
  }
  else {
    // No override, return default string.
    switch ($key) {
      case 'registration_not_confirmed_subject':
        return t('Please confirm: Park Slope Food Coop New Member Orientation', $variables, $options);
      case 'registration_not_confirmed_body':
        $ret = <<<EOT
Dear !attendee_firstname !attendee_lastname,

Thank you for interest in attending a New Member Orientation at the Park Slope Food Coop. You have selected the following Session:

!orientation_date

In order to complete your registration and secure your seat, please click on the "confirm" link below within 48 hours. After 48 hours, any un-confirmed registrations will be cancelled and those seats will be released.

CLICK TO CONFIRM:
!confirm_link

CLICK TO CANCEL:
!cancel_link

Please also take a moment to read the following important information:

 * In order to join the Coop you (and all housemates) will first need to present in person two forms of ID -- one photo ID and one proof of address. (Acceptable forms of proof are listed in the "Provide Proof of ID and Address" section of the website.)

 * You will be asked to present your proof of ID while checking into the Orientation room.

 * If you live with other adults who have not yet attended an Orientation, they are welcome to attend this orientation with you. Remember that they will need to present their own proof of ID and Address to complete the joining process.

 * Your shopping privileges being the day after your household completes the joining process.

 * Arrive on time. The Orientation begins promptly and lasts approximately two hours. Latecomers will not be admitted.

 * If you will be unable to attend the Orientation, please log in to your "Orientation Status" page and cancel your registration, even if it’s only an hour or two before the Session. Seats are sought after, and someone will appreciate the opening.

Click on the link above to complete your registration. We look forward to seeing you soon!

- The Park Slope Food Coop

Please DO NOT REPLY to this email. If you have any questions or need assistance, contact the Coop Membership Office at 718-622-0560.
EOT;
        return strtr($ret, $variables);
      case 'registration_reminder_subject':
        return t('Park Slope Food Coop New Member Orientation', $variables, $options);
      case 'registration_reminder_body':
        $ret = <<<EOT
Dear !attendee_firstname !attendee_lastname

This is a reminder that you are registered for a Park Slope Food Coop New Member Orientation on !orientation_date.

There are four things we REALLY want you to know:

    * You will be asked to present proof of ID while checking into the Orientation room.

    * To join the Coop you, and all your housemates, must present photo ID and proof of address in person. (Acceptable forms of proof are listed on foodcoop.com in the “Join the Coop” section.)

    * If you live with other adults who have not yet attended an Orientation, they are welcome to attend this orientation with you. Remember that they will need to present their own proof of ID and Address to complete the joining process.

    * Your shopping privileges will begin the day after your household completes the joining process.

If you will be unable to attend please <strong> !cancel_link cancel your registration</strong>, so that someone else can attend in your place.

Thank you. We look forward to seeing you soon!

- The Park Slope Food Coop

Please DO NOT REPLY to this email. If you have any questions or need assistance, contact the Coop Membership Office at 718-622-0560.
EOT;
        return strtr($ret, $variables);
      case 'registration_cancelled_subject':
        return t('Your PSFC orientation has been cancelled.', $variables, $options);
      case 'registration_cancelled_body':
        return t("Dear !attendee_firstname !attendee_lastname\n\nYou have successfully cancelled your new member orientation on !orientation_date.\n\n Thank you,\nThe Park Slope Food Coop", $variables, $options);
      case 'confirmation_window_missed_subject':
        return t('You failed to confirm your PSFC orientation.', $variables, $options);
      case 'confirmation_window_missed_body':
        return t("Dear !attendee_firstname !attendee_lastname\n\nYour PSFC new member orientation reservation has been cancelled because you did not confirm.\n\n Thank you,\nThe Park Slope Food Coop", $variables, $options);
      case 'registration_coop_cancelled_subject':
        return t('Notice: Your PSFC orientation has been cancelled.', $variables, $options);
      case 'registration_coop_cancelled_body':
        return t("Dear !attendee_firstname !attendee_lastname\n\n\n\nUnfortunately, the Orientation that you were scheduled to attend on !orientation_date has been cancelled by the PSFC. We apologize for the inconvenience. Because the cancellation was at the Coop's request, we will expedite your placement in the earliest possible upcoming Orientation session that suits your schedule. For assistance re-registering, please contact the PSFC Membership Office at 718-622-0560.\n\n\n\nApologies,\n\nThe Park Slope Food Coop\n\n\n\n\n\nPlease DO NOT REPLY to this email. If you have any questions or need assistance contact the Coop Membership Office at 718-622-0560", $variables, $options);
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

  $attendance_wrapper = entity_metadata_wrapper('node', $node);
  $orientation_node = $attendance_wrapper->field_orientation_nid->value();
  $orientation_wrapper= entity_metadata_wrapper('node', $orientation_node);
  $account =  $attendance_wrapper->field_user_id->value();
  $tokens = array(
    '!attendee_firstname' => $attendance_wrapper->field_first_name->value(),
    '!attendee_lastname' => $attendance_wrapper->field_last_name->value(),
    '!attendee_email' => $attendance_wrapper->field_email->value(),
    '!attendee_confirmed_status' => $attendance_wrapper->field_confirmed_orientation->value() ? t('Confirmed') : t('Not confirmed'),
    '!orientation_description' => $orientation_wrapper->body->value(),
    '!orientation_date' => format_date($orientation_wrapper->field_orientation_date->value(), 'medium'),
    '!orientation_date_short' => format_date($orientation_wrapper->field_orientation_date->value(), 'short'),
    '!orientation_link' => l($orientation_wrapper->title->value(), $orientation_wrapper->url->value()),
    '!registered_on_date' => $attendance_wrapper->created->value(),
    '!registerer' => $attendance_wrapper->title->value(),
    '!site' => variable_get('site_name', 'Drupal'),
    '!confirm_link' => psfc_orientation_confirm_url($account, 'confirm', '', FALSE),
    '!cancel_link' => psfc_orientation_confirm_url($account, 'cancel', '', FALSE),
    '!uri' => $base_url,
    '!uri_brief' => preg_replace('!^https?://!', '', $base_url),
    '!login_uri' => url('user', array('absolute' => TRUE, 'language' => $language)),
  );
  return $tokens;
}

/**
 * Send orientaion reminder emails.
 */
function psfc_orientation_send_reminders() {
  $time = (2 * 24 * 60 * 60); // 2 days

	// Get all orientation nodes where email reminders haven't been sent and
  // orientation date within 2 days.
  $result = db_query("SELECT DISTINCT date.entity_id FROM field_data_field_orientation_date date
    JOIN field_data_field_orientation_reminder reminder USING(entity_id)
    WHERE date.bundle = 'orientation' AND reminder.field_orientation_reminder_value = 0
    AND (UNIX_TIMESTAMP(date.field_orientation_date_value) - UNIX_TIMESTAMP()) < :date 
    AND UNIX_TIMESTAMP(date.field_orientation_date_value) > UNIX_TIMESTAMP();", array(':date' => $time));

  while($oid = $result->fetchField()) {
    // Load orienation node.
    $node = node_load($oid);
    $node_wrapper= entity_metadata_wrapper('node', $node);
    //Send emails
    $attendees = psfc_orientation_get_all_attendee_nodes($oid);
    if (count($attendees)) {
      foreach ($attendees as $attendee) {
        $attendee_wrapper = entity_metadata_wrapper('node', $attendee);
        $confirmed = $attendee_wrapper->field_confirmed_orientation->value();
        if ($confirmed == 1) {
          $uid = $attendee_wrapper->field_user_id->value()->uid;
          $account = user_load($uid);
          $recipient = $account->mail;
          // We only need the node params. The confirm and cancel links are added
          // in nodeapi.
          $params['node'] = $attendee;

          drupal_mail('psfc_orientation', 'registration_reminder', $recipient, language_default(), $params);

          // XXX: adding additional watchdog for purposes of testing
	  	    watchdog('psfc_orientation', "Mailing ".$recipient, array('@title' => $node->title),WATCHDOG_NOTICE);
        }
      }
      // Mark as emails sent only if we actually sent any.
      $node_wrapper->field_orientation_reminder->set(1);
      $node_wrapper->save();
      watchdog('psfc_orientation', 'Email reminders sent for: @title', array('@title' => $node->title), WATCHDOG_NOTICE);
    }
  }
}
