<?php

function psfc_orientation_nodemap_settings($form, &$form_state) {
  $form['psfc_orientation_nodemap_help'] = array(
    '#markup' => '<p>' . t('There are parts of the orientation system that have multiple little pages placed onto one page, or entirely surrounded by code complexitiy. To make it easier we\'ve abstracted that text into nodes. Here is a map for each piece of content.') . '</p><p>' . t('To change any one mapping, just change the node id in the form, and save it.') . '</p><p>' . t('NOTE: The convenience links below each form field will not update until you save the page.') . '</p>',
  );


  // There are no orientations available
  $form['no_orientations'] = array(
    '#type' => 'fieldset',
    '#title' => t('There are no orientations available'),
  );
  $form['no_orientations']['psfc_orientation_no_orientations'] = array(
    '#type' => 'textfield',
    '#title' => t('Node ID'),
    '#default_value' => variable_get('psfc_orientation_no_orientations', 35),
    '#size' => 5,
  );
  $form['no_orientations']['psfc_orientation_no_orientations_links'] = array(
    '#markup' => l('Edit this node', 'node/' . variable_get('psfc_orientation_no_orientations') .'/edit'),
  );

  // Text below list of available orientations
  $form['below_available'] = array(
    '#type' => 'fieldset',
    '#title' => t('Text below list of available orientations'),
  );
  $form['below_available']['psfc_orientation_upcoming_orientations'] = array(
    '#type' => 'textfield',
    '#title' => t('Node ID'),
    '#default_value' => variable_get('psfc_orientation_upcoming_orientations', 36),
    '#size' => 5,
  );
  $form['below_available']['psfc_orientation_upcoming_orientations_links'] = array(
    '#markup' => l('Edit this node', 'node/' . variable_get('psfc_orientation_upcoming_orientations') .'/edit'),
  );


  // What is an online account (login page left)
  /* variable_set('psfc_orientation_why_account', 37); */
  $form['why_account'] = array(
    '#type' => 'fieldset',
    '#title' => t('What is an online account (login page left)'),
  );
  $form['why_account']['psfc_orientation_why_account'] = array(
    '#type' => 'textfield',
    '#title' => t('Node ID'),
    '#default_value' => variable_get('psfc_orientation_why_account', 37),
    '#size' => 5,
  );
  $form['why_account']['psfc_orientation_why_account_links'] = array(
    '#markup' => l('Edit this node', 'node/' . variable_get('psfc_orientation_why_account') .'/edit'),
  );


  /* // Account creation instructions (login page right) */
  $form['below_available'] = array(
    '#type' => 'fieldset',
    '#title' => t('Text below list of available orientations'),
  );
  $form['below_available']['psfc_orientation_upcoming_orientations'] = array(
    '#type' => 'textfield',
    '#title' => t('Node ID'),
    '#default_value' => variable_get('psfc_orientation_upcoming_orientations', 36),
    '#size' => 5,
  );
  $form['below_available']['psfc_orientation_upcoming_orientations_links'] = array(
    '#markup' => l('Edit this node', 'node/' . variable_get('psfc_orientation_upcoming_orientations') .'/edit'),
  );


  // New user signed up as part of orientation registration
  $form['new_user_ort'] = array(
    '#type' => 'fieldset',
    '#title' => t('New user signed up as part of orientation registration'),
  );
  $form['new_user_ort']['psfc_orientation_new_user_from_orientation'] = array(
    '#type' => 'textfield',
    '#title' => t('Node ID'),
    '#default_value' => variable_get('psfc_orientation_new_user_from_orientation', 86),
    '#size' => 5,
  );
  $form['new_user_ort']['psfc_orientation_new_user_from_orientation_links'] = array(
    '#markup' => l('Edit this node', 'node/' . variable_get('psfc_orientation_new_user_from_orientation') .'/edit'),
  );


  // New user signed up from another form
  $form['new_user'] = array(
    '#type' => 'fieldset',
    '#title' => t('New user signed up from another form'),
  );
  $form['new_user']['psfc_orientation_new_user'] = array(
    '#type' => 'textfield',
    '#title' => t('Node ID'),
    '#default_value' => variable_get('psfc_orientation_new_user', 87),
    '#size' => 5,
  );
  $form['new_user']['psfc_orientation_new_user_links'] = array(
    '#markup' => l('Edit this node', 'node/' . variable_get('psfc_orientation_new_user') .'/edit'),
  );


  // Confirm orientation details page
  $form['confirm_ort'] = array(
    '#type' => 'fieldset',
    '#title' => t('Confirm orientation details page'),
  );
  $form['confirm_ort']['psfc_orientation_confirm_orientation_page'] = array(
    '#type' => 'textfield',
    '#title' => t('Node ID'),
    '#default_value' => variable_get('psfc_orientation_confirm_orientation_page', 40),
    '#size' => 5,
  );
  $form['confirm_ort']['psfc_orientation_confirm_orientation_page_links'] = array(
    '#markup' => l('Edit this node', 'node/' . variable_get('psfc_orientation_confirm_orientation_page') .'/edit'),
  );


  // Session no longer available
  $form['ort_filled'] = array(
    '#type' => 'fieldset',
    '#title' => t('Session no longer available'),
  );
  $form['ort_filled']['psfc_orientation_orientation_filled'] = array(
    '#type' => 'textfield',
    '#title' => t('Node ID'),
    '#default_value' => variable_get('psfc_orientation_orientation_filled', 41),
    '#size' => 5,
  );
  $form['ort_filled']['psfc_orientation_orientation_filled_links'] = array(
    '#markup' => l('Edit this node', 'node/' . variable_get('psfc_orientation_orientation_filled') .'/edit'),
  );


  //  Could not register addiontional attendees
  $form['no_additional'] = array(
    '#type' => 'fieldset',
    '#title' => t('Could not register addiontional attendees'),
  );
  $form['no_additional']['psfc_orientation_no_additional_attendees'] = array(
    '#type' => 'textfield',
    '#title' => t('Node ID'),
    '#default_value' => variable_get('psfc_orientation_no_additional_attendees', 42),
    '#size' => 5,
  );
  $form['no_additional']['psfc_orientation_no_additional_attendees_links'] = array(
    '#markup' => l('Edit this node', 'node/' . variable_get('psfc_orientation_no_additional_attendees') .'/edit'),
  );


  // Thank you for confirming your orientation
  $form['thank_you'] = array(
    '#type' => 'fieldset',
    '#title' => t('Thank you for confirming your orientation'),
  );
  $form['thank_you']['psfc_orientation_confirmation_thank_you'] = array(
    '#type' => 'textfield',
    '#title' => t('Node ID'),
    '#default_value' => variable_get('psfc_orientation_confirmation_thank_you', 43),
    '#size' => 5,
  );
  $form['thank_you']['psfc_orientation_confirmation_thank_you_links'] = array(
    '#markup' => l('Edit this node', 'node/' . variable_get('psfc_orientation_confirmation_thank_you') .'/edit'),
  );


  // Cancellation completion
  $form['reg_removed'] = array(
    '#type' => 'fieldset',
    '#title' => t('Cancellation completion'),
  );
  $form['reg_removed']['psfc_orientation_registrant_removed'] = array(
    '#type' => 'textfield',
    '#title' => t('Node ID'),
    '#default_value' => variable_get('psfc_orientation_registrant_removed', 44),
    '#size' => 5,
  );
  $form['reg_removed']['psfc_orientation_registrant_removed_links'] = array(
    '#markup' => l('Edit this node', 'node/' . variable_get('psfc_orientation_registrant_removed') .'/edit'),
  );

  return system_settings_form($form);

}