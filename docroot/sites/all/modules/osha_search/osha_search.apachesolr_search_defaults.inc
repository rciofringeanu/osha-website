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
  $searcher->page_id = 'search_wiki';
  $searcher->label = 'Search Wiki';
  $searcher->description = '';
  $searcher->search_path = 'search/oshwiki';
  $searcher->page_title = 'OSHWiki';
  $searcher->env_id = 'solr';
  $searcher->settings = array(
    'fq' => array(
      0 => 'bundle:wiki_page',
    ),
    'apachesolr_search_custom_enable' => 1,
    'apachesolr_search_search_type' => 'bundle',
    'apachesolr_search_per_page' => 50,
    'apachesolr_search_spellcheck' => 0,
    'apachesolr_search_search_box' => 1,
    'apachesolr_search_allow_user_input' => 0,
    'apachesolr_search_browse' => 'none',
  );
  $export['search_wiki'] = $searcher;

  return $export;
}
