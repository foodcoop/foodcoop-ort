<?php

/**
 * Default Administration page
 */
function psfc_orientation_admin_page() {
  $existing_orientations = psfc_orientation_display_orientation_rules();
  $form = array();
  $form['existing_orientations'] = array(
    '#type' => 'markup',
    '#value' => $existing_orientations,
  );
  $form['psfc_orientation_default_description'] = array(
    '#type' => 'textarea',
    '#title' => t('Default Orientation Description'),
    '#default_value' => variable_get('psfc_orientation_default_description', t('PSFC Orientations are blah blah blah')),
    '#description' => t("This is the description that will be put on the auto generated orientations."),
  );
  return system_settings_form($form);
}
/**
 * Build a generic resuable form for dealing with orientation rules
 */
function psfc_orientation_admin_rule_form_skel($op, $orid = NULL) {
  $form = array();

  switch ($op) {
    case 'edit':
      if (is_numeric($orid)) {
        $info = psfc_orientation_get_repeat_rule_info($orid);
        $time = psfc_orienation_split_time_of_day($orid);
      }
      break;
  }
  $form['orid'] = array(
    '#type' => 'value',
    '#value' => (!$info) ? NULL : $info['orid'],
  );
  $form['day_of_week'] = array(
    '#type' => 'select',
    '#title' => t('Day'),
    '#options' => array(
      'Sunday' => 'Sunday',
      'Monday' =>  'Monday',
      'Tuesday' =>  'Tuesday',
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
      '01' => 1,
      '02' => 2,
      '03' => 3,
      '04' => 4,
      '05' => 5,
      '06' => 6,
      '07' => 7,
      '08' => 8,
      '09' => 9,
      '10' => 10,
      '11' => 11,
      '12' => 12,
    ),
    '#required' => TRUE,
    '#default_value' => (!$time) ? NULL : $time['hour'],
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
    '#default_value' => (!$time) ? NULL : $time['minute'],

  );
  $form['ampm'] = array(
    '#type' => 'select',
    '#title' => 'AM / PM',
    '#options' => array(
      'AM' => 'AM',
      'PM' => 'PM',
    ),
    '#required' => TRUE,
    '#default_value' => (!$time) ? NULL : $time['ampm'],
  );

  $form['capacity'] = array(
    '#type' => 'textfield',
    '#title' => t('Capacity'),
    '#default_value' => (!$edit) ? NULL : $edit[0]['capacity'],
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
function psfc_orientation_admin_add_rule($edit) {
  $form = psfc_orientation_admin_rule_form_skel('add');
  $form['submit'] = array('#type' => 'submit', '#value' => t('Add'));
  return $form;
}

// function psfc_orientation_admin_add_rule_validate($form, &$form_state) {
//   $values = $form_state['values'];
// }

function psfc_orientation_admin_add_rule_submit($form, &$form_state) {
  $values = $form_state['values'];
  $time = $values['hour'] .':'. $values['min'] .' '. $values['ampm'];
  if ($values['submit'] == 'Add') {
    db_query('INSERT INTO {psfc_orientation_repeat_rules} (day_of_week, time_of_day, capacity) VALUES ("%s","%s", "%d")', $values['day_of_week'], $time, $values['capacity']);
    $form_state['values']['orid'] = db_last_insert_id('psfc_orientation_repeat_rules', 'orid');

    drupal_set_message(t('A new orientation time has been created for %day at %time with room for %capacity people', array('%day' => $values['day_of_week'] .'s', '%time' => $time, '%capacity' => $values['capacity'])));
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
  while ($result = db_fetch_array($query)) {
    $orientation = t('%day at %time with room for %capacity', array('%day' => $result['day_of_week'] .'s', '%time' => $result['time_of_day'], '%capacity' => $result['capacity']));
    $rows[] = array($orientation, l('edit', 'admin/psfc/orientation/edit-rule/'. $result['orid']), l('delete', 'admin/psfc/orientation/delete-rule/'. $result['orid']));
  }

  $output = theme('table', array(t('Existing Rules')), $rows);

  return $output;
}

/**
 * Delete an orientation rule
 */
function psfc_orientation_admin_delete_rule($form_state, $orid = NULL) {
  if ($info = psfc_orientation_get_repeat_rule_info($orid)) {
    $form['orid'] = array(
      '#type' => 'value',
      '#value' => $info['orid'],
    );
    return confirm_form($form, t('Are you sure you want to delete the orientation on %day at %time?', array('%day' => $info['day_of_week'], '%time' => $info['time_of_day'])), 'admin/psfc/orientation', t('Orientations will no longer be automatically scheduled at this time.'), t('Delete'), t('Cancel'));
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
  db_query("DELETE FROM {psfc_orientation_repeat_rules} WHERE orid = %d", $info['orid']);
  drupal_set_message(t('The orientation rule for  %day_of_week at %time_of_day has been deleted.', array('%day_of_week' => $info['day_of_week'], '%time_of_day' => $info['time_of_day'])));
  watchdog('psfc', 'Orientation rule for  %day_of_week at %time_of_day was deleted.', array('%day_of_week' => $info['day_of_week'], '%time_of_day' => $info['time_of_day']), WATCHDOG_NOTICE);

  $form_state['redirect'] = 'admin/psfc/orientation';
}

function psfc_orientation_admin_edit_rule($form, $orid) {
  $form = psfc_orientation_admin_rule_form_skel('edit', $orid);
  $form['submit'] = array('#type' => 'submit', '#value' => t('Update'));
  return $form;
}

// function psfc_orientation_admin_edit_rule_validate($form, &$form_state) {
//   dsm($form_state);
// }

function psfc_orientation_admin_edit_rule_submit($form, &$form_state) {
  $values = $form_state['values'];
  $time = $values['hour'] .':'. $values['min'] .' '. $values['ampm'];
  db_query('UPDATE {psfc_orientation_repeat_rules} SET day_of_week = "%s", time_of_day = "%s", capacity = %d WHERE orid = %d', $values['day_of_week'], $time, $values['capacity'], $values['orid']);
  drupal_set_message(t('The orientation rule for  %day_of_week at %time_of_day has been updated.', array('%day_of_week' => $values['day_of_week'], '%time_of_day' => $time)));
  $form_state['redirect'] = 'admin/psfc/orientation';
}

