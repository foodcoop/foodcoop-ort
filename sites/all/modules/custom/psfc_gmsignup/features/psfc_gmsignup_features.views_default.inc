<?php
/**
 * @file
 * psfc_gmsignup_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function psfc_gmsignup_features_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'general_meeting_attendees';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'General Meeting Attendees';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'General Meeting Attendees';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_gm_attendee_first_name' => 'field_gm_creditee_last_name',
    'field_gm_creditee_last_name' => 'field_gm_creditee_last_name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_gm_attendee_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'field_gm_creditee_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ', ',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['label'] = 'akdhff';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['external'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['counter']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['counter']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['html'] = 0;
  $handler->display->display_options['fields']['counter']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['counter']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['counter']['hide_empty'] = 0;
  $handler->display->display_options['fields']['counter']['empty_zero'] = 0;
  $handler->display->display_options['fields']['counter']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['id'] = 'field_gm_creditee_last_name';
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['table'] = 'field_data_field_gm_creditee_last_name';
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['field'] = 'field_gm_creditee_last_name';
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_gm_creditee_last_name']['field_api_classes'] = 0;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['id'] = 'field_gm_attendee_first_name';
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['table'] = 'field_data_field_gm_attendee_first_name';
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['field'] = 'field_gm_attendee_first_name';
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['fields']['field_gm_attendee_first_name']['field_api_classes'] = 0;
  /* Sort criterion: Content: Last Name (field_gm_attendee_last_name:format) */
  $handler->display->display_options['sorts']['field_gm_attendee_last_name_format']['id'] = 'field_gm_attendee_last_name_format';
  $handler->display->display_options['sorts']['field_gm_attendee_last_name_format']['table'] = 'field_data_field_gm_attendee_last_name';
  $handler->display->display_options['sorts']['field_gm_attendee_last_name_format']['field'] = 'field_gm_attendee_last_name_format';
  /* Contextual filter: Content: Meeting (field_gm) */
  $handler->display->display_options['arguments']['field_gm_nid']['id'] = 'field_gm_nid';
  $handler->display->display_options['arguments']['field_gm_nid']['table'] = 'field_data_field_gm';
  $handler->display->display_options['arguments']['field_gm_nid']['field'] = 'field_gm_nid';
  $handler->display->display_options['arguments']['field_gm_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_gm_nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_gm_nid']['default_argument_options']['code'] = '	$result = db_query(\'SELECT n.nid FROM {field_data_field_gm_date} fgmd JOIN node n ON fgmd.bundle=n.type AND fgmd.revision_id=n.vid WHERE fgmd.field_gm_date_value > UNIX_TIMESTAMP() ORDER BY fgmd.field_gm_date_value LIMIT 1\');

  return $result->fetchField();
';
  $handler->display->display_options['arguments']['field_gm_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_gm_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_gm_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_gm_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_gm_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_gm_nid']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'general_meeting_attendee' => 'general_meeting_attendee',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'gmsignup/print-roster';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_gm_date']['id'] = 'field_gm_date';
  $handler->display->display_options['fields']['field_gm_date']['table'] = 'field_data_field_gm_date';
  $handler->display->display_options['fields']['field_gm_date']['field'] = 'field_gm_date';
  $handler->display->display_options['fields']['field_gm_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_gm_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_gm_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_gm_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_gm_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_gm_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_gm_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_gm_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_gm_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_gm_date']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_gm_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_gm_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_gm_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_gm_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_gm_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_gm_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_gm_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_gm_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_gm_date']['settings'] = array(
    'format_type' => 'long_12_hour',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_gm_date']['field_api_classes'] = 0;
  /* Field: Content: Meeting Location */
  $handler->display->display_options['fields']['field_gm_location']['id'] = 'field_gm_location';
  $handler->display->display_options['fields']['field_gm_location']['table'] = 'field_data_field_gm_location';
  $handler->display->display_options['fields']['field_gm_location']['field'] = 'field_gm_location';
  $handler->display->display_options['fields']['field_gm_location']['label'] = '';
  $handler->display->display_options['fields']['field_gm_location']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_gm_location']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_gm_location']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_gm_location']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_gm_location']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_gm_location']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_gm_location']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_gm_location']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_gm_location']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_gm_location']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_gm_location']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_gm_location']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_gm_location']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_gm_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gm_location']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_gm_location']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_gm_location']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_gm_location']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_gm_location']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'general_meeting' => 'general_meeting',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['general_meeting_attendees'] = $view;

  return $export;
}
