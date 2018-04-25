<?php

/** 
 * This function replaces the home page link at the top of the them
 * with an alternate URL to users are directed to the group's actual
 * home page rather than the PowerBase home page.
 *
 * Uncomment the function lines and edit to enable.
 **/
function coop_preprocess_page(&$variables) {
  $variables['front_page'] = 'https://foodcoop.com/';
}
