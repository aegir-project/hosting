<?php
/**
 * @file
 * Hosting server views integration.
 */

/**
 * Implements hook_views_data().
 */
function hosting_server_views_data() {
  $data['hosting_service']['table'] = array(
    'group' => 'Hosting Server',
    'title' => 'Server',
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
