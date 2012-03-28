<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">
  <head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8" />
    <title><?php print $head_title; ?></title>
    <?php print $head; ?>
    <?php print $styles; ?>
    <?php print $scripts; ?>
  </head>
  <body>
    <?php if ($psfc_welcom_new): ?>
      <?php print $psfc_welcom_new; ?>
    <?php endif; ?>
    <div class="container_12">
      <div id="header">
        <div id="logo" class="grid_2">
          <!-- a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a -->
          <a href="http://foodcoop.com/" rel="home"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
        </div>
        <?php if ($header_user): ?>
          <div id="header-user-block" class="grid_8 push_2">
             <?php print render($page['header_user']); ?>
          </div>
        <?php endif; ?>
        <div class="clear"></div>
   <?php //print $primary_links; ?>
       <?php if (isset($main_menu)) { ?><?php print theme('links', $main_menu, array('class' => 'links', 'id' => 'navlist')) ?><?php } ?>

      </div><!-- /header -->

      <div id="section-header">
        <?php print render($title_prefix); ?>
        <?php if ($title): ?><h1>
          <?php print $title; ?></h1>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
      </div>
      <div class="clear"></div>

      <div id="content" class="grid_12">
        <div id="right-side">
          <?php if (count($secondary_links)): ?>
            <div id="secondary-links">
              <?php print theme('links', $secondary_links); ?>
            </div>
          <?php endif; ?>
   <?php print render($page['right']); ?>
        </div>
        <div id="main-content">
          <?php if ($messages): ?>
            <div id="message-section">
              <?php print $messages ?>
              <?php print render($page['help']); ?>
            </div>
          <?php endif; ?>
          <?php if ($tabs): ?>
            <?php print render($tabs); ?>
          <?php endif; ?>
          <?php if ($orientation_crumbs): ?>
   <?php //print $orientation_crumbs; ?>
          <?php endif; ?>
          <?php if ($node->field_subhead): ?>
   <h2><?php //print $node->field_subhead[0]['safe']; ?></h2>
          <?php endif; ?>
 <?php print render($page['content']); ?>

        </div>
      </div>

      <div class="clear"></div>

      <div id="footer">
   <?php print render($page['footer']); ?>
      </div>
    </div>
    <?php if ($page['devel_area']): ?>
      <div id="devel-area">;
        <?php print render($page['devel_area']); ?>
      </div>
    <?php endif; ?>
    <?php print $closure; ?>
  </body>
</html>
