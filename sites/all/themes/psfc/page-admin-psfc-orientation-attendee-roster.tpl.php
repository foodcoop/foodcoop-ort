<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">
  <head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8" />
    <title><?php print $head_title; ?></title>
    <?php print $head; ?>
    <link type="text/css" rel="stylesheet" media="all" href="<?php print base_path(); ?>modules/system/defaults.css">
    <link type="text/css" rel="stylesheet" media="all" href="<?php print base_path(); ?>modules/system/system.css">
    <link type="text/css" rel="stylesheet" media="all" href="<?php print base_path(); ?>modules/system/system-menus.css">
    <link type="text/css" rel="stylesheet" media="all" href="<?php print base_path() . path_to_theme()  ?>/css/roster.css">
  </head>
  <body>
   <h1><img src="<?php print base_path() . path_to_theme()  ?>/img/logo-grayscale.png" /> <?php print $title; ?></h1>
   <?php print $content; ?>
   <table>
      <tr><td class="walk-in" >&nbsp;</td></tr>
      <tr><td class="walk-in" >&nbsp;</td></tr>
      <tr><td class="walk-in" >&nbsp;</td></tr>
      <tr><td class="walk-in" >&nbsp;</td></tr>
      <tr><td class="walk-in" >&nbsp;</td></tr>
   </table>
    <?php print $closure; ?>
  </body>
</html>