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
    <div class="container_12">
      <div id="header">
        <div id="logo" class="grid_2">
          <!-- a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a -->
          <a href="http://foodcoop.com/" rel="home"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
        </div>
        <div class="clear"></div>
        <?php print $primary_links; ?>

      </div><!-- /header -->

      <div id="section-header">
        <!-- <h2>New Member Orientation</h2> -->
        <h1><?php print $title; ?></h1>
      </div>
      <div class="clear"></div>

      <div id="content" class="grid_12">
        <!-- h1><?php print $title; ?></h1 -->
        <div id="right-side">
          <div id="secondary-links">
            <?php print theme('links', $secondary_links); ?>
          </div>
          <?php print $right; ?>
        </div>
        <div id="main-content">
          <?php if ($messages): ?>
            <div id="message-section">
              <?php print $messages ?>
            </div>
          <?php endif; ?>
          <?php print $tabs ?>
          <?php print $content; ?>
        </div>
      </div>

      <div class="clear"></div>

      <div id="footer">
        <?php print $footer; ?>
      </div>
    </div>
    <?php if ($devel): ?>
     <?php print $devel; ?>
    <?php endif; ?>
    <?php print $closure; ?>
  </body>
</html>
