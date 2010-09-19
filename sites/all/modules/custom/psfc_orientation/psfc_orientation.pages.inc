<?php
/**
 * @file PSFC Orientation module additional attendees form related functions
 */

/**
 * Additional attendees form.
 *
 * @param $form_state
 *
 * @return The form array.
 */
function psfc_orientation_additional_attendees_form(&$form_state) {

  // If there is no orientation nid, we're in the wrong place, send back to
  // choose again.
  if (!isset($_SESSION['psfc_orientation']['onid'])) {
    drupal_goto('orientations');
  }

  $form = array();
  $values = &$form_state['post'];

  if (!$form_state['storage']['step']) {
    $form_state['storage']['step'] = 1;
  }

  $form_state['values'] = $form_state['storage']['values'];

  if ($form_state['storage']['step'] == 1) {
     $form['attendee_info'] = array(
       '#value' => 'We will probably load a node here for the instructions',
       '#prefix' => '<div>',
       '#suffix' => '</div>',
    );
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
     $form['attendee_email_info'] = array(
      '#value' => 'We will probably load a node here for info about shared email',
       '#prefix' => '<div>',
       '#suffix' => '</div>',
    );
     
   $form['proceed'] = array('#type' => 'submit', '#value' => t('Do Not Add Attendees'));

   $form['proceed_add'] = array('#type' => 'submit', '#value' => t('Add Attendees'));
  }
  if ($form_state['storage']['step'] == 2) {
    $form['confirm_info'] = array(
       '#value' => 'We will display orientation time and any addl attendees here',
       '#prefix' => '<div>',
       '#suffix' => '</div>',
    );
    drupal_set_title(t('Review the Details of Your Orientation Session'));
    $form['submit'] = array('#type' => 'submit', '#value' => t('Register for this Orientation'));
    $form['#redirect'] = 'orientations';

  }
  return $form;
}

/**
 * Additional attendees form validation.
 *
 * @param $form_state
 *
 * @param $form
 *
 */
function psfc_orientation_additional_attendees_form_validate($form, &$form_state) {
  // We only need extra validation if we're on step 1 and if user clicked to
  // add additional attendees.
  if ($form_state['storage']['step'] == 1 && $form_state['clicked_button']['#id'] == 'edit-proceed_add') {
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
    
    // @todo What do we want to do if the account already exists?
    if (pfsc_orientation_check_email($values['email_1'])) {
      form_set_error('email_1', t('The email address for attendee 1 has an account already.'));
    }
    if (pfsc_orientation_check_email($values['email_2'])) {
      form_set_error('email_2', t('The email address for attendee 2 has an account already.'));
    }
    if ($values['email_2'] == $values['email_1'] && $values['email_1'] != '') {
      form_set_error('email_1', t('Each attendee must have a unique email address.'));
    }
  }
}

/**
 * Additional attendees form submit.
 *
 * @param $form_state
 *
 * @param $form
 *
 */
function psfc_orientation_additional_attendees_form_submit($form, &$form_state) {
  if (!$form_state['storage']['values']) {
    $form_state['storage']['values'] = array();
  }
  if ($form_state['clicked_button']['#id'] == 'edit-proceed') {
    $form_state['storage']['step'] = 2;
    $form_state['storage']['values'] = $form_state['values'] + $form_state['storage']['values'];
    return;
  }

  if ($form_state['clicked_button']['#id'] == 'edit-submit') {
    $form_state['values'] += $form_state['storage']['values'];
    $from = variable_get('site_mail', ini_get('sendmail_from'));
    $onid = $_SESSION['psfc_orientation']['onid'];

    // Create the attendee node for the logged in user, if not already registered
    // and there is space.
    global $user;
    if (psfc_orientation_registered($user->uid) ) {
      if (psfc_orientation_attendees($onid, TRUE) >= 1) {
        profile_load_profile($user);
        psfc_orientation_node_build_attendee($user, $onid, 1);

        // Create the attendee nodes for any additiona users.
        // Let's do this as a while loop so we can easily expand the number of addl
        // attendees if we need to.
        $i = 1;
        // Is there still a spot open?
        while ($form_state['values']['first_name_'. $i] != '') {
          if (psfc_orientation_attendees($onid, TRUE) >= 1 ) {
            $username = $form_state['values']['first_name_'. $i] .'.'. $form_state['values']['last_name_'. $i];
            $username = pfsc_orientation_check_username($username);

            $user_data = array(
              'mail' => $form_state['values']['email_'. $i],
              'name' => $username,
              'pass' => user_password(),
              'roles' => array(),
              'status' => 1,
              'profile_firstname' => $form_state['values']['first_name_'. $i],
              'profile_lastname' => $form_state['values']['last_name_'. $i],
            );

            // We need to set the categor to 'name so our name fields get saved.
           $account = user_save('', $user_data, 'name');

          // Terminate if an error occured during user_save().
          if (!$account) {
            drupal_set_message(t("Error saving user account."), 'error');
            $form_state['redirect'] = '';
            return;
          }

          watchdog('user', 'New user: %name (%email).', array('%name' => $name, '%email' => $mail), WATCHDOG_NOTICE, l(t('edit'), 'user/'. $account->uid .'/edit'));
     //     This is the default drupal message. We probably don't need it.
     //          drupal_set_message(t('Password and further instructions have been e-mailed to the new user <a href="@url">%name</a>.', array('@url' => url("user/$account->uid"), '%name' => $account->name)));

          // Create the attendee node for the additional attendee.
          psfc_orientation_node_build_attendee($account, $onid);
        }
        // No more spots open for at least one attendee.
        else {
          drupal_set_message(t('Oops! We just ran out of spots and were not able to register @name for this orientation.', array('@name' => $form_state['values']['first_name_'. $i] .' '. $form_state['values']['last_name_'. $i] )));
        }
        $i++;
        }
      }
      // No more spots open!
      else {
        drupal_set_message(t('Oops! We just ran out of spots and were not able to register you for this orientation. Please try again.'));
      }
    }
    // Already registered!
    else {
      drupal_set_message(t('Sorry, you are alredy registered for a future orientation. To switch sessions you must first cancel your existing registration.'));
    }
  $form_state['rebuild'] = '';
  unset($form_state['storage']);
  }
}

/**
 * Check for unique user name.
 *
 * @param $name
 *   The user name
 *
 * @return A unique user name.
 */
function pfsc_orientation_check_username($name) {
  if (db_result(db_query("SELECT COUNT(*) FROM {users} WHERE LOWER(name) = LOWER('%s') AND uid <> 0", $name))) {
    // Username is unse. Try again with a random 2 digit number appended.
    $name .= rand(10, 99);
    pfsc_orientation_check_username($name);
  }
  return $name;
}

/**
 * Check if email is associated with existing account.
 *
 * @param $email
 *   The email address to check
 *
 * @return The number of times the email address is in use. (Should be 1 or 0.)
 */

function pfsc_orientation_check_email($email) {
  return db_result(db_query("SELECT COUNT(*) FROM {users} WHERE LOWER(mail) = LOWER('%s') AND uid <> 0", $email));
}