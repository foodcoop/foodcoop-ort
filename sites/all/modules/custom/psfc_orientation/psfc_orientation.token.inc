<?php

/**
 * Implementation of hook_token_list().
 */
function psfc_orientation_token_info() {
  $type = array(
    'name' => t("PSFC Orientation Tokens"),
    'description' => t("Tokens used for PSFC orientations"),
    'needs-data' => 'node',
  );
  $psfc['register-button'] = array(
    'name' => t("Register Button"),
    'description' => t('Contextual button: Register for an Orientation, or Create Account / Log in to Register for an Orientation, or No Orientations available. '),
  );
  $psfc['orientation-date'] = array(
    'name' => t("Orientation Date"),
    'description' => t('Confirmed orientation session date for current user.'),
  );
  return array(
    'types' => array('psfc' => $type),
    'tokens' => array('psfc' => $psfc),
  );
}

/**
 * Implementation of hook_token_values().
 */
function psfc_orientation_tokens($type, $tokens, $data = array(), $options = array()) {
  $values = array();
  if($type == 'psfc') {
    global $user;
    // Not logged in.
    if (!$user->uid && psfc_orientation_check_openings()) {
      $values['[psfc:register-button]'] = '<div class="button-rounded"><span><a href="/login?destination=join/orientation">Create an Account / Login to Register for Orientation</a></span></div>';
    }
    // Not logged in, no sessions available.
    elseif (!$user->uid && !psfc_orientation_check_openings()) {
      $values['[psfc:register-button]'] =       '<h1> Sorry, there are no sessions available at this time.</h1>
       <p>All of the Sessions that have been opened for registration at this time are full and no more seats are available. <strong>
       If you have not yet created an PSFC user account, we encourage you to do so now</strong>
       to expedite the registration process when you return to the site at a later date, and to
       better your chances of getting an Orientation seat in time. Please also feel free to explore our
       website to learn more about the Coop and Coop Membership.</p>'.
       '<div class="button-rounded"><span><a href="/login">Create an Account</a></span></div>';
    }
    // Logged in, there are openings.
    if ($user->uid && psfc_orientation_check_openings()) {
      $values['[psfc:register-button]'] = '<div class="button-rounded"><span><a href="/join/orientation">Register for Orientation</a></span></div>';
    }
    // Logged in, there are openings.
    elseif ($user->uid && !psfc_orientation_check_openings()) {
      $values['[psfc:register-button]'] = 
      '<h1> Sorry, there are no sessions available at this time.</h1>
       <p>All of the Sessions that have been opened for registration at this time are full and no more seats are available. <strong>
       If you have not yet created an PSFC user account, we encourage you to do so now</strong> 
       to expedite the registration process when you return to the site at a later date, and to 
       better your chances of getting an Orientation seat in time. Please also feel free to explore our 
       website to learn more about the Coop and Coop Membership.</p>';
    }

    // We only want this token if the user is confirmed form orientation, no more,
    // no less.
    if ($user && psfc_orientation_user_orientation_status($user->uid) == 1) {
      $attendee = psfc_orientation_get_attendee_node($user);
      $node_wrapper = entity_metadata_wrapper('node', $attendee);
      $nid = $node_wrapper->field_orientation_nid->value()->nid;
      $orientation = node_load($nid);
      $node_wrapper = entity_metadata_wrapper('node', $orientation);
      $date = $node_wrapper->field_orientation_date->value();
      $table = array('date' => $date);
      $values['[psfc:orientation-date]'] = theme_psfc_orientation_date_table($table);
    }
    else {
      $values['[psfc:orientation-date]'] = '';
    }
  }
  return $values;
}
