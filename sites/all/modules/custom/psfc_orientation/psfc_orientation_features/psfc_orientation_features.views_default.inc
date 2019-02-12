<?php

/**
 * @file
 * psfc_orientation_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function psfc_orientation_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'orientation_admin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Orientation Admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Upcoming orientations';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Field: Content: Orientation date */
  $handler->display->display_options['fields']['field_orientation_date']['id'] = 'field_orientation_date';
  $handler->display->display_options['fields']['field_orientation_date']['table'] = 'field_data_field_orientation_date';
  $handler->display->display_options['fields']['field_orientation_date']['field'] = 'field_orientation_date';
  $handler->display->display_options['fields']['field_orientation_date']['label'] = 'Date/Time';
  $handler->display->display_options['fields']['field_orientation_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_orientation_date']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'l, F j \\@g:i a',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Capacity */
  $handler->display->display_options['fields']['field_orientation_capacity']['id'] = 'field_orientation_capacity';
  $handler->display->display_options['fields']['field_orientation_capacity']['table'] = 'field_data_field_orientation_capacity';
  $handler->display->display_options['fields']['field_orientation_capacity']['field'] = 'field_orientation_capacity';
  $handler->display->display_options['fields']['field_orientation_capacity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_orientation_capacity']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Confirmed Attendees */
  $handler->display->display_options['fields']['field_confirmed_attendees']['id'] = 'field_confirmed_attendees';
  $handler->display->display_options['fields']['field_confirmed_attendees']['table'] = 'field_data_field_confirmed_attendees';
  $handler->display->display_options['fields']['field_confirmed_attendees']['field'] = 'field_confirmed_attendees';
  /* Field: Manage attendees link */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'Manage attendees link';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '<a href="/admin/psfc/orientation/attendee-manage/[nid]">Manage Attendees</a>';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: View roster link */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['ui_name'] = 'View roster link';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['alter']['text'] = ' <a href="/admin/psfc/orientation/attendee-roster/[nid_1]">View roster</a>';
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Orientation date (field_orientation_date) */
  $handler->display->display_options['sorts']['field_orientation_date_value']['id'] = 'field_orientation_date_value';
  $handler->display->display_options['sorts']['field_orientation_date_value']['table'] = 'field_data_field_orientation_date';
  $handler->display->display_options['sorts']['field_orientation_date_value']['field'] = 'field_orientation_date_value';
  $handler->display->display_options['sorts']['field_orientation_date_value']['order'] = 'DESC';
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
    'orientation' => 'orientation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Orientation date (field_orientation_date) */
  $handler->display->display_options['filters']['field_orientation_date_value']['id'] = 'field_orientation_date_value';
  $handler->display->display_options['filters']['field_orientation_date_value']['table'] = 'field_data_field_orientation_date';
  $handler->display->display_options['filters']['field_orientation_date_value']['field'] = 'field_orientation_date_value';
  $handler->display->display_options['filters']['field_orientation_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_orientation_date_value']['default_date'] = '-7 days';
  $export['orientation_admin'] = $view;

  $view = new view();
  $view->name = 'orientation_attendees';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Orientation Attendees';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Orientation Attendees';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_first_name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: Content: Email Address */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  /* Sort criterion: Content: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Contextual filter: Content: Orientation nid (field_orientation_nid) */
  $handler->display->display_options['arguments']['field_orientation_nid_nid']['id'] = 'field_orientation_nid_nid';
  $handler->display->display_options['arguments']['field_orientation_nid_nid']['table'] = 'field_data_field_orientation_nid';
  $handler->display->display_options['arguments']['field_orientation_nid_nid']['field'] = 'field_orientation_nid_nid';
  $handler->display->display_options['arguments']['field_orientation_nid_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_orientation_nid_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_orientation_nid_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_orientation_nid_nid']['summary_options']['items_per_page'] = '25';
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
    'orientation_attendee' => 'orientation_attendee',
  );
  /* Filter criterion: Content: Confirmed (field_confirmed_orientation) */
  $handler->display->display_options['filters']['field_confirmed_orientation_value']['id'] = 'field_confirmed_orientation_value';
  $handler->display->display_options['filters']['field_confirmed_orientation_value']['table'] = 'field_data_field_confirmed_orientation';
  $handler->display->display_options['filters']['field_confirmed_orientation_value']['field'] = 'field_confirmed_orientation_value';
  $handler->display->display_options['filters']['field_confirmed_orientation_value']['value'] = array(
    1 => '1',
  );

  /* Display: Roster */
  $handler = $view->new_display('page', 'Roster', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<strong>Orientation: %1</strong>

<a class="roster-print" href="/print/admin/psfc/orientation/attendee-roster/!1">Print</a>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<h2>Additional Registrants</h2>';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: Content: Email Address */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['type'] = 'email_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Attended?';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '&#9744;';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Orientation nid (field_orientation_nid) */
  $handler->display->display_options['arguments']['field_orientation_nid_nid']['id'] = 'field_orientation_nid_nid';
  $handler->display->display_options['arguments']['field_orientation_nid_nid']['table'] = 'field_data_field_orientation_nid';
  $handler->display->display_options['arguments']['field_orientation_nid_nid']['field'] = 'field_orientation_nid_nid';
  $handler->display->display_options['arguments']['field_orientation_nid_nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_orientation_nid_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_orientation_nid_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_orientation_nid_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_orientation_nid_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'orientation_attendee' => 'orientation_attendee',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Confirmed (field_confirmed_orientation) */
  $handler->display->display_options['filters']['field_confirmed_orientation_value']['id'] = 'field_confirmed_orientation_value';
  $handler->display->display_options['filters']['field_confirmed_orientation_value']['table'] = 'field_data_field_confirmed_orientation';
  $handler->display->display_options['filters']['field_confirmed_orientation_value']['field'] = 'field_confirmed_orientation_value';
  $handler->display->display_options['filters']['field_confirmed_orientation_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_confirmed_orientation_value']['group'] = 1;
  /* Filter criterion: Content: Canceled (field_canceled_orientation) */
  $handler->display->display_options['filters']['field_canceled_orientation_value']['id'] = 'field_canceled_orientation_value';
  $handler->display->display_options['filters']['field_canceled_orientation_value']['table'] = 'field_data_field_canceled_orientation';
  $handler->display->display_options['filters']['field_canceled_orientation_value']['field'] = 'field_canceled_orientation_value';
  $handler->display->display_options['filters']['field_canceled_orientation_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_canceled_orientation_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'admin/psfc/orientation/attendee-roster';

  /* Display: Roster Management */
  $handler = $view->new_display('page', 'Roster Management', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Mark as confirmed or attended',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'orientation_attendee::field_attended_orientation' => 'orientation_attendee::field_attended_orientation',
          'orientation_attendee::field_confirmed_orientation' => 'orientation_attendee::field_confirmed_orientation',
        ),
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 1,
      'postpone_processing' => 1,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid]';
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: Content: Email Address */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  /* Field: Content: Attended */
  $handler->display->display_options['fields']['field_attended_orientation']['id'] = 'field_attended_orientation';
  $handler->display->display_options['fields']['field_attended_orientation']['table'] = 'field_data_field_attended_orientation';
  $handler->display->display_options['fields']['field_attended_orientation']['field'] = 'field_attended_orientation';
  /* Field: Content: Confirmed */
  $handler->display->display_options['fields']['field_confirmed_orientation']['id'] = 'field_confirmed_orientation';
  $handler->display->display_options['fields']['field_confirmed_orientation']['table'] = 'field_data_field_confirmed_orientation';
  $handler->display->display_options['fields']['field_confirmed_orientation']['field'] = 'field_confirmed_orientation';
  /* Field: Content: Canceled */
  $handler->display->display_options['fields']['field_canceled_orientation']['id'] = 'field_canceled_orientation';
  $handler->display->display_options['fields']['field_canceled_orientation']['table'] = 'field_data_field_canceled_orientation';
  $handler->display->display_options['fields']['field_canceled_orientation']['field'] = 'field_canceled_orientation';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Canceled (field_canceled_orientation) */
  $handler->display->display_options['sorts']['field_canceled_orientation_value']['id'] = 'field_canceled_orientation_value';
  $handler->display->display_options['sorts']['field_canceled_orientation_value']['table'] = 'field_data_field_canceled_orientation';
  $handler->display->display_options['sorts']['field_canceled_orientation_value']['field'] = 'field_canceled_orientation_value';
  /* Sort criterion: Content: Confirmed (field_confirmed_orientation) */
  $handler->display->display_options['sorts']['field_confirmed_orientation_value']['id'] = 'field_confirmed_orientation_value';
  $handler->display->display_options['sorts']['field_confirmed_orientation_value']['table'] = 'field_data_field_confirmed_orientation';
  $handler->display->display_options['sorts']['field_confirmed_orientation_value']['field'] = 'field_confirmed_orientation_value';
  $handler->display->display_options['sorts']['field_confirmed_orientation_value']['order'] = 'DESC';
  /* Sort criterion: Content: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'orientation_attendee' => 'orientation_attendee',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/psfc/orientation/attendee-manage/%';
  $export['orientation_attendees'] = $view;

  $view = new view();
  $view->name = 'orientations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Orientations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Orientation date */
  $handler->display->display_options['fields']['field_orientation_date']['id'] = 'field_orientation_date';
  $handler->display->display_options['fields']['field_orientation_date']['table'] = 'field_data_field_orientation_date';
  $handler->display->display_options['fields']['field_orientation_date']['field'] = 'field_orientation_date';
  $handler->display->display_options['fields']['field_orientation_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_orientation_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_orientation_date']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'l, F j, Y \\@g:i a',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '<a href="/join/orientation/signup/session/[nid]">I want this one</a>';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
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
    'orientation' => 'orientation',
  );
  /* Filter criterion: Content: Closed (field_orientation_closed) */
  $handler->display->display_options['filters']['field_orientation_closed_value']['id'] = 'field_orientation_closed_value';
  $handler->display->display_options['filters']['field_orientation_closed_value']['table'] = 'field_data_field_orientation_closed';
  $handler->display->display_options['filters']['field_orientation_closed_value']['field'] = 'field_orientation_closed_value';
  $handler->display->display_options['filters']['field_orientation_closed_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_orientation_closed_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_orientation_closed_value']['reduce_duplicates'] = TRUE;
  $export['orientations'] = $view;

  return $export;
}
