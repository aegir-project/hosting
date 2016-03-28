<?php
/**
 * @file
 * Site backup functions.
 */

/**
 * Confirmation form for site backups.
 *
 * @see hosting_task_confirm_form().
 */
function hosting_task_backup_form($node) {
  $form['description'] = array(
    '#title' => t('Description'),
    '#type' => 'textfield',
    '#required' => FALSE,
    '#weight' => '-1',
    '#description' => "Describe the reasons for creating this backup.",
  );

  return $form;
}

/**
 * Add a site backup record.
 *
 * Builds a list of backups of the site that have been generated.
 */
function hosting_site_add_backup($site, $web_server, $filename, $description = '', $size = '') {
  $id = db_insert('hosting_site_backups')
  ->fields(array(
    'site' => $site,
    'web_server' => $web_server,
    'filename' => $filename,
    'description' => $description,
    'size' => $size,
    'timestamp' => REQUEST_TIME,
  ))
  ->execute();
  return $id;
}

/**
 * Delete a site backup record
 */
function hosting_site_delete_backup($bid) {
  db_delete('hosting_site_backups')
    ->condition('bid', $bid)
    ->execute();
}

/**
 * Get a site backup record
 */
function hosting_site_get_backup($bid) {
  return db_query("SELECT bid, site, web_server, filename, description, size, timestamp FROM {hosting_site_backups} WHERE bid = :bid", array(':bid' => $bid))->fetchAssoc();
}

/**
 * Return an array with site backup IDs as keys, and file paths as values.
 */
function hosting_site_get_backups($nid) {
  return db_query("SELECT bid, filename FROM {hosting_site_backups} WHERE site = :nid", array(':nid' => $nid))->fetchAllKeyed();
}


/**
 * Retrieve a list of backup generated for a site.
 *
 * @param site
 *   The node if of the site backups are being retrieved for
 * @return
 *   An associative array of backups existing for the site, indexed by bid and sorted reverse chronologically.
 */
function hosting_site_backup_list($site) {
  $result = db_query("SELECT bid, description, size, timestamp FROM {hosting_site_backups} WHERE site = :site ORDER BY timestamp DESC", array(':site' => $site));
  $backups = array();
  foreach ($result as $object) {
    #needs to be cleaned up. but i am NOT generating a theme func for this right now.
    $backups[$object->bid] = '<strong>' . format_date($object->timestamp) . '</strong> - ' . format_size($object->size) . ' - ' . filter_xss($object->description);
  }
  return $backups;
}

/**
 * Implements hosting_task_TASK_TYPE_form_validate().
 */
function hosting_task_backup_delete_form_validate($form, &$form_state) {
  if (isset($form['parameters']['no_backups'])) {
    form_set_error('no_backups', t('There are no valid backups available.'));
  }
  // Filter out unchecked backups.
  if (isset($form_state['values']['parameters'])) {
    $form_state['values']['parameters'] = array_filter($form_state['values']['parameters']);
    if (!count($form_state['values']['parameters'])) {
      form_set_error('no_backups', t('No backups were selected for deletion.'));
    }
  }
}

/**
 * Implements hosting_task_TASK_TYPE_form().
 */
function hosting_task_backup_delete_form($node) {
  $list = hosting_site_backup_list($node->nid);
  if (sizeof($list)) {
    foreach ($list as $bid => $info) {
      $backup = hosting_site_get_backup($bid);
      $form[$bid] = array(
        '#type' => 'checkbox',
        '#title' => $info,
        '#return_value' => $backup['filename'],
      );
    }
  }
  else {
    $form['no_backups'] = array(
      '#type' => 'item',
      '#title' => t('Backups'),
      '#markup' => t('There are no valid backups available.')
    );
  }
  return $form;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function hosting_site_form_hosting_task_confirm_form_alter(&$form, &$form_state) {
  $node = $form_state['build_info']['args'][0];
  if($node->type == 'site' && $form['task']['#value'] == 'delete') {
    $backups = hosting_site_get_backups($node->nid);
    if (!empty($backups) && variable_get('hosting_delete_backups', 'never') == 'prompt') {
      $form['delete_backups'] = array(
        '#type' => 'checkbox',
        '#title' => t('Delete site backups'),
        '#description' => t('WARNING: Checking this box will delete all backups for the site.'),
      );
      // Push the submit handler to the beginning, so that backups are deleted
      // prior to the site itself. This results in keeping the pre-delete
      // backup.
    }
    elseif (variable_get('hosting_delete_backups', 'never') == 'always') {
      $form['delete_backups'] = array(
        '#markup' => 'Note that all backups for this site will be deleted, except for the final pre-delete backup.',
      );
    }
    array_unshift($form['#submit'], 'hosting_site_delete_site_task_submit');
  }
}

/**
 * Submit handler for site delete form for deleting backups.
 */
function hosting_site_delete_site_task_submit($form, $form_state){
  $delete = isset($form_state['values']['delete_backups']) ? $form_state['values']['delete_backups'] : FALSE ;
  if ($delete || variable_get('hosting_delete_backups', 'never') == 'always') {
    $nid = $form_state['values']['nid'];
    $backups = hosting_site_get_backups($nid);
    hosting_add_task($nid, 'backup-delete', $backups);
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function hosting_site_form_hosting_settings_alter(&$form, &$form_state) {
  $form['hosting_delete_backups'] = array(
    '#title' => t('Automatically delete backups'),
    '#description' => t("When a site is deleted, should the site's backups also be deleted? Note that the final, pre-delete backup will remain."),
    '#type' => 'radios',
    '#options' => array(
      'always' => t('Always'),
      'prompt' => t('Prompt'),
      'never' => t('Never'),
    ),
    '#default_value' => variable_get('hosting_delete_backups', 'never'),
  );
}
