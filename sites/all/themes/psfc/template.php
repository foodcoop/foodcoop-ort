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