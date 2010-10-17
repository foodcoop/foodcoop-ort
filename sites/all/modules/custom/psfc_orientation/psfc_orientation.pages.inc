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
  $attendee_info = node_load(variable_get('psfc_orientation_add_additional_instructions', 39));
  unset($attendee_info->title);
  $attendee_info_view = node_view($attendee_info);

  $attendee_email = node_load(variable_get('psfc_orientation_add_additional_email', 45));
  unset($attendee_email->title);
  $attendee_email_view = node_view($attendee_email);

  $form = array();
  $values = &$form_state['post'];

  if (!$form_state['storage']['step']) {
    $form_state['storage']['step'] = 1;
  }

  $form_state['values'] = $form_state['storage']['values'];

  if ($form_state['storage']['step'] == 1) {
     $form['attendee_info'] = array(
       '#value' => $attendee_info_view,
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
      '#value' => $attendee_email_view,
       '#prefix' => '<div>',
       '#suffix' => '</div>',
    );

   $form['proceed'] = array('#type' => 'submit', '#value' => t('Do Not Add Attendees'));

   $form['proceed_add'] = array('#type' => 'submit', '#value' => t('Add Attendees'));
  }
  if ($form_state['storage']['step'] == 2) {
    drupal_set_title(t('Review the Details of Your Orientation Session'));
    global $user;
    $orientation = node_load($_SESSION['psfc_orientation']['onid']);

    $form['confirm_info_text'] = array(
       '#value' => t('You have signed up for the following Orientation Session:'),
       '#prefix' => '<div class="confirm-info-text">',
       '#suffix' => '</div>',
    );
    $form['confirm_info_date'] = array(
       '#value' => theme(psfc_orientation_date_table, $orientation->field_date[0]['value']),
       '#prefix' => '<div class="confirm-info-date">',
       '#suffix' => '</div>',
    );
    $form['confirm_info_addl_text'] = array(
       '#value' => t('You have included the following additional attendees:'),
       '#prefix' => '<div class="confirm-info-addl-text">',
       '#suffix' => '</div>',
    );
    $form['confirm_info_addl_attendees'] = array(
       '#value' => theme('psfc_orientation_additional_attendees', psfc_orientation_parse_additional($form_state)),
       '#prefix' => '<div class="confirm-info-addl-text">',
       '#suffix' => '</div>',
    );

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
  if ($form_state['storage']['step'] == 1 && $form_state['clicked_button']['#id'] == 'edit-proceed-add') {
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
        form_set_error('email_2', t('You must provide a valid email address for your second attendee.'));
      }
    }

    if (psfc_orientation_check_email($values['email_1'])) {
      form_set_error('email_1', t('The email address for attendee 1 has an account already. This person must self-register.'));
    }
    if (psfc_orientation_check_email($values['email_2'])) {
      form_set_error('email_2', t('The email address for attendee 2 has an account already. This person must self-register.'));
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
  if ($form_state['clicked_button']['#id'] == 'edit-proceed' || $form_state['clicked_button']['#id'] == 'edit-proceed-add') {
    $form_state['storage']['step'] = 2;
    $form_state['storage']['values'] = $form_state['values'] + $form_state['storage']['values'];
    return;
  }

  if ($form_state['clicked_button']['#id'] == 'edit-submit') {
    $form_state['values'] += $form_state['storage']['values'];
    $from = variable_get('site_mail', ini_get('sendmail_from'));
    $onid = $_SESSION['psfc_orientation']['onid'];

    $users_array = psfc_orientation_parse_additional($form_state);
    $users_count = count($users_array);

    // Create the attendee node for the logged in user, if not already registered
    // and there is space. We already check if user is registered, but let's do
    // it again just in case they open 2 browsers or something.
    global $user;
    if (!psfc_orientation_registered($user->uid) ) {
      if (psfc_orientation_capacity($onid, TRUE) >= 1) {
        profile_load_profile($user);
        $registerer = psfc_orientation_node_build_attendee($user, $onid);

        // Create the attendee nodes for any additional users.
        // Let's do this as a loop so we can easily expand the number of addl
        // attendees if we need to.
        // Are enough spots available?

        if (psfc_orientation_capacity($onid, TRUE) >= $users_count) {
          foreach ($users_array as $addl_user) {
            $username = $addl_user['first_name'] .'.'. $addl_user['last_name'];
            $username = psfc_orientation_check_username($username);

            $user_data = array(
              'mail' => $addl_user['email'],
              'name' => $username,
              'pass' => user_password(),
              'roles' => array(),
              'status' => 1,
              'profile_firstname' => $addl_user['first_name'],
              'profile_lastname' => $addl_user['last_name'],
            );

            // We need to set the category to 'name so our name fields get saved.
           $account = user_save('', $user_data, 'name');

          // Terminate if an error occured during user_save().
          if (!$account) {
            drupal_set_message(t("Error saving user account."), 'error');
            $form_state['redirect'] = '';
            return;
          }

          watchdog('user', 'New user: %name (%email).', array('%name' => $name, '%email' => $mail), WATCHDOG_NOTICE, l(t('edit'), 'user/'. $account->uid .'/edit'));
     //     This is the default drupal message. We probably don't need it.
     //     drupal_set_message(t('Password and further instructions have been e-mailed to the new user <a href="@url">%name</a>.', array('@url' => url("user/$account->uid"), '%name' => $account->name)));

          // Create the attendee node for the additional attendee.
          psfc_orientation_node_build_attendee($account, $onid);

          // Add a reference to the additional attendee on the resterer's attendee node.
          $registerer->field_additional_attendees[]['uid'] = $account->uid;
          node_save($registerer);
        }
      }
      // No more spots open for at least one attendee.
      else {
        drupal_goto('node/'. variable_get('psfc_orientation_no_additional_attendees', ''));
      }
    }
    // No more spots open for logged in user!
    else {
      drupal_goto('node/'. variable_get('psfc_orientation_orientation_filled', ''));
    }
  }
  // Already registered!
  else {
    drupal_set_message(t('Sorry, you are already registered for a future orientation. To switch sessions you must first cancel your existing registration.'));
  }
  $form_state['rebuild'] = '';
  unset($form_state['storage']);
  // Logged in user is registered.
  drupal_goto('node/'. variable_get('psfc_orientation_confirm_orientation_page', ''));
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
function psfc_orientation_check_username($name) {
  if (db_result(db_query("SELECT COUNT(*) FROM {users} WHERE LOWER(name) = LOWER('%s') AND uid <> 0", $name))) {
    // Username is unse. Try again with a random 2 digit number appended.
    $name .= rand(10, 99);
    psfc_orientation_check_username($name);
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

function psfc_orientation_check_email($email) {
  if ($email == '') {
    return FALSE;
  }
  return db_result(db_query("SELECT COUNT(*) FROM {users} WHERE LOWER(mail) = LOWER('%s') AND uid <> 0", $email));
}

/**
 * Build an array of additional attendees.
 *
 * @param $form_state
 *
 * @return The array.
 */
function psfc_orientation_parse_additional($form_state) {
  if ($form_state['values']['first_name_1'] != '') {
    $users_array[1]['first_name'] = $form_state['values']['first_name_1'];
    $users_array[1]['last_name'] = $form_state['values']['last_name_1'];
    $users_array[1]['email'] = $form_state['values']['email_1'];
  }
  else {
    $users_array[1] = NULL;
  }
  if ($form_state['values']['first_name_2'] != '') {
    $users_array[2]['first_name'] = $form_state['values']['first_name_2'];
    $users_array[2]['last_name'] = $form_state['values']['last_name_2'];
    $users_array[2]['email'] = $form_state['values']['email_2'];
  }
  else {
    $users_array[2] = NULL;
  }

  return array_filter($users_array);
}