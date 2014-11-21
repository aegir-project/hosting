<?php

/**
 * @file
 * The Drush integration for server data example.
 */

/**
 * Implements hook_hosting_server_context_options().
 */
function hosting_server_data_hosting_server_context_options(&$task) {
  if (isset($task->ref->server_data) && !empty($task->ref->server_data)) {
    $task->context_options['server_data'] = $task->ref->server_data;
  }
  else {
    $task->context_options['server_data'] = 'null';
  }
}

/**
 * Implements hook_drush_context_import().
 */
function hosting_server_data_drush_context_import($context, &$node) {
  if ($context->type == 'server') {
    if (isset($context->server_data) && !empty($context->server_data)) {
      $node->server_data = $context->server_data;
    }
  }

}
