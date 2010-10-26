<?php

/**
 * Implementation of template_preprocess_page().
 */
function psfc_preprocess_page(&$variables) {
  if (module_exists('devel') && user_access('access devel information')) {
    $variables['devel'] = '<div id="devel-area">'. $variables['devel_area'] .'</div>';
  }
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
