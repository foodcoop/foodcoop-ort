<?php

/**
 * Implementation of hook_token_list().
 */
function psfc_orientation_token_list($type = 'all') {
  $tokens = array();
  if ($type == 'node' || $type == 'all') {
    $tokens['psfc_orientation']['register-button'] = t('Contextual button: Register for an Orientation, or Create Account / Log in to Register for an Orientation, or No Orientations available. ');
    $tokens['psfc_orientation']['orientation-date'] = t('Confirmed orientation session date for current user.');
  }
  return $tokens;
}

/**
 * Implementation of hook_token_values().
 */
function psfc_orientation_token_values($type, $object = NULL) {
  $values = array();
  if ($type == 'global') {
    global $user;
    // Not logged in.
    if (!$user->uid && psfc_orientation_check_openings()) {
      $values['register-button'] = '<div class="button-rounded"><span><a href="/login?destination=join/orientation">Create an Account / Login to Register for Orientation</a></span></div>';
    }
    // Not logged in, no sessions available.
    elseif (!$user->uid && !psfc_orientation_check_openings()) {
      $values['register-button'] =       '<h1> Sorry, there are no sessions available at this time.</h1>
       <p>All of the Sessions that have been opened for registration at this time are full and no more seats are available. <strong>
       If you have not yet created an PSFC user account, we encourage you to do so now</strong>
       to expedite the registration process when you return to the site at a later date, and to
       better your chances of getting an Orientation seat in time. Please also feel free to explore our
       website to learn more about the Coop and Coop Membership.</p>'.
       '<div class="button-rounded"><span><a href="/login">Create an Account</a></span></div>';
    }
    // Logged in, there are openings.
    if ($user->uid && psfc_orientation_check_openings()) {
      $values['register-button'] = '<div class="button-rounded"><span><a href="/join/orientation">Register for Orientation</a></span></div>';
    }
    // Logged in, there are openings.
    elseif ($user->uid && !psfc_orientation_check_openings()) {
      $values['register-button'] = 
      '<h1> Sorry, there are no sessions available at this time.</h1>
       <p>All of the Sessions that have been opened for registration at this time are full and no more seats are available. <strong>
       If you have not yet created an PSFC user account, we encourage you to do so now</strong> 
       to expedite the registration process when you return to the site at a later date, and to 
       better your chances of getting an Orientation seat in time. Please also feel free to explore our 
       website to learn more about the Coop and Coop Membership.</p>'.
      '<div class="button-rounded grey"><span>Register for Orientation.</span></div>';
    }
  }
  // We only want this token if the user is confirme form orientation, no more,
  // no less.
  if (psfc_orientation_user_orientation_status($user->uid) == 1) {
    $attendee = psfc_orientation_get_attendee_node($user);
    $orientation = node_load($attendee->field_orientation_nid[0]['nid']);
    $values['orientation-date'] = theme_psfc_orientation_date_table($orientation);
  }
  return $values;
}
