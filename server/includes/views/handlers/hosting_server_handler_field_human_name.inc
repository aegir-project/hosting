<?php

/**
 * A handler for the Site status field.
 *
 * @ingroup views_field_handlers
 */
class hosting_server_handler_field_human_name extends views_handler_field {
  /**
   * Constructor; calls to base object constructor.
   */
  function construct() {
    parent::construct();
    $this->additional_fields['title'] = array('table' => 'node', 'field' => 'title');
  }

  function render($values) {
    // Default to the hostname if the human-readable name isn't set.
    $value = $values->{$this->field_alias} ? $values->{$this->field_alias} : $values->{$this->aliases['title']};

    return $value;
  }
}
