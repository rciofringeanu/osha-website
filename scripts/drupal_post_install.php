<?php

if (function_exists('drush_log')) {
  drush_log('Executing post-install tasks ...', 'ok');
}

osha_configure_default_themes();
osha_configure_solr();
osha_change_field_size();
osha_configure_mailsystem();
osha_configure_htmlmail();
osha_configure_simplenews();
osha_configure_newsletter_category();
osha_configure_imce();
osha_configure_file_translator();

module_disable(array('overlay'));

/**
 * Configure the apachesolr and search_api_solr modules with proper settings.
 */
function osha_configure_solr() {
  $config_file = sprintf('%s/../conf/config.json', dirname(__FILE__));
  if (!is_readable($config_file)) {
    drupal_set_message("Cannot read configuration file!", 'warning');
    return;
  }
  $cfg = json_decode(file_get_contents($config_file), TRUE);
  if (empty($cfg)) {
    drupal_set_message('Configuration file was empty, nothing to do here', 'warning');
    return;
  }
  $cfg = array_merge(
    array(
      'name' => 'Solr server',
      'enabled' => 1,
      'description' => 'Search server',
      'scheme' => 'http',
      'host' => 'localhost',
      'port' => '8983',
      'path' => '/solr',
      'http_user' => '',
      'http_password' => '',
      'excerpt' => NULL,
      'retrieve_data' => NULL,
      'highlight_data' => NULL,
      'skip_schema_check' => NULL,
      'solr_version' => '',
      'http_method' => 'AUTO',
    ), $cfg['solr_server']
  );

  if (module_exists('search_api_solr') && module_load_include('inc', 'search_api', 'search_api.admin')) {
    drupal_set_message('Configuring search_api_solr ...');
    $form_state = array(
      'values' => array(
        'machine_name' => 'solr_server',
        'class' => 'search_api_solr_service',
        'name' => $cfg['name'],
        'enabled' => $cfg['enabled'],
        'description' => $cfg['description'],
        'options' => array(
          'form' => array(
            'scheme' => $cfg['scheme'],
            'host' => $cfg['host'],
            'port' => $cfg['port'],
            'path' => $cfg['path'],
            'http' => array(
              'http_user' => $cfg['http_user'],
              'http_pass' => $cfg['http_pass'],
            ),
            'advanced' => array(
              'excerpt' => $cfg['excerpt'],
              'retrieve_data' => $cfg['retrieve_data'],
              'highlight_data' => $cfg['highlight_data'],
              'skip_schema_check' => $cfg['skip_schema_check'],
              'solr_version' => $cfg['solr_version'],
              'http_method' => $cfg['http_method'],
            ),
          ),
        ),
      ),
    );
    drupal_form_submit('search_api_admin_add_server', $form_state);
  }

  // Configure apachesolr: submit apachesolr_environment_edit_form
  if (module_exists('apachesolr') && module_load_include('inc', 'apachesolr', 'apachesolr.admin')) {
    drupal_set_message('Configuring apachesolr ...');

    $url = sprintf('%s://%s:%s%s', $cfg['scheme'], $cfg['host'], $cfg['port'], $cfg['path']);
    $env_id = apachesolr_default_environment();
    $environment = apachesolr_environment_load($env_id);

    $environment['url'] = $url;
    $environment['name'] = $cfg['name'];
    $environment['conf']['apachesolr_direct_commit'] = $cfg['apachesolr_direct_commit'];
    $environment['conf']['apachesolr_read_only'] = $cfg['apachesolr_read_only'];
    $environment['conf']['apachesolr_soft_commit'] = $cfg['apachesolr_soft_commit'];

    apachesolr_environment_save($environment);
    // @todo: See ticket #2527 - cannot make the form save new settings!
    // drupal_form_submit('apachesolr_environment_edit_form', $form_state,
    // $environment);
  }
}

/**
 * Configure the drupal mailsystem module with proper settings.
 */
function osha_configure_mailsystem() {
  drupal_set_message('Configuring Drupal Mailsystem module ...');

  $mail_system = array(
    'default-system' => 'HTMLMailSystem',
    'htmlmail' => 'DefaultMailSystem',
  );

  variable_set('mail_system', $mail_system);
  variable_set('mailsystem_theme', 'default');
}

/**
 * Configure the drupal htmlmail module with proper settings.
 */
function osha_configure_htmlmail() {
  drupal_set_message('Configuring Drupal HTML Mail module ...');

  $site_default_theme = variable_get('theme_default', 'bartik');

  variable_set('htmlmail_theme', $site_default_theme);
  variable_set('htmlmail_postfilter', 'full_html');
}

/**
 * Configure the drupal simplenews module with proper settings.
 */
function osha_configure_simplenews() {
  drupal_set_message('Configuring Drupal Simplenews module ...');

  $site_mail = variable_get('site_mail', 'no-reply@osha.org');
  $site_name = variable_get('site_name', 'OSHA');

  variable_set('simplenews_debug', '1');
  variable_set('simplenews_format', 'html');
  variable_set('simplenews_from_address', $site_mail);
  variable_set('simplenews_from_name', $site_name);
  variable_set('simplenews_priority', '3');
  variable_set('simplenews_receipt', 0);
  variable_set('simplenews_send', '0');
  variable_set('simplenews_source_cache', 'SimplenewsSourceCacheNone');
  variable_set('simplenews_spool_expire', '0');
  variable_set('simplenews_test_address', $site_mail);
  variable_set('simplenews_test_address_override', 1);
  variable_set('simplenews_throttle', '20');
  variable_set('simplenews_use_cron', 1);
}

/**
 * Configure the OSHA newsletter category to format HTML and priority NORMAL.
 */
function osha_configure_newsletter_category() {
  drupal_set_message('Configuring OSHA newsletters format and priority ...');

  db_update('simplenews_category')
  ->fields(array('format' => 'html', 'priority' => 3))
  ->execute();
}

/**
 * Configure IMCE contrib module - Alter User-1 profile and assign User-1 profile to the administrator role.
 */
function osha_configure_imce() {
  drupal_set_message('Configuring Drupal IMCE module ...');
  // /admin/config/media/imce
  if (!module_load_include('inc', 'imce', 'inc/imce.admin')) {
    throw new Exception('Cannot load inc/imce.admin.inc');
  }

  // Alter profile User-1.
  $profiles = variable_get('imce_profiles', array());

  if (isset($profiles[1])) {
    $profiles[1]['directories'][0]['name'] = "sites/default/files";
    variable_set('imce_profiles', $profiles);
  }
  else {
    throw new Exception('Cannot load IMCE profile User-1.');
  }

  $roles = user_roles();

  if (in_array("administrator", $roles)) {
    // Role administrator found - assign User-1 profile to administrator.
    $roles_profiles = variable_get('imce_roles_profiles', array());
    $admin_role = user_role_load_by_name("administrator");

    $roles_profiles[$admin_role->rid]['public_pid'] = 1;
    $roles_profiles[$admin_role->rid]['private_pid'] = 1;
    $roles_profiles[$admin_role->rid]['weight'] = 0;

    variable_set('imce_roles_profiles', $roles_profiles);
  }
  else {
    // Role administrator not found.
    throw new Exception('Cannot assign IMCE profile User-1 to administrator - role administrator not found.');
  }
}

/**
 * Sets default themes for OSHA project.
 */
function osha_configure_default_themes() {
  drupal_set_message('Configuring Drupal default themes ...');

  variable_set('admin_theme', 'osha_admin');
  variable_set('theme_default', 'osha_frontend');
}

/**
 * Config file translator not available during osha_tmgmt installation.
 */
function osha_configure_file_translator() {
  /* @var TMGMTTranslator $file */
  $file = tmgmt_translator_load('file');
  if ($file) {
    $file->settings['export_format'] = 'xml';
    $file->settings['allow_override'] = FALSE;
    $file->save();
  }
}
