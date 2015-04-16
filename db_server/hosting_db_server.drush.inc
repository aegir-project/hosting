<?php

/**
 * Implements hook_drush_context_import().
 *
 * Make sure the database name is populated in the frontend when importing a
 * site.
 */
function hosting_db_server_drush_context_import($context, &$node) {
  if ($context->type == 'site') {
    $node->db_name = $context->db_name;
  }
}