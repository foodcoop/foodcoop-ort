<?php

/**
 * Implementation of hook_token_list().
 */
function psfc_orientation_token_list($type = 'all') {
  $tokens = array();
  if ($type == 'node' || $type == 'all') {
    $tokens['psfc_orientation']['register-button'] = t('Contextual button: Register for an Orientation, or Create Account / Log in to Register for an Orientation, or No Orientations available. ');
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
    if (!$user->uid) {
      $values['register-button'] = '<div class="button-rounded"><span><a href="/login">Create an Account / Login to Register for Orientation</a></span></div>';
    }
    // Logged in, there are openings.
    if ($user->uid && psfc_orientation_check_openings()) {
      $values['register-button'] = '<div class="button-rounded"><span><a href="/join/orientation">Register for Orientation</a></span></div>';
    }
    // Logged in, there are openings.
    elseif ($user->uid && !psfc_orientation_check_openings()) {
      $values['register-button'] = '<div class="button-rounded grey"><span><a href="/login">Sorry, there are no Orientations available - create an account if you like.</a></span></div>';
    }
  }
  return $values;
}
