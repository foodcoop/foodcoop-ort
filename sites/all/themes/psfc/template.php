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
    'Join the Coop' => 'join',
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

//function psfc_button($element) {
//  // Make sure not to overwrite classes.
//  if (isset($element['#attributes']['class'])) {
//    $element['#attributes']['class'] = 'form-' . $element['#button_type'] . ' ' . $element['#attributes']['class'];
//  }
//  else {
//    $element['#attributes']['class'] = 'form-' . $element['#button_type'];
//  }
//  return '<div class="button-rounded"><span><button type="submit" ' . (empty($element['#name']) ? '' : 'name="' . $element['#name'] . '" ') . 'id="' . $element['#id'] . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</button></span></div>';
//}