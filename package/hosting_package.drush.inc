<?php
/**
 * @file
 * Drush include for the package management module.
 */

function drush_hosting_package_pre_hosting_task() {
  $task = &drush_get_context('HOSTING_TASK');
  if ($task->ref->type == 'site') {
    // populate the profile option, if it hasn't been specified yet.
    if (empty($task->options['profile'])) {

      // If site node "profile_name" property is a string and not empty, lookup
      // the profile package NID and save it to the site node.
      if (empty($task->ref->profile) && !empty($task->ref->profile_name) && is_string($task->ref->profile_name)) {
        $instances = hosting_package_instances_load(array(
          'i.rid' => $task->ref->platform,
          'p.package_type' => 'profile',
          'p.short_name' => $task->ref->profile_name,
        ));

        // If instance is found, save the package ID to hosting_site table.
        $instance = current($instance);
        if (!empty($instance->package_id)) {
          db_update('hosting_site')
            ->fields(array('profile' => $instance->package_id))
            ->condition('nid', $task->ref->nid)
            ->execute();

          drush_log(dt('Updated site node !nid with install profile "!profile" with package ID !package_id.', array(
            '!nid' => $task->ref->nid,
            '!profile' => $task->ref->profile_name,
            '!package_id' => $task->ref->profile,
          )), 'notice');
        }
        else {
          drush_log(dt('Package for install profile "!profile" not found for site !nid.', array(
            '!nid' => $task->ref->nid,
            '!profile' => $task->ref->profile_name,
          )), 'warning');
        }
      }

      $profile = node_load($task->ref->profile);
      if ($task->task_type != 'import' && $task->task_type != 'delete' && $task->task_type != 'verify') {
        $task->options['profile'] = $profile->short_name;
      }
    }
  }
}
