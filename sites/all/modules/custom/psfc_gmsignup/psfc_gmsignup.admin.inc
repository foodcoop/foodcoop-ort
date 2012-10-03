<?php
function psfc_gmsignup_admin_page(){
  $current_month = date('m');
  // THIS IS A HACK!!
  // php 5.2 date handling doesn't know how to to handle
  // 'last Tueday of 2012-11'. php 5.3 reads that as the
  // give me the date of the last Tuesday that occurs in
  // November. 5.2 however reads that as "Its the first
  // of november, what was the date last tuesday".

  // to fix the hack, remove the line below, and add 'of'
  // to the 'last Tuesday ' strtotime call below.
  $current_month++;
  $current_year = date('Y');
  $range = range($current_month, $current_month + 11);
  $upcoming_mtg_dates = array();
  $upcoming_mtg_nodes = psfc_gmsignup_get_upcoming_mtg_nodes();
  foreach ($range as $value) {
    $year = $current_year;
    if ($value > 12) {
      $value -= 12; $year += 1;
    }
    $default_date_stamp = strtotime('last Tuesday ' . $year . '-' . $value . ' 20:00:00');
    $default_date = date('Y-m-d H:i:s', $default_date_stamp);

    $mtg_month = date('Y-m', $default_date_stamp);
    $upcoming_mtg_dates[$mtg_month] = array(
     'timestamp' => $default_date_stamp,
     'date_formatted' => $default_date,
     'meeting_month' => $mtg_month,
     'created' => FALSE,
    );
  }
  dsm($upcoming_mtg_dates);
  dsm(psfc_gmsignup_get_upcoming_mtg_nodes());
  foreach (psfc_gmsignup_get_upcoming_mtg_nodes() as $nid => $info) {
    $up_mtg_mo = date('Y-m', strtotime($info['meeting_month']));
    dsm($date);
    if (isset($upcoming_mtg_dates[$up_mtg_mo])) {
      $upcoming_mtg_dates[$mtg_month]['created'] = TRUE;
      $output = 'got here';
    }
  }
  foreach ($upcoming_mtg_dates as $month => $data) {
    if (!$data['created']) {
      // CREATE GM NODE
      //$upcoming_mtg_dates[$mtg_month]['created'] = TRUE;
    }
  }

      //  return theme('table', array('header' => array('data' => t('Default dates'), '' => ''), 'rows' => $tbl_tmp));
  return isset($output) ? $output : 'nothin';
}

/**
 * @function Helper function to get upcoming meeting nodes
 *
 * @return An associative array of upcoming meeting node objects.
 */

function psfc_gmsignup_get_upcoming_mtg_nodes() {
  $query = db_query('SELECT n.nid, f.field_gm_date_value, f2.field_meeting_month_value
    FROM {node} n
      JOIN {field_data_field_gm_date} f
        ON n.vid=f.revision_id
        AND n.nid=f.entity_id
      JOIN {field_data_field_meeting_month} f2
        ON n.vid=f2.revision_id
        AND n.nid=f2.entity_id
      WHERE f.field_gm_date_value > :now',
      array(':now' => time())
  );
  $out = array();
  foreach ($query as $result) {
    $out[$result->nid] = array(
      'nid' => $result->nid,
      'date' => $result->field_gm_date_value,
      'meeting_month' => $result->field_meeting_month_value,
    );
  }
  return $out;
}
