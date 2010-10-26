<div id="block-<?php print $block->module .'-'. $block->delta; ?>" class="<?php print $extra_block_classes; ?> block block-<?php print $block->module ?>">

  <?php if ($block->subject): ?>
    <h4><?php print $block->subject ?></h4>
  <?php endif;?>

  <div class="content"><?php print $block->content ?></div>
</div>