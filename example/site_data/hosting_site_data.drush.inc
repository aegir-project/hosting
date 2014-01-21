<?php

/**
 * Implementation of hook_hosting_site_context_options().
 */
function hosting_site_data_hosting_site_context_options(&$task) {
  if (isset($task->ref->site_data) && !empty($task->ref->site_data)) {
    $task->context_options['site_data'] = $task->ref->site_data;
  }
  else {
    $task->context_options['site_data'] = 'null';
  }
}

/**
 * Implementation of hook_drush_context_import().
 */
function hosting_site_data_drush_context_import($context, &$node) {
  if ($context->type == 'site') {
    if (isset($context->site_data) && !empty($context->site_data)) {
      $node->site_data = $context->site_data;
    }
  }

}
