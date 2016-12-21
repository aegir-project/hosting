<?php
/**
 * @file
 * :Drush hooks for the Hosting server module.
 */

/**
 * Pass options for the server verification to the backend.
 *
 * Here we pass the hostname, IP addresses, and setup the services for
 * this server (?).
 */
function hosting_hosting_server_context_options(&$task) {
  $task->context_options['remote_host'] = $task->ref->title;
  $ip_list = $task->ref->ip_addresses;
  $task->context_options['ip_addresses'] = count($ip_list) ? implode(',', $ip_list) : 'null';

  foreach (hosting_server_services() as $type => $info) {
    if (isset($task->ref->services[$type])) {
      $service = $task->ref->services[$type];
      if ($service->available) {
        $service->context_options($task->task_type, $task->ref->type, $task);
      }
    }
    else {
      // If we're here, there is no enabled service of this type on this server.
      // If such a service had previously been enabled, that fact, along with
      // any subscribed properties would be recorded in the server context.
      // Since we persist values in contexts, we cannot just leave this unset.
      // Similarly, in Provision_Context::__get(), we filter out falsy values,
      // so we cannot set this to NULL. 0 or the like. Therefore, we explicitely
      // set it to value that we check for in
      // Provision_Context_server::spawn_service().
      $task->context_options["{$type}_service_type"] = 'NONE';
    }
  }
}


/**
 * Implements hook_drush_context_import().
 */
function hosting_server_drush_context_import($context, &$node) {
  if ($context->type == 'server') {
    if (!isset($node->title)) {
      $node->title = strtolower($context->remote_host);
    }
    $node->new_ip_addresses = implode("\n", $context->ip_addresses);
    foreach (hosting_server_services() as $type => $info) {
      if (isset($context->{$type . '_service_type'})) {
        $service_type = $context->{$type . '_service_type'};
        if (isset($node->services[$type])) {
          if ($node->services[$type]->type != $service_type) {
            unset($node->services[$type]);
          }
        }
        if (!isset($node->services[$type])) {
          // Only support the base configuration things for now.
          hosting_services_add($node, $type, $service_type, $values);
        }

        $node->services[$type]->context_import($context);
      }
    }
  }
}

/**
 * Resave the target node to trigger reverifications.
 */
function hosting_server_post_hosting_verify_task($task, $data) {
  if ($task->ref->type == 'server') {
    $task->ref->no_verify = TRUE;

    // Set verified flag on server, to let it know it has been checked.
    $task->ref->verified = REQUEST_TIME;

    $task->ref->server_status = HOSTING_SERVER_ENABLED;
    node_save($task->ref);
  }
}

/**
 * Implements hook_hosting_post_DELETE().
 */
function hosting_server_post_hosting_delete_task($task, $data) {
  $task->ref->server_status = HOSTING_SERVER_DELETED;
  $task->ref->no_verify = TRUE;
  $task->ref->services = array();
  node_save($task->ref);
  hosting_context_delete($task->ref->nid);
}
