<?php

/**
 * A handler for the Package status field.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_hosting_package_status extends views_handler_field_hosting_site_status {

  /**
   * Constructor; calls to base object constructor.
   */
  function construct() {
    views_handler_field::construct();
  }

  function render($values) {
    $value = $values->{$this->field_alias};
    $output = $value ? t('Enabled') : t('Disabled');

    switch ($this->options['status_mode']) {
      case 'image':
        return "<span class='hosting-status hosting-status-icon'></span>";

      case 'text_image':
        return "<span class='hosting-status'>{$output}</span>";

      case 'class':
        return $value ? 'hosting-success' : 'hosting-info';
    }
    return $output;
  }
}
