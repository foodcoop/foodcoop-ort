<?php

/**
 * @file Drush file for psfc_orientation
 *
 **/

function psfc_orientation_drush_command() {
    $items = array();

    // the key in the $items array is the name of the command.
    $items['psfc-create-ort'] = array(
        'callback' => 'psfc_orientation_create_ort',
        'description' => "Create a new orientation based on first returned repeat rule.",
    );
    return $items;
}

function psfc_orientation_create_ort() {
  $query = db_query("SELECT * FROM {psfc_orientation_repeat_rules}");
  while($result = $query->fetchAssoc()) {
    $time = psfc_orientation_split_out_time_of_day($result['orid']);
    $next_ort = psfc_orientation_determine_next_repeat($time);
    if (!psfc_orientation_orientation_exists($next_ort) &&
      !psfc_orientation_orientation_blacked_out($next_ort)) {
      $node_wrapper = psfc_orientation_node_build($result, $next_ort);
      if ($node_wrapper->nid->value()) {
        drush_log(dt("Orientation created."), 'ok');
      }
      else {
        drush_log(dt("Something went wrong, orientation not created."), 'error');
      }
      return;
    }
  }
  $msg = dt("I tried to create an orientation, but all possible times have been created or are blacked out.");
  drush_log($msg, 'error');
}
