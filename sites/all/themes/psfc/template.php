<?php

/**
 * Implementation of template_preprocess_page().
 */
function psfc_preprocess_page(&$variables) {
  if (module_exists('devel') && user_access('access devel information')) {
    $variables['devel'] = '<div id="devel-area">'. $variables['devel_area'] .'</div>';
  }
  $variables['primary_links'] = psfc_output_primary($variables['primary_links']);
}

/**
 * Implementation of template_preprocess_block().
 *
 */
function psfc_preprocess_block(&$variables) {
  // Add grid and other classes.
  $variables['extra_block_classes'] = NULL;
  if ($variables['block']->region == 'footer') {
    $variables['extra_block_classes'] = 'grid_3';
  }
}

 function psfc_output_primary($primary_links) {
  $out = '<ul id="nav">';
  // create an array to map css classes, for background image in links
  $class_names = array(
    'About the Coop' => 'about',
    'Overview' => 'join',
    'News & Publications' => 'news',
    'Food & Recipies' => 'food',
   'Events & Community' =>  'events',
   'Member Information' => 'members',
  );

  foreach ($primary_links as $key => $menu_item) {
    $attributes = array('class' => $class_names[$menu_item['title']]);
    $link = l($menu_item['title'], $menu_item['href'], array('attributes' => $attributes));
    $out .= '<li class="grid_2">'. $link .'</li>';
  }
  $out .= '</ul>';

  return $out;
}

// Adding the class "button" so we can target to replace with cufon text in
// psfc.js
function psfc_button($element) {
  // Make sure not to overwrite classes.
  if (isset($element['#attributes']['class'])) {
    $element['#attributes']['class'] = 'form-' . $element['#button_type'] . ' ' . $element['#attributes']['class']  .' button';
  }
  else {
    $element['#attributes']['class'] = 'form-' . $element['#button_type'] .' button';
  }

  return '<input type="submit" ' . (empty($element['#name']) ? '' : 'name="' . $element['#name'] . '" ') . 'id="' . $element['#id'] . '" value="' . check_plain($element['#value']) . '" ' . drupal_attributes($element['#attributes']) . " />\n";

}


function psfc_views_bulk_operations_fields_action_form($form) {
  if (arg(0) == 'admin' && arg(1) == 'psfc' && arg(2) == 'orientation' && arg(3) == 'attendee-manage') {
    drupal_set_title(t('Change attendence status for attendees'));
  }
  $output = '';
  $access = user_access('Use PHP input for field settings (dangerous - grant with care)');
  if ($access && $form['#settings']['php_code']) {
    $output .= t('<h3>Using the Code widget</h3>
                  <ul>
                  <li>Will override the value specified in the Field widget.</li>
                  <li>Should include &lt;?php ?&gt; delimiters.</li>
                  <li>If in doubt, refer to <a target="_blank" href="@link_devel">devel.module</a> \'Dev load\' tab on a content page to figure out the expected format.</
li>
                  </ul>', array('@link_devel' => 'http://www.drupal.org/project/devel')
                 );
  }

  if (count($form['#field_info']) == 1) { // Special case for just one field: make the table more usable
    $field_name = key($form['#field_info']);
    $header = array();
    if ($form[$field_name . '_add']['#type'] == 'checkbox') {
      $row[] = drupal_render($form[$field_name . '_add']);
      $header[] = array('data' => t('Add?'), 'title' => t('Checkboxes in this column allow you to add new values to multi-valued fields, instead of overwriting existing values.'));
    }
    $row[] = drupal_render($form[$field_name]);
    $header[] = t('Field');
    if ($access && $form['#settings']['php_code']) {
      $row[] = drupal_render($form[$field_name . '_code']);
      $header[] = t('Code');
    }
    if (count($header) == 1) {
      $header = NULL;
    }
    $output .= theme('table', $header, array(array('class' => 'fields-action-row', 'id' => 'fields-action-row' . str_replace('_', '-', $field_name), 'data' => $row)));
  }
  else { // Many fields
    drupal_add_js(drupal_get_path('module', 'views_bulk_operations') . '/fields.action.js');

    $header = array(theme('table_select_header_cell'), t('Add?'), t('Field'));
    if ($access && $form['#settings']['php_code']) {
      $header[] = t('Code');
    }
    if (!empty($form['#field_info'])) foreach ($form['#field_info'] as $field_name => $field) {
        $row = array(
                     'class' => 'fields-action-row',
                     'id' => 'fields-action-row-' . str_replace('_', '-', $field_name), 
                     'data' => array(
                                     drupal_render($form[$field_name . '_check']),
                                     drupal_render($form[$field_name . '_add']),
                                     drupal_render($form[$field_name]),
                                     ),
                     );
        if ($access && $form['#settings']['php_code']) {
          $row['data'][] = drupal_render($form[$field_name . '_code']);
        }
        $rows[] = $row;
      }
    $output .= theme('table', $header, $rows); 
  }
  $output .= drupal_render($form);
  return $output;
}
