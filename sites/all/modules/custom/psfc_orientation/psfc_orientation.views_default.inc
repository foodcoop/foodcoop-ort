<?php
/**
 * Implementation of hook_views_default_views().
 */
function psfc_orientation_views_default_views() {
  /*
   * View 'orientation_admin'
   */
  $view = new view;
  $view->name = 'orientation_admin';
  $view->description = 'Administrative views for orientation';
  $view->tag = 'orientation psfc';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => 'Upcoming Orientations',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'field_capacity_value' => array(
      'label' => 'Capacity',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'custom',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_capacity_value',
      'table' => 'node_data_field_capacity',
      'field' => 'field_capacity_value',
      'relationship' => 'none',
    ),
    'phpcode_2' => array(
      'label' => 'Open seats',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'value' => '<?php
 print psfc_orientation_capacity($data->nid, $close = FALSE);
?>',
      'exclude' => 0,
      'id' => 'phpcode_2',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'field_open_value' => array(
      'label' => 'Open/Closed',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'custom',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_open_value',
      'table' => 'node_data_field_open',
      'field' => 'field_open_value',
      'relationship' => 'none',
    ),
    'phpcode_1' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'value' => '<?php print l(\'Manage attendees\', \'admin/psfc/orientation/attendee-manage/\'. $data->nid); ?>',
      'exclude' => 0,
      'id' => 'phpcode_1',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'phpcode' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'value' => '<?php print l(\'View roster\', \'admin/psfc/orientation/attendee-roster/\'. $data->nid); ?>',
      'exclude' => 0,
      'id' => 'phpcode',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'edit_node' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'text' => '',
      'exclude' => 0,
      'id' => 'edit_node',
      'table' => 'node',
      'field' => 'edit_node',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'field_date_value' => array(
      'order' => 'ASC',
      'delta' => -1,
      'id' => 'field_date_value',
      'table' => 'node_data_field_date',
      'field' => 'field_date_value',
      'relationship' => 'none',
    ),
    'field_date_value_1' => array(
      'order' => 'ASC',
      'delta' => -1,
      'id' => 'field_date_value_1',
      'table' => 'node_data_field_date',
      'field' => 'field_date_value',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'orientation' => 'orientation',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'date_filter' => array(
      'operator' => '>=',
      'value' => array(
        'value' => NULL,
        'min' => NULL,
        'max' => NULL,
        'default_date' => 'now',
        'default_to_date' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'date_fields' => array(
        'node_data_field_date.field_date_value' => 'node_data_field_date.field_date_value',
      ),
      'date_method' => 'OR',
      'granularity' => 'day',
      'form_type' => 'date_select',
      'default_date' => 'now',
      'default_to_date' => '',
      'year_range' => '-0:+3',
      'id' => 'date_filter',
      'table' => 'node',
      'field' => 'date_filter',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'role',
    'role' => array(
      '4' => 4,
      '5' => 5,
    ),
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Upcoming Orientations');
  $handler->override_option('empty', 'There are no upcoming orientations');
  $handler->override_option('empty_format', '1');
  $handler->override_option('items_per_page', 0);
  $handler->override_option('style_plugin', 'table');
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => 'Orientations',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'field_capacity_value' => array(
      'label' => 'Capacity',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'custom',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_capacity_value',
      'table' => 'node_data_field_capacity',
      'field' => 'field_capacity_value',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'field_open_value' => array(
      'label' => 'Open/Closed',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'custom',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_open_value',
      'table' => 'node_data_field_open',
      'field' => 'field_open_value',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);
  $views[$view->name] = $view;

/*
  * View 'orientations'
  */
$view = new view;
$view->name = 'orientations';
$view->description = 'Upcoming orientations - user facing';
$view->tag = 'orientation psfc';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('fields', array(
  'nid' => array(
    'label' => 'Nid - excluded',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'exclude' => 1,
    'id' => 'nid',
    'table' => 'node',
    'field' => 'nid',
    'relationship' => 'none',
  ),
  'field_date_value' => array(
    'label' => 'Date',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'custom',
    'format' => 'mon_date',
    'multiple' => array(
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'group' => TRUE,
    ),
    'repeat' => array(
      'show_repeat_rule' => '',
    ),
    'fromto' => array(
      'fromto' => 'both',
    ),
    'exclude' => 0,
    'id' => 'field_date_value',
    'table' => 'node_data_field_date',
    'field' => 'field_date_value',
    'relationship' => 'none',
  ),
  'field_date_value_1' => array(
    'label' => 'Day',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'custom',
    'format' => 'day',
    'multiple' => array(
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'group' => TRUE,
    ),
    'repeat' => array(
      'show_repeat_rule' => '',
    ),
    'fromto' => array(
      'fromto' => 'both',
    ),
    'exclude' => 0,
    'id' => 'field_date_value_1',
    'table' => 'node_data_field_date',
    'field' => 'field_date_value',
    'relationship' => 'none',
  ),
  'field_date_value_2' => array(
    'label' => 'Time',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'custom',
    'format' => 'time',
    'multiple' => array(
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'group' => TRUE,
    ),
    'repeat' => array(
      'show_repeat_rule' => '',
    ),
    'fromto' => array(
      'fromto' => 'both',
    ),
    'exclude' => 0,
    'id' => 'field_date_value_2',
    'table' => 'node_data_field_date',
    'field' => 'field_date_value',
    'relationship' => 'none',
  ),
  'phpcode_1' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'value' => '<?php
print psfc_orientation_signup_link($data->nid);
?>',
    'exclude' => 0,
    'id' => 'phpcode_1',
    'table' => 'customfield',
    'field' => 'phpcode',
    'relationship' => 'none',
  ),
  'phpcode' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'value' => '<?php
    global $user;
    if ($user->uid > 0) {
      if (psfc_orientation_capacity($data->nid) <= 3) {
        print \'<div class="only-three">\' . t(\'Fewer than 3 spots available\') . \'</div>\';
      }
    }
?>',
    'exclude' => 0,
    'id' => 'phpcode',
    'table' => 'customfield',
    'field' => 'phpcode',
    'relationship' => 'none',
  ),
));
$handler->override_option('sorts', array(
  'field_date_value' => array(
    'order' => 'ASC',
    'delta' => -1,
    'id' => 'field_date_value',
    'table' => 'node_data_field_date',
    'field' => 'field_date_value',
    'relationship' => 'none',
  ),
));
$handler->override_option('filters', array(
  'status' => array(
    'operator' => '=',
    'value' => '1',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'status',
    'table' => 'node',
    'field' => 'status',
    'relationship' => 'none',
  ),
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'orientation' => 'orientation',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'type',
    'table' => 'node',
    'field' => 'type',
    'relationship' => 'none',
  ),
  'date_filter' => array(
    'operator' => '>=',
    'value' => array(
      'value' => NULL,
      'min' => NULL,
      'max' => NULL,
      'default_date' => 'now +1 hour',
      'default_to_date' => '',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'date_fields' => array(
      'node_data_field_date.field_date_value' => 'node_data_field_date.field_date_value',
    ),
    'date_method' => 'OR',
    'granularity' => 'day',
    'form_type' => 'date_select',
    'default_date' => 'now +1 hour',
    'default_to_date' => '',
    'year_range' => '-0:+3',
    'id' => 'date_filter',
    'table' => 'node',
    'field' => 'date_filter',
    'relationship' => 'none',
    'override' => array(
      'button' => 'Override',
    ),
  ),
  'field_open_value' => array(
    'operator' => '=',
    'value' => '0',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'case' => 0,
    'id' => 'field_open_value',
    'table' => 'node_data_field_open',
    'field' => 'field_open_value',
    'relationship' => 'none',
  ),
));
$handler->override_option('access', array(
  'type' => 'none',
));
$handler->override_option('cache', array(
  'type' => 'none',
));
$handler->override_option('title', 'Sign up for an orientation session');
$handler->override_option('footer', '<?php
$nid = variable_get(\'psfc_orientation_upcoming_orientations\', 36);
$footer_txt = node_load($nid);
drupal_set_title(t($footer_txt->title));
unset($footer_txt->title);
$out = node_view($footer_txt);
if (user_access(\'administer psfc orientation\') && user_access(\'administer nodes\')) {
$out .= l(\'edit\', "node/". $nid ."/edit");
}

return $out;
?>');
$handler->override_option('footer_format', '3');
$handler->override_option('footer_empty', 0);
$handler->override_option('empty', '<?php
$nid = variable_get(\'psfc_orientation_no_orientations\', 35);
$empty_txt = node_load($nid);
drupal_set_title(t($empty_txt->title));
unset($empty_txt->title);
$out = node_view($empty_txt);
if (user_access(\'administer psfc orientation\') && user_access(\'administer nodes\')) {
$out .= l(\'edit\', "node/". $nid ."/edit");
}
return $out;
?>');
$handler->override_option('empty_format', '3');
$handler->override_option('items_per_page', 0);
$handler->override_option('style_plugin', 'table');
$handler = $view->new_display('page', 'Page', 'page_1');
$handler->override_option('path', 'join/orientation');
$handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => '',
    'name' => '',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('header', '<?php
$nid = variable_get(\'psfc_orientation_upcoming_orientations\', 36);
$node = node_load($nid);
$txt = check_markup($node->field_subhead[0][\'value\']);
print \'<h2>\'. $txt .\'</h2>\';
?>');
$handler->override_option('header_format', '3');
$handler->override_option('header_empty', 0);

$views[$view->name] = $view;

  /*
   * View 'orientation_attendees'
   */
$view = new view;
$view->name = 'orientation_attendees';
$view->description = 'List of orientation attendees';
$view->tag = 'orientation psfc';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('fields', array(
  'rownumber' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'exclude' => 0,
    'id' => 'rownumber',
    'table' => 'customfield',
    'field' => 'rownumber',
    'relationship' => 'none',
  ),
  'field_firstname_value' => array(
    'label' => 'First Name',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_firstname_value',
    'table' => 'node_data_field_firstname',
    'field' => 'field_firstname_value',
    'relationship' => 'none',
  ),
  'field_lastname_value' => array(
    'label' => 'Last Name',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_lastname_value',
    'table' => 'node_data_field_lastname',
    'field' => 'field_lastname_value',
    'relationship' => 'none',
  ),
  'field_email_email' => array(
    'label' => 'Email Address',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 1,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_email_email',
    'table' => 'node_data_field_email',
    'field' => 'field_email_email',
    'relationship' => 'none',
  ),
  'markup' => array(
    'label' => 'Attended',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'value' => '<div class="roster-checkbox"></div>',
    'format' => '2',
    'exclude' => 0,
    'id' => 'markup',
    'table' => 'customfield',
    'field' => 'markup',
    'relationship' => 'none',
  ),
));
$handler->override_option('arguments', array(
  'field_orientation_nid_nid' => array(
    'default_action' => 'not found',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => '%1',
    'breadcrumb' => '',
    'default_argument_type' => 'fixed',
    'default_argument' => '',
    'validate_type' => 'node',
    'validate_fail' => 'not found',
    'break_phrase' => 0,
    'not' => 0,
    'id' => 'field_orientation_nid_nid',
    'table' => 'node_data_field_orientation_nid',
    'field' => 'field_orientation_nid_nid',
    'validate_user_argument_type' => 'uid',
    'validate_user_roles' => array(
      '2' => 0,
      '3' => 0,
    ),
    'relationship' => 'none',
    'default_options_div_prefix' => '',
    'default_argument_fixed' => '',
    'default_argument_user' => 0,
    'default_argument_php' => '',
    'validate_argument_node_type' => array(
      'orientation' => 'orientation',
      'orientation_attendee' => 0,
      'page' => 0,
      'story' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(),
    'validate_argument_type' => 'tid',
    'validate_argument_transform' => 0,
    'validate_user_restrict_roles' => 0,
    'validate_argument_php' => '',
  ),
));
$handler->override_option('filters', array(
  'field_attendee_confirmed_value' => array(
    'operator' => '=',
    'value' => '1',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => 'field_attendee_confirmed_value_op',
      'label' => 'Content: Confirmed (field_attendee_confirmed)',
      'use_operator' => FALSE,
      'identifier' => 'field_attendee_confirmed_value',
      'remember' => FALSE,
      'single' => TRUE,
      'optional' => TRUE,
    ),
    'case' => 1,
    'id' => 'field_attendee_confirmed_value',
    'table' => 'node_data_field_attendee_confirmed',
    'field' => 'field_attendee_confirmed_value',
    'relationship' => 'none',
    'override' => array(
      'button' => 'Override',
    ),
  ),
  'type' => array(
    'id' => 'type',
    'table' => 'node',
    'field' => 'type',
  ),
));
$handler->override_option('access', array(
  'type' => 'perm',
  'perm' => 'administer orientation attendance',
));
$handler->override_option('cache', array(
  'type' => 'none',
));
$handler->override_option('items_per_page', 0);
$handler->override_option('style_plugin', 'table');
$handler = $view->new_display('page', 'Roster', 'page_1');
$handler->override_option('filters', array(
  'type' => array(
    'id' => 'type',
    'table' => 'node',
    'field' => 'type',
  ),
  'field_attendee_confirmed_value_many_to_one' => array(
    'operator' => 'or',
    'value' => array(
      '1' => '1',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'field_attendee_confirmed_value_many_to_one',
    'table' => 'node_data_field_attendee_confirmed',
    'field' => 'field_attendee_confirmed_value_many_to_one',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
    'reduce_duplicates' => 0,
  ),
));
$handler->override_option('path', 'admin/psfc/orientation/attendee-roster/%');
$handler->override_option('menu', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler = $view->new_display('attachment', 'Registered by phone Roster Attachment', 'attachment_1');
$handler->override_option('fields', array(
  'rownumber' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'exclude' => 0,
    'id' => 'rownumber',
    'table' => 'customfield',
    'field' => 'rownumber',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
  'field_orientation_by_phone_value' => array(
    'label' => 'Registered by phone',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => 0,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => 0,
    ),
    'exclude' => 0,
    'id' => 'field_orientation_by_phone_value',
    'table' => 'node_data_field_orientation_by_phone',
    'field' => 'field_orientation_by_phone_value',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
  'markup' => array(
    'label' => 'Attended',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'value' => '<div class="roster-checkbox"></div>',
    'format' => '2',
    'exclude' => 0,
    'id' => 'markup',
    'table' => 'customfield',
    'field' => 'markup',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
  'field_attendee_attended_value' => array(
    'label' => 'Attended',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_attendee_attended_value',
    'table' => 'node_data_field_attendee_attended',
    'field' => 'field_attendee_attended_value',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('arguments', array(
  'nid' => array(
    'default_action' => 'not found',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => '',
    'breadcrumb' => '',
    'default_argument_type' => 'fixed',
    'default_argument' => '',
    'validate_type' => 'none',
    'validate_fail' => 'not found',
    'break_phrase' => 0,
    'not' => 0,
    'id' => 'nid',
    'table' => 'node',
    'field' => 'nid',
    'validate_user_argument_type' => 'uid',
    'validate_user_roles' => array(
      '2' => 0,
      '3' => 0,
    ),
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
    'default_options_div_prefix' => '',
    'default_argument_fixed' => '',
    'default_argument_user' => 0,
    'default_argument_php' => '',
    'validate_argument_node_type' => array(
      'orientation' => 0,
      'orientation_attendee' => 0,
      'page' => 0,
      'story' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(),
    'validate_argument_type' => 'tid',
    'validate_argument_transform' => 0,
    'validate_user_restrict_roles' => 0,
    'validate_argument_php' => '',
  ),
));
$handler->override_option('filters', array());
$handler->override_option('attachment_position', 'after');
$handler->override_option('inherit_arguments', TRUE);
$handler->override_option('inherit_exposed_filters', FALSE);
$handler->override_option('inherit_pager', FALSE);
$handler->override_option('render_pager', TRUE);
$handler->override_option('displays', array(
  'page_1' => 'page_1',
  'default' => 0,
));
$handler = $view->new_display('attachment', 'Manage registered by phone Roster Attachment', 'attachment_3');
$handler->override_option('fields', array(
  'rownumber' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'exclude' => 0,
    'id' => 'rownumber',
    'table' => 'customfield',
    'field' => 'rownumber',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
  'field_orientation_by_phone_value' => array(
    'label' => 'Registered by phone',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => 0,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => 0,
    ),
    'exclude' => 0,
    'id' => 'field_orientation_by_phone_value',
    'table' => 'node_data_field_orientation_by_phone',
    'field' => 'field_orientation_by_phone_value',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
  'field_attendee_attended_value' => array(
    'label' => 'Attended',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_attendee_attended_value',
    'table' => 'node_data_field_attendee_attended',
    'field' => 'field_attendee_attended_value',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
  'edit_node' => array(
    'label' => 'Manage by editing the ort.',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 1,
    'empty_zero' => 0,
    'text' => 'Manage',
    'exclude' => 0,
    'id' => 'edit_node',
    'table' => 'node',
    'field' => 'edit_node',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('arguments', array(
  'nid' => array(
    'default_action' => 'not found',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => '',
    'breadcrumb' => '',
    'default_argument_type' => 'fixed',
    'default_argument' => '',
    'validate_type' => 'none',
    'validate_fail' => 'not found',
    'break_phrase' => 0,
    'not' => 0,
    'id' => 'nid',
    'table' => 'node',
    'field' => 'nid',
    'validate_user_argument_type' => 'uid',
    'validate_user_roles' => array(
      '2' => 0,
      '3' => 0,
    ),
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
    'default_options_div_prefix' => '',
    'default_argument_fixed' => '',
    'default_argument_user' => 0,
    'default_argument_php' => '',
    'validate_argument_node_type' => array(
      'orientation' => 0,
      'orientation_attendee' => 0,
      'page' => 0,
      'story' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(),
    'validate_argument_type' => 'tid',
    'validate_argument_transform' => 0,
    'validate_user_restrict_roles' => 0,
    'validate_argument_php' => '',
  ),
));
$handler->override_option('filters', array());
$handler->override_option('attachment_position', 'after');
$handler->override_option('inherit_arguments', TRUE);
$handler->override_option('inherit_exposed_filters', FALSE);
$handler->override_option('inherit_pager', FALSE);
$handler->override_option('render_pager', TRUE);
$handler->override_option('displays', array(
  'page_2' => 'page_2',
  'default' => 0,
  'page_1' => 0,
));
$handler = $view->new_display('page', 'Manage page', 'page_2');
$handler->override_option('fields', array(
  'field_firstname_value' => array(
    'label' => 'First Name',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_firstname_value',
    'table' => 'node_data_field_firstname',
    'field' => 'field_firstname_value',
    'relationship' => 'none',
  ),
  'field_lastname_value' => array(
    'label' => 'Last Name',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_lastname_value',
    'table' => 'node_data_field_lastname',
    'field' => 'field_lastname_value',
    'relationship' => 'none',
  ),
  'field_email_email' => array(
    'label' => 'Email Address',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_email_email',
    'table' => 'node_data_field_email',
    'field' => 'field_email_email',
    'relationship' => 'none',
    'override' => array(
      'button' => 'Use default',
    ),
  ),
  'field_attendee_confirmed_value' => array(
    'label' => 'Confirmation status',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'custom',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_attendee_confirmed_value',
    'table' => 'node_data_field_attendee_confirmed',
    'field' => 'field_attendee_confirmed_value',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
  'field_attendee_attended_value' => array(
    'label' => 'Attended',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_attendee_attended_value',
    'table' => 'node_data_field_attendee_attended',
    'field' => 'field_attendee_attended_value',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('filters', array(
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'orientation_attendee' => 'orientation_attendee',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'type',
    'table' => 'node',
    'field' => 'type',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('header', '<?php
print l(t(\'Go back to main orientations admin page.\'), \'admin/psfc/orientation\');
?>');
$handler->override_option('header_format', '3');
$handler->override_option('header_empty', 0);
$handler->override_option('style_plugin', 'bulk');
$handler->override_option('style_options', array(
  'grouping' => '',
  'override' => 1,
  'sticky' => 1,
  'order' => 'asc',
  'columns' => array(
    'field_firstname_value' => 'field_firstname_value',
    'field_lastname_value' => 'field_lastname_value',
    'field_email_email' => 'field_email_email',
    'field_attendee_confirmed_value' => 'field_attendee_confirmed_value',
    'field_attendee_attended_value' => 'field_attendee_attended_value',
  ),
  'info' => array(
    'field_firstname_value' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'field_lastname_value' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'field_email_email' => array(
      'sortable' => 0,
      'separator' => ' | ',
    ),
    'field_attendee_confirmed_value' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'field_attendee_attended_value' => array(
      'sortable' => 0,
      'separator' => '',
    ),
  ),
  'default' => 'field_lastname_value',
  'execution_type' => '1',
  'display_type' => '0',
  'hide_select_all' => 0,
  'skip_confirmation' => 0,
  'display_result' => 1,
  'merge_single_action' => 1,
  'selected_operations' => array(
    'psfc_orientation_mass_attendee_helper:4fcda3b99e93133ba1dad2171b5d860f' => 'psfc_orientation_mass_attendee_helper:4fcda3b99e93133ba1dad2171b5d860f',
    'views_bulk_operations_delete_node_action' => 'views_bulk_operations_delete_node_action',
    'views_bulk_operations_fields_action' => 'views_bulk_operations_fields_action',
    'system_send_email_action' => 'system_send_email_action',
    'psfc_orientation_mass_attendee_helper:2818a845396f77474e6b8bea31a26c4b' => 'psfc_orientation_mass_attendee_helper:2818a845396f77474e6b8bea31a26c4b',
    'node_assign_owner_action' => 0,
    'node_mass_update:a27b9efabcd054685a549378b174ad11' => 0,
    'system_message_action' => 0,
    'views_bulk_operations_action' => 0,
    'views_bulk_operations_script_action' => 0,
    'node_make_sticky_action' => 0,
    'node_make_unsticky_action' => 0,
    'node_mass_update:c4d3b28efb86fd703619a50b74d43794' => 0,
    'views_bulk_operations_taxonomy_action' => 0,
    'views_bulk_operations_argument_selector_action' => 0,
    'node_promote_action' => 0,
    'node_mass_update:14de7d028b4bffdf2b4a266562ca18ac' => 0,
    'node_mass_update:9c585624b9b3af0b4687d5f97f35e047' => 0,
    'node_publish_action' => 0,
    'system_goto_action' => 0,
    'node_unpromote_action' => 0,
    'node_mass_update:8ce21b08bb8e773d10018b484fe4815e' => 0,
    'node_save_action' => 0,
    'node_mass_update:0ccad85c1ebe4c9ceada1aa64293b080' => 0,
    'node_unpublish_action' => 0,
    'node_unpublish_by_keyword_action' => 0,
    'auto_nodetitle_operations_update' => 0,
    'pathauto_node_update_alias_multiple:620e193b20ba9caa374fea9ca0ad38f0' => 0,
  ),
  'views_bulk_operations_fields_action' => array(
    'php_code' => 0,
    'display_fields' => array(
      'field_attendee_attended' => 'field_attendee_attended',
    ),
    '_error_element_base' => 'style_options][views_bulk_operations_fields_action][',
  ),
));
$handler->override_option('path', 'admin/psfc/orientation/attendee-manage');
$handler->override_option('menu', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler = $view->new_display('attachment', 'Non Confirmed Attendee Attachment', 'attachment_2');
$handler->override_option('fields', array(
  'field_orientation_unconfirmed_value' => array(
    'label' => 'People who missed their confirmation window',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'custom',
    'format' => 'default',
    'multiple' => array(
      'group' => 0,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => 0,
    ),
    'exclude' => 0,
    'id' => 'field_orientation_unconfirmed_value',
    'table' => 'node_data_field_orientation_unconfirmed',
    'field' => 'field_orientation_unconfirmed_value',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('arguments', array(
  'nid' => array(
    'default_action' => 'not found',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => '',
    'breadcrumb' => '',
    'default_argument_type' => 'fixed',
    'default_argument' => '',
    'validate_type' => 'node',
    'validate_fail' => 'not found',
    'break_phrase' => 0,
    'not' => 0,
    'id' => 'nid',
    'table' => 'node',
    'field' => 'nid',
    'validate_user_argument_type' => 'uid',
    'validate_user_roles' => array(
      '2' => 0,
      '3' => 0,
      '4' => 0,
      '5' => 0,
    ),
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
    'default_options_div_prefix' => '',
    'default_argument_fixed' => '',
    'default_argument_user' => 0,
    'default_argument_php' => '',
    'validate_argument_node_type' => array(
      'orientation' => 'orientation',
      'orientation_attendee' => 0,
      'page' => 0,
      'story' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(),
    'validate_argument_type' => 'tid',
    'validate_argument_transform' => 0,
    'validate_user_restrict_roles' => 0,
    'validate_argument_php' => '',
  ),
));
$handler->override_option('filters', array());
$handler->override_option('attachment_position', 'after');
$handler->override_option('inherit_arguments', TRUE);
$handler->override_option('inherit_exposed_filters', FALSE);
$handler->override_option('inherit_pager', FALSE);
$handler->override_option('render_pager', TRUE);
$handler->override_option('displays', array(
  'page_2' => 'page_2',
  'default' => 0,
  'page_1' => 0,
));

  $views[$view->name] = $view;

/*
 * List of upcoming orientations.
 */
  $view = new view;
  $view->name = 'orientations_list';
  $view->description = 'Upcoming orientations - internal use';
  $view->tag = 'orientation psfc';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'nid' => array(
      'label' => 'Nid - excluded',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'exclude' => 1,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'relationship' => 'none',
    ),
    'field_date_value_2' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'custom',
      'format' => 'long',
      'multiple' => array(
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'group' => TRUE,
      ),
      'repeat' => array(
        'show_repeat_rule' => '',
      ),
      'fromto' => array(
        'fromto' => 'both',
      ),
      'exclude' => 0,
      'id' => 'field_date_value_2',
      'table' => 'node_data_field_date',
      'field' => 'field_date_value',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'field_date_value' => array(
      'order' => 'ASC',
      'delta' => -1,
      'id' => 'field_date_value',
      'table' => 'node_data_field_date',
      'field' => 'field_date_value',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'orientation' => 'orientation',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'date_filter' => array(
      'operator' => '>=',
      'value' => array(
        'value' => NULL,
        'min' => NULL,
        'max' => NULL,
        'default_date' => 'now',
        'default_to_date' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'date_fields' => array(
        'node_data_field_date.field_date_value' => 'node_data_field_date.field_date_value',
      ),
      'date_method' => 'OR',
      'granularity' => 'day',
      'form_type' => 'date_select',
      'default_date' => 'now',
      'default_to_date' => '',
      'year_range' => '-0:+3',
      'id' => 'date_filter',
      'table' => 'node',
      'field' => 'date_filter',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Sign up for an orientation session');
  $handler->override_option('footer', '<?php
  $nid = variable_get(\'psfc_orientation_upcoming_orientations\', 36);
  $footer_txt = node_load($nid);
  drupal_set_title(t($footer_txt->title));
  unset($footer_txt->title);
  $out = node_view($footer_txt);
  if (user_access(\'administer psfc orientation\') && user_access(\'administer nodes\')) {
  $out .= l(\'edit\', "node/". $nid ."/edit");
  }

  return $out;
  ?>');
  $handler->override_option('footer_format', '3');
  $handler->override_option('footer_empty', 0);
  $handler->override_option('empty', '<?php
  $nid = variable_get(\'psfc_orientation_no_orientations\', 35);
  $empty_txt = node_load($nid);
  drupal_set_title(t($empty_txt->title));
  unset($empty_txt->title);
  $out = node_view($empty_txt);
  if (user_access(\'administer psfc orientation\') && user_access(\'administer nodes\')) {
  $out .= l(\'edit\', "node/". $nid ."/edit");
  }
  return $out;
  ?>');
  $handler->override_option('empty_format', '3');
  $handler->override_option('items_per_page', 0);
  $handler->override_option('style_options', array(
    'grouping' => '',
  ));
  $views[$view->name] = $view;
  return $views;
}
