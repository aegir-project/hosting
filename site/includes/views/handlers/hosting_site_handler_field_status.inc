<?php

/**
 * A handler for the Site status field.
 *
 * @ingroup views_field_handlers
 */
class hosting_site_handler_field_status extends hosting_field_handler_status {
  function render($values) {
    $value = $values->{$this->field_alias};
    $output = _hosting_site_status($value);

    switch ($this->options['status_mode']) {
      case 'image':
        return "<span class='hosting-status hosting-status-icon'></span>";

      case 'text_image':
        return "<span class='hosting-status'>{$output}</span>";

      case 'class':
        return _hosting_site_list_class($value, $values->{$this->aliases['verified']});
    }
    return $output;
  }
}
