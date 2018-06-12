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
  $psfc['mail'] = array(
    'name' => t("Attendee E-mail"),
    'description' => t('Email from attendee record.'),
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
    if(array_key_exists('node', $data)) {
      if($data['node']->type == 'orientation_attendee') {
        $attendee_node_wrapper = entity_metadata_wrapper('node', $data['node']);
        $values['[psfc:mail]'] = $attendee_node_wrapper->field_email->value();
      }
    }
    global $user;
    // Not logged in.
    if (!$user->uid && psfc_orientation_check_openings()) {
      $values['[psfc:register-button]'] = '<div class="btn btn-success btn-lg"><a href="/login?destination=join/orientation">Create an Account / Login to Register for Orientation</a></div>';
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
      $values['[psfc:register-button]'] = '<div class="btn btn-success btn-lg"><a href="/join/orientation">Register for Orientation</a></div>';
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
  }
  return $values;
}
