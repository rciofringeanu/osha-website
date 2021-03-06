<?php
/**
 * @file
 * osha_calls.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osha_calls_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'calls';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Calls';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Processed calls for contractors';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Publication Date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = '';
  $handler->display->display_options['fields']['field_publication_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Sort criterion: Content: Publication Date (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['order'] = 'DESC';
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
    'calls' => 'calls',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Publication Date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_publication_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Deadline (field_calls_deadline) */
  $handler->display->display_options['filters']['field_calls_deadline_value']['id'] = 'field_calls_deadline_value';
  $handler->display->display_options['filters']['field_calls_deadline_value']['table'] = 'field_data_field_calls_deadline';
  $handler->display->display_options['filters']['field_calls_deadline_value']['field'] = 'field_calls_deadline_value';
  $handler->display->display_options['filters']['field_calls_deadline_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_calls_deadline_value']['group'] = 1;
  $handler->display->display_options['filters']['field_calls_deadline_value']['default_date'] = 'now';
  /* Filter criterion: Workbench Moderation: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = '1';
  $handler->display->display_options['filters']['published']['group'] = 1;

  /* Display: Open */
  $handler = $view->new_display('block', 'Open', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Current calls for contractors';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
    3 => 'OR',
    4 => 'OR',
  );
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
    'calls' => 'calls',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Publication Date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date_value']['group'] = 3;
  $handler->display->display_options['filters']['field_publication_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Deadline (field_calls_deadline) */
  $handler->display->display_options['filters']['field_calls_deadline_value']['id'] = 'field_calls_deadline_value';
  $handler->display->display_options['filters']['field_calls_deadline_value']['table'] = 'field_data_field_calls_deadline';
  $handler->display->display_options['filters']['field_calls_deadline_value']['field'] = 'field_calls_deadline_value';
  $handler->display->display_options['filters']['field_calls_deadline_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_calls_deadline_value']['group'] = 2;
  $handler->display->display_options['filters']['field_calls_deadline_value']['default_date'] = 'now';
  /* Filter criterion: Workbench Moderation: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = '1';
  $handler->display->display_options['filters']['published']['group'] = 1;
  /* Filter criterion: Content: Deadline (field_calls_deadline) */
  $handler->display->display_options['filters']['field_calls_deadline_value_1']['id'] = 'field_calls_deadline_value_1';
  $handler->display->display_options['filters']['field_calls_deadline_value_1']['table'] = 'field_data_field_calls_deadline';
  $handler->display->display_options['filters']['field_calls_deadline_value_1']['field'] = 'field_calls_deadline_value';
  $handler->display->display_options['filters']['field_calls_deadline_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_calls_deadline_value_1']['group'] = 2;
  /* Filter criterion: Content: Publication Date (field_publication_date) */
  $handler->display->display_options['filters']['field_publication_date_value_1']['id'] = 'field_publication_date_value_1';
  $handler->display->display_options['filters']['field_publication_date_value_1']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_value_1']['field'] = 'field_publication_date_value';
  $handler->display->display_options['filters']['field_publication_date_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_publication_date_value_1']['group'] = 3;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_expiration_date_value']['group'] = 4;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value_1']['id'] = 'field_expiration_date_value_1';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['operator'] = '>';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['group'] = 4;
  $handler->display->display_options['filters']['field_expiration_date_value_1']['default_date'] = 'now';

  /* Display: Ongoing */
  $handler = $view->new_display('block', 'Ongoing', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Ongoing calls for contractors';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
    'calls' => 'calls',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Deadline (field_calls_deadline) */
  $handler->display->display_options['filters']['field_calls_deadline_value']['id'] = 'field_calls_deadline_value';
  $handler->display->display_options['filters']['field_calls_deadline_value']['table'] = 'field_data_field_calls_deadline';
  $handler->display->display_options['filters']['field_calls_deadline_value']['field'] = 'field_calls_deadline_value';
  $handler->display->display_options['filters']['field_calls_deadline_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_calls_deadline_value']['group'] = 1;
  $handler->display->display_options['filters']['field_calls_deadline_value']['default_date'] = 'now';
  /* Filter criterion: Workbench Moderation: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = '1';
  $handler->display->display_options['filters']['published']['group'] = 1;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_expiration_date_value']['group'] = 2;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value_1']['id'] = 'field_expiration_date_value_1';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['operator'] = '>';
  $handler->display->display_options['filters']['field_expiration_date_value_1']['group'] = 2;
  $handler->display->display_options['filters']['field_expiration_date_value_1']['default_date'] = 'now';

  /* Display: Archived calls page */
  $handler = $view->new_display('page', 'Archived calls page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Processed calls for contractors';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<a href="/articles/procurement">Back to calls</a>
';
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
    'calls' => 'calls',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Deadline (field_calls_deadline) */
  $handler->display->display_options['filters']['field_calls_deadline_value']['id'] = 'field_calls_deadline_value';
  $handler->display->display_options['filters']['field_calls_deadline_value']['table'] = 'field_data_field_calls_deadline';
  $handler->display->display_options['filters']['field_calls_deadline_value']['field'] = 'field_calls_deadline_value';
  $handler->display->display_options['filters']['field_calls_deadline_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_calls_deadline_value']['group'] = 1;
  $handler->display->display_options['filters']['field_calls_deadline_value']['default_date'] = 'now';
  /* Filter criterion: Workbench Moderation: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = '1';
  $handler->display->display_options['filters']['published']['group'] = 1;
  /* Filter criterion: Content: Expiration Date (field_expiration_date) */
  $handler->display->display_options['filters']['field_expiration_date_value']['id'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['table'] = 'field_data_field_expiration_date';
  $handler->display->display_options['filters']['field_expiration_date_value']['field'] = 'field_expiration_date_value';
  $handler->display->display_options['filters']['field_expiration_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_expiration_date_value']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'calls_archive';
  $translatables['calls'] = array(
    t('Master'),
    t('Processed calls for contractors'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Open'),
    t('Current calls for contractors'),
    t('Ongoing'),
    t('Ongoing calls for contractors'),
    t('Archived calls page'),
    t('<a href="/articles/procurement">Back to calls</a>
'),
  );
  $export['calls'] = $view;

  return $export;
}
