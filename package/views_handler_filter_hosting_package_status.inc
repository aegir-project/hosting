<?php
/**
 * @file
 *   Define a views filter for the Package management module.
 */

/**
 * Views filter class to filter by package status.
 */
class views_handler_filter_hosting_package_status extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Package Status');
      $this->value_options = array('1' => 'Enabled', '0' => 'Disabled');
    }
  }
}
