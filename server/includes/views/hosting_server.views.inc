<?php
/**
 * @file
 * Hosting server views integration.
 */

/**
 * Implements hook_views_data().
 */
function hosting_server_views_data() {
  $data['hosting_server']['table'] = array(
    'group' => 'Hosting Server',
    'title' => 'Server',
    'join' => array(
      'node' => array(
        'left_field' => 'vid',
        'field' => 'vid',
      ),
    ),
  );

  $data['hosting_server']['services'] = array(
    'title' => t('Services'),
    'help' => t('Available types of services per server.'),
    'field' => array(
      'handler' => 'hosting_server_handler_field_services',
      'field' => 'nid',
/*      'click sortable' => TRUE,*/
    ),
  );

  $data['hosting_server']['human_name'] = array(
    'title' => t('Human-readable name'),
    'help' => t('A human-readable name for the server.'),
    'field' => array(
      'handler' => 'hosting_server_handler_field_human_name',
      'click sortable' => TRUE,
    ),
  );

  $data['hosting_server']['verified'] = array(
    'title' => t('Verified Date'),
    'help' => t('The most recent date that this server was verified.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
  );

  $data['hosting_server']['status'] = array(
    'title' => t('Status'),
    'help' => t('The current state of this server.'),
    'field' => array(
      'handler' => 'hosting_server_handler_field_status',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  $data['hosting_service']['table'] = array(
    'group' => 'Hosting Service',
    'title' => 'Services',
    'join' => array(
      'node' => array(
        'left_field' => 'vid',
        'field' => 'vid',
      ),
    ),
  );

  $data['hosting_service']['service'] = array(
    'title' => t('Service'),
    'help' => t('The type of service.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['hosting_service']['type'] = array(
    'title' => t('Type'),
    'help' => t('The service sub-type.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['hosting_service']['restart_cmd'] = array(
    'title' => t('Restart command'),
    'help' => t('The restart command for the service.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['hosting_service']['port'] = array(
    'title' => t('Port'),
    'help' => t('The port for the service.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
  );

  $data['hosting_service']['available'] = array(
    'title' => t('Available'),
    'help' => t('Whether the service is available.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
  );

  return $data;
}
