<?php

/**
 * Implements COMMANDFILE_drush_command().
 */
function osha_workflow_drush_command() {
  $items = array();
  $items['osha-create-users'] = array(
    'description' => 'Generate users for each workflow role',
    'aliases' => array('oshcu'),
    'examples' => array(),
    'arguments' => array(),
    'options' => array(),
    'sections' => array(),
  );
  return $items;
}

/**
 * Implements COMMANDFILE_drush_help().
 */
function osha_workflow_drush_help($section) {
  switch ($section) {
    case 'drush:osha-create-users':
      return 'This command will create a group of test users assigned to the workflow roles';
  }
  return NULL;
}

/**
 * Drush command to create OSHA workflow users.
 *
 * @throws Exception
 */
function drush_osha_workflow_osha_create_users() {
  $users = array(
    'editor' => 'Editor',
    'review_manager' => 'Review Manager',
    'project_manager' => 'Project Manager',
    'approver' => 'Approver',
    'final_approver' => 'Final Approver',
    'content_administrator' => 'Content Administrator',
  );

  foreach ($users as $username => $role_name) {
    if (user_load_by_name($username)) {
      drush_log("$username already exists ...", 'warning');
      continue;
    }
    $role = user_role_load_by_name($role_name);
    $fields = array(
      'name' => $username,
      'pass' => $username,
      'status' => 1,
      'init' => "$username@localhost",
      'roles' => array(
        DRUPAL_AUTHENTICATED_RID => 'authenticated user',
        $role->rid => $role_name,
      ),
    );
    user_save(NULL, $fields);
  }
}
