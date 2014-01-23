<?php

/**
 * @file
 * Definition of hosting_server_handler_field_services.
 */

/**
 * Field handler to show services running on servers.
 *
 * @ingroup views_field_handlers
 */
class hosting_server_handler_field_services extends views_handler_field {
  /**
   * Constructor; calls to base object constructor.
   */
  function construct() {
    parent::construct();
    //$this->additional_fields = array('service', 'type', 'available');
  }

  /**
   * Build a table header compiled from available services.
   */
  function label() {
    // Return a simple string for the Views_UI.
    if ($this->view->editing && is_null($this->original_value)) {
      return 'Services';
    }
    $services = hosting_server_services();
    foreach ($services as $name => $service) {
      $services[$name] = $service['title'];
    }
    return implode(',', $services);
  }

  /**
   * Build a list of services.
   */
  function render($values) {
    $all_services = hosting_server_services();
    $types = array();
    foreach ($all_services as $type => $service) {
      $types[$type] = 'no';
    }

    $node = node_load($values->hosting_server_nid);
    foreach ($node->services as $type => $class) {
      $types[$type] = $class->type;
    }
    return implode(',', $types);
  }

}
