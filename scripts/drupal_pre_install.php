<?php
/**
 * Author: Cristian Romanescu <cristi _at_ eaudeweb dot ro>
 * Created: 201407171712
 */

$config_file = sprintf('%s/../conf/config.json', dirname(__FILE__));
if (!is_readable($config_file)) {
  die("Cannot read config file! ($config_file). Please configure your project correctly");
}
$json = json_decode(file_get_contents($config_file), TRUE);

if (!empty($json['variables']) && is_array($json['variables'])) {
  foreach ($json['variables'] as $k => $v) {
    variable_set($k, $v);
  }
}

global $user;
$user->uid = 1;

//osha_configure_solr();


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
