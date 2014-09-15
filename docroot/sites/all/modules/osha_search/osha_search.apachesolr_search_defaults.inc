<?php
/**
 * @file
 * osha_search.apachesolr_search_defaults.inc
 */

/**
 * Implements hook_apachesolr_search_default_searchers().
 */
function osha_search_apachesolr_search_default_searchers() {
  $export = array();

  $searcher = new stdClass();
  $searcher->disabled = FALSE; /* Edit this to true to make a default searcher disabled initially */
  $searcher->api_version = 3;
  $searcher->page_id = 'page_search_wiki';
  $searcher->label = 'OSHWiki search page';
  $searcher->description = 'OSHWiki search ';
  $searcher->search_path = 'search/wiki';
  $searcher->page_title = 'OSHWiki';
  $searcher->env_id = 'solr';
  $searcher->settings = array(
    'fq' => array(
      0 => 'bundle:wiki_page',
    ),
    'apachesolr_search_custom_enable' => 1,
    'apachesolr_search_search_type' => 'custom',
    'apachesolr_search_per_page' => 10,
    'apachesolr_search_spellcheck' => 0,
    'apachesolr_search_search_box' => 1,
    'apachesolr_search_allow_user_input' => 0,
    'apachesolr_search_browse' => 'none',
    'apachesolr_multilingual_auto_language_filter' => 1,
    'apachesolr_multilingual_auto_language_filter_detachable' => 1,
    'apachesolr_multilingual_show_language_undefined_results' => 0,
  );
  $export['page_search_wiki'] = $searcher;

  return $export;
}
