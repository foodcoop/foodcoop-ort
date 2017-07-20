<?php
/**
 * Default Administration page
 */
function psfc_orientation_admin_page() {
  drupal_add_css(drupal_get_path('module', 'psfc_orientation') . '/psfc_orientation_admin.css');
  $view_name = 'orientation_admin';
  $display_id = 'default';
  $upcoming_orientations = views_embed_view($view_name, $display_id);

  $existing_orientations = psfc_orientation_display_orientation_rules();

  $output = '<div id="psfc-admin-form">';
  $output .= $upcoming_orientations;
  $output .= '<div class="psfc-admin-two-col">';
  if (user_access('administer psfc orientation')) {
    $output .= '<div class="col-left">';
    $output .= $existing_orientations .  l('Create a new Orientation rule', 'admin/psfc/orientation/add-rule');
    $output .= '</div>';
  }
  $blackout_content = psfc_orientation_display_blackouts();
  if (user_access('administer psfc orientation')) {
    $blackout_content .= l('Create a new blackout date', 'admin/psfc/orientation/add-blackout');
  }
  $output .= '<div class="col-right">';
  $output .= $blackout_content;
  $output .= '</div>';
  $output .= '</div>';
  $output .= '</div>';
  return $output;
}

/**
 * Build a generic resuable form for dealing with orientation rules
 */
function psfc_orientation_admin_rule_form_skel($op, $orid = NULL) {
  $form = array();
  $info = NULL;
  switch ($op) {
    case 'edit':
      if (is_numeric($orid)) {
        $info = psfc_orientation_get_repeat_rule_info($orid);
        $time = psfc_orientation_split_out_time_of_day($info['time_of_day']); 
      }
      break;
  }
  $form['orid'] = array(
    '#type' => 'value',
    '#value' => (isset($info)) ? $info['orid'] : NULL,
  );
  $form['day_of_week'] = array(
    '#type' => 'select',
    '#title' => t('Day'),
    '#options' => array(
      'Sunday' => 'Sunday',
      'Monday' => 'Monday',
      'Tuesday' => 'Tuesday',
      'Wednesday' => 'Wednesday',
      'Thursday' => 'Thursday',
      'Friday' => 'Friday',
      'Saturday' => 'Saturday',
    ),
    '#required' => TRUE,
    '#default_value' => (!$info) ? NULL : $info['day_of_week'],
  );
  $form['hour'] = array(
    '#type' => 'select',
    '#title' => 'Hour',
    '#options' => array(
      '1' => 1,
      '2' => 2,
      '3' => 3,
      '4' => 4,
      '5' => 5,
      '6' => 6,
      '7' => 7,
      '8' => 8,
      '9' => 9,
      '10' => 10,
      '11' => 11,
      '12' => 12,
    ),
    '#required' => TRUE,
    '#default_value' => (isset($time)) ? $time['hour'] : NULL,
  );
  $form['min'] = array(
    '#type' => 'select',
    '#title' => 'Minute',
    '#options' => array(
      '00' => '00',
      '15' => '15',
      '30' => '30',
      '45' => '45',
    ),
    '#required' => TRUE,
    '#default_value' => (isset($time)) ? $time['minute'] : NULL,
  );
  $form['ampm'] = array(
    '#type' => 'select',
    '#title' => 'AM / PM',
    '#options' => array(
      'am' => 'AM',
      'pm' => 'PM',
    ),
    '#required' => TRUE,
    '#default_value' => (isset($time)) ? $time['ampm'] : NULL,
  );

  $form['capacity'] = array(
    '#type' => 'textfield',
    '#title' => t('Capacity'),
    '#default_value' => (isset($edit)) ? $edit[0]['capacity'] : NULL,
    '#description' => t("The total number of spaces available for this orientation."),
    '#size' => 2,
    '#maxlength' => 2,
    '#required' => TRUE,
    '#default_value' => (!$info) ? NULL : $info['capacity'],
  );
  return $form;
}



/**
 *  Builds the admin form for building  orientation rules.
 */
function psfc_orientation_admin_add_rule($form, $edit) {
  $form = psfc_orientation_admin_rule_form_skel('add');
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add'),
  );
  return $form;
}

/**
 * Helper function for creating orientation rules
 *
 * These are not formal drupal entites - they are simply stored in the
 * database. They provide the basis for the auto-creation of orientations
 * by the cron job.
 */
function psfc_orientation_add_rule($values) {
  $time = $values['hour'] . ':' . $values['min'] . ' ' . $values['ampm'];
  $id = db_insert('psfc_orientation_repeat_rules')
    ->fields(
      array(
       'day_of_week' => $values['day_of_week'],
       'time_of_day' => $time,
       'capacity' => $values['capacity'],
       ))
     ->execute();
  return $id;
}

/**
 * Submit function when admin submits new orientation rule
 **/
function psfc_orientation_admin_add_rule_submit($form, &$form_state) {
  $values = $form_state['values'];
  if ($values['submit'] == 'Add') {
    $id = psfc_orientation_add_rule($values);
    $time = $values['hour'] . ':' . $values['min'] . ' ' . $values['ampm'];
    $form_state['values']['orid'] = $id;
    drupal_set_message(t('A new orientation time has been created for %day at %time with room for %capacity people',
      array('%day' => $values['day_of_week'] . 's', '%time' => $time, '%capacity' => $values['capacity'])));
  }
  drupal_goto( 'admin/psfc/orientation');
}

/**
 * Helper function to return themed list of orientation rule presets.
 *
 * @return Returns a themed table of exisiting orientation rules
 */
function psfc_orientation_display_orientation_rules() {
  $query = db_query("SELECT * FROM {psfc_orientation_repeat_rules}");
  $rows = array();
  while ($result = $query->fetchAssoc()) {
    $orientation = t('%day at %time with room for %capacity', array('%day' => $result['day_of_week'] . 's', '%time' => $result['time_of_day'], '%capacity' => $result['capacity']));
    $rows[] = array($orientation, l('edit', 'admin/psfc/orientation/edit-rule/' . $result['orid']), l('delete', 'admin/psfc/orientation/delete-rule/' . $result['orid']));
  }

  $output = theme('table', array('header' => array(t('Existing Rules'), '', ''), 'rows' => $rows));

  return $output;
}

/**
 *  Helper function to return a themed list of orientation blackout days
 *
 * @return Returns a themed table of orientation blackout days
 */
function psfc_orientation_display_blackouts() {
  $query = db_query("SELECT * FROM {psfc_orientation_blackout_days} ORDER BY blackout_date");
  $rows = array();
  while ($result = $query->fetchAssoc()) {
    $datetime = strtotime($result['blackout_date']);
    $date = date('F j, Y', $datetime);
    if (user_access('administer psfc orientation')) {
      $rows[] = array($date, l('delete', 'admin/psfc/orientation/delete-blackout/' . $result['obid']));
    }
    else {
      $rows[] = array($date);
    }
  }
  $output = theme('table', array('header' => array(t('Upcoming Blackout Dates'), ''), 'rows' => $rows));

  return $output;

}

/**
 * Form for adding and orientation blackout date.
 */
function psfc_orientation_add_blackout($form, $form_state) {
  drupal_set_title(t('Create an Orientation black out date'));
  $form = array();
  $form['pre'] = array(
    '#type' => 'markup',
    '#value' => '<div>',
  );
  $form['obid'] = array(
    '#type' => 'value',
    '#value' => (isset($values)) ? $values['obid'] : NULL,
  );

  $format = 'Y-m-d';

  $date = date($format) . ' 00:00:00';

  $form['date'] = array(
    '#type' => 'date_select',
    '#title' => 'select a date',
    '#default_value' => (!isset($values)) ? $date : $values['date'],
    '#date_format' => $format,
    '#date_label_position' => 'within',
    '#date_year_range' => '-0:+3',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add'),
  );
  $form['suff'] = array(
    '#type' => 'markup',
    '#value' => '</div>',
  );
  return $form;
}

/**
 * Process blackout date submission.
 */
function psfc_orientation_add_blackout_submit($form, &$form_state) {
  $values = $form_state['values'];

  if ($values['submit'] == 'Add') {
    if(psfc_orientation_insert_blackout_date($values['date'])) {
      drupal_set_message(t('A new orientation blackout time has been created for %day', array('%day' => $values['date'])));
    }
    else {
      drupal_set_message(t('Failed to create a blackout time for %day', array('%day' => $values['date'])));
    }
  }
  drupal_goto( 'admin/psfc/orientation');
}

/**
 * Insert a blackout date record for the given date
 */
function psfc_orientation_insert_blackout_date($date) {
  $id = db_insert('psfc_orientation_blackout_days')
    ->fields(array('blackout_date' => $date))
    ->execute();
  return $id;
}

/**
 * Form to delete orientation blackout dates
 */
function psfc_orientation_delete_blackout($form, $form_state, $obid = NULL) {
  $blackout_days = db_query('SELECT * FROM {psfc_orientation_blackout_days} WHERE obid = :obid', array(':obid' => $obid));
  foreach ($blackout_days as $blackout_day) {
    $blackout_id = $blackout_day->obid;
    $form['obid'] = array(
      '#type' => 'value',
      '#value' => $blackout_id,
    );
    if ($blackout_id) {
      return confirm_form($form, t('Are you sure you want to delete the blackout date set for %day?',
        array('%day' => $blackout_day->blackout_date)), 'admin/psfc/orientation',
        t('Orientations will once again be automatically scheduled at this time.'), t('Delete'), t('Cancel'));
    }
    else {
      drupal_set_message(t('Orientation blackout date not found.'), 'error');
      drupal_goto('admin/psfc/orientation');
    }
  }
}

/**
 * Process orientation blackout form submission.
 */
function psfc_orientation_delete_blackout_submit($form, &$form_state) {
  $obid = $form_state['values']['obid'];
  $q = db_query('SELECT * FROM {psfc_orientation_blackout_days} WHERE obid = :obid', array(':obid' => $obid));
  foreach ($q as $info) {
    db_delete('psfc_orientation_blackout_days')
      ->condition('obid', $obid)
      ->execute();
    drupal_set_message(t('The blackout date for  %day has been deleted.', array('%day' => $info->blackout_date)));
    watchdog('psfc', 'Orientation blackout date for  %day was deleted.', array('%day' => $info->blackout_date), WATCHDOG_NOTICE);
    $form_state['redirect'] = 'admin/psfc/orientation';
  }
}

/**
 * Form to delete an orientation rule
 */
function psfc_orientation_admin_delete_rule($form, $form_state, $orid = NULL) {
  if ($info = psfc_orientation_get_repeat_rule_info($orid)) {
    $form['orid'] = array(
      '#type' => 'value',
      '#value' => $info['orid'],
    );
    return confirm_form($form, t('Are you sure you want to delete the orientation on %day at %time?',
      array('%day' => $info['day_of_week'], '%time' => $info['time_of_day'])), 'admin/psfc/orientation',
      t('Orientations will no longer be automatically scheduled at this time.'), t('Delete'), t('Cancel'));
  }
  else {
    drupal_set_message(t('Orientation rule not found.'), 'error');
    drupal_goto('admin/psfc/orientation');
  }
}

/**
 * Process orientation rule delete form submission.
 */
function psfc_orientation_admin_delete_rule_submit($form, &$form_state) {
  $info = psfc_orientation_get_repeat_rule_info($form_state['values']['orid']);
  db_delete('psfc_orientation_repeat_rules')
  ->condition('orid', $info['orid'])
  ->execute();
  drupal_set_message(t('The orientation rule for  %day_of_week at %time_of_day has been deleted.',
    array('%day_of_week' => $info['day_of_week'], '%time_of_day' => $info['time_of_day'])));
  watchdog('psfc', 'Orientation rule for  %day_of_week at %time_of_day was deleted.',
    array('%day_of_week' => $info['day_of_week'], '%time_of_day' => $info['time_of_day']), WATCHDOG_NOTICE);

  $form_state['redirect'] = 'admin/psfc/orientation';
}

/**
 *  Form function to edit an orientation rule.
 */
function psfc_orientation_admin_edit_rule($form, $orid) {
  $orid = $orid['build_info']['args'][0];
  $form = psfc_orientation_admin_rule_form_skel('edit', $orid);
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
  );
  return $form;
}

/**
 * Process orientation rule edit submission.
 */
function psfc_orientation_admin_edit_rule_submit($form, &$form_state) {
  $values = $form_state['values'];
  $time = $values['hour'] . ':' . $values['min'] . ' ' . $values['ampm'];
  db_update('psfc_orientation_repeat_rules')
    ->fields(array(
      'day_of_week' => $values['day_of_week'],
      'time_of_day' => $time,
      'capacity' => $values['capacity'],
    ))
    ->condition('orid', $values['orid'])
    ->execute();
  drupal_set_message(t('The orientation rule for  %day_of_week at %time_of_day has been updated.',
    array('%day_of_week' => $values['day_of_week'], '%time_of_day' => $time)));
  $form_state['redirect'] = 'admin/psfc/orientation';
}

/**
 * Orientation log in or create account . Using this instead of default.
 */

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function psfc_orientation_login() {
  return theme('psfc_orientation_login');
}


/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function theme_psfc_orientation_login() {
  $why_account_help_txt = node_load(variable_get('psfc_orientation_why_account', 37));
  $why_account_help_txt_view = node_view($why_account_help_txt);
  if (user_access('administer psfc orientation') && user_access('administer nodes')) {
    $why_account_help_txt_view .= l('edit', "node/" . variable_get('psfc_orientation_why_account', 37) . "/edit");
  }
  $account_create_help_txt = node_load(variable_get('psfc_orientation_account_create', 38));
  $account_create_help_txt_view = node_view($account_create_help_txt);
  if (user_access('administer psfc orientation') && user_access('administer nodes')) {
    $account_create_help_txt_view .= l('edit', "node/" . variable_get('psfc_orientation_account_create', 38) . "/edit");
  }

  $output = '<div class="orientation-login">';
  $output .= '<h3>If you already have an account, please log in</h3>';
  $user_login = drupal_get_form('user_login');
  $output .= render($user_login);
  $output .= '<br />' . l(t('Request new password'), 'user/password');
  $output .= '<div class="orientation-what">';
  $output .= render($why_account_help_txt_view);
  $output .= '</div>';
  $output .= '</div>';
  $output .= '<div class="orientation-register">';
  // $output .= '<h3>Create an account</h3>';
  $output .= render($account_create_help_txt_view);
  $user_register = drupal_get_form('user_register_form');
  $output .= render($user_register);
  $output .= '</div>';
  return $output;
}

/**
 * Return an array of upcoming orientations
 *
 * The array should
 */
function psfc_orientation_upcoming_orientations() {
  $ret = array();
  $sql = "SELECT n.nid AS nid, field_orientation_date_value AS date ".
    "FROM {node} n JOIN ".
    "{field_revision_field_orientation_date} d ON n.nid = d.entity_id JOIN ".
    "{field_revision_field_orientation_closed} c ON n.nid = c.entity_id ".
    "WHERE n.type = 'orientation' AND d.field_orientation_date_value >= NOW() AND ".
    "c.field_orientation_closed_value != 1;";
  $result = db_query($sql);
  foreach ($result as $ort) {
    // This is a bit hokey. Drupal stores the date/time in the database in UTC AND in ISO format.
    // Since Drupal and PHP know we are in America/New_York, any attempt to convert to a UTC timestamp
    // will expect this date to be in America/New_York, not UTC.
    // So... convert it from 2017-07-02 23:30:00 to 2017-07-02T23:30:00Z - the Z means UTC.
    $timestamp = strtotime(str_replace(' ', 'T', $ort->date) . 'Z');
    $ret[$ort->nid] = format_date($timestamp);
  }
  return $ret;
}
/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function psfc_orientation_add_registrant($form, $form_state) {
  // Get available orientations
  $options = psfc_orientation_upcoming_orientations();

  $form['instructions'] = array(
    '#value' => '<h2>' . t('Manually sign up a person for orientation') . '</h2>' .
    t('You may add one person at a time to an orientation. The person may be added by email address or by name and phone number.'),
  );
  $form['onid'] = array(
    '#type' => 'select',
    '#title' => t('Select an orientation'),
    '#default_value' => isset($form_state['values']['onid']) ? $form_state['values']['onid'] : NULL,
    '#options' => $options,
    '#required' => TRUE,
    '#description' => t('All upcoming orientations are listed.'),
  );
  $form['has_account'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sign up a person who already has a site account'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('You will need to have the person\'s email address. The person must already have a site account.'),
  );

  $form['has_account']['mail'] = array(
    '#type' => 'textfield',
    '#title' => t('Registrant\'s email address'),
    '#maxlength' => 60,
    '#autocomplete_path' => 'admin/psfc/orientation/psfc-orientation-autocomplete',
    '#default_value' => isset($form_state['values']['mail']) ? $form_state['values']['mail'] : NULL,
  );
  $form['no_account'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sign up a person using name and phone number'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('You will not need to have the person\'s email address.'),
  );
  $form['no_account']['first_name'] = array(
    '#type' => 'textfield',
    '#title' => t('First name'),
    '#default_value' => isset($form_state['values']['first_name']) ? $form_state['values']['first_name'] : NULL,
    '#size' => 30,
    '#maxlength' => 30,
  );
  $form['no_account']['last_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Last name'),
    '#default_value' => isset($form_state['values']['last_name']) ? $form_state['values']['last_name'] : NULL,
    '#size' => 30,
    '#maxlength' => 30,
  );
  $form['no_account']['phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Phone number'),
    '#default_value' => isset($form_state['values']['phone']) ? $form_state['values']['phone'] : NULL,
    '#size' => 30,
    '#maxlength' => 30,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

/**
 * Validation function for manual sign up.
 */
function psfc_orientation_add_registrant_validate(&$form, &$form_state) {
  $values = $form_state['values'];
  if (!empty($values['mail']) && (!empty($values['first_name']) || !empty($values['last_name']) || !empty($values['middle_name']) || !empty($values['phone']))) {
    form_set_error('mail', t('You may only register someone by email OR by name and phone.'));
  }
  if (empty($values['mail']) && (empty($values['first_name']) || empty($values['last_name']) || empty($values['phone']))) {
    form_set_error('first_name', t('First name, last name and phone number are required for non-internet users.'));
  }
}

/**
 * Submit function for manual sign up.
 */
function psfc_orientation_add_registrant_submit($form, &$form_state) {
  // Registrant has a site account.
  $orientation = node_load($form_state['values']['onid']);
  $confirmed = 1;
  if (!empty($form_state['values']['mail'])) {
    $mail = $form_state['values']['mail'];
    $user = user_load_multiple(array(), array('mail' => $mail));
    $account = array_shift($user);
    if(empty($account->uid)) {
      drupal_set_message(t("Failed to find that user."));
      return;
    }
    $attendee_wrapper = psfc_orientation_node_build_attendee_from_account($account, $form_state['values']['onid'], $confirmed);
  }
  // Registrant has no internet access ever.
  else {
    $email = NULL;
    global $user;
    $uid = $user->uid;
    $attendee_wrapper = psfc_orientation_node_build_attendee(
      $form_state['values']['onid'],
      $form_state['values']['first_name'],
      $form_state['values']['last_name'],
      $email,
      $form_state['values']['phone'],
      $uid,
      $confirmed
    );
  }
  $info = $attendee_wrapper->field_first_name->value() . ' ' . $attendee_wrapper->field_last_name->value();
  drupal_set_message(t('@info has been registed for orientation on @date.',
    array('@info' => $info, '@date' => $orientation->field_orientation_date['und'][0]['value'])));

}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function psfc_orientation_email_autocomplete($string = '') {
  $matches = array();
  if ($string) {
    $result = db_query('SELECT mail FROM {users} WHERE mail LIKE :string', array(':string' => db_like($string) . '%'));
    foreach ($result as $user) {
      $matches[$user->mail] = check_plain($user->mail);
    }
  }
  if (count($matches)) {
    drupal_json_output($matches);
  }
}

