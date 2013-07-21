<?php

/**
 * Filter by task type
 */
class hosting_task_handler_filter_hosting_task_status extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Task Status');

      $options = array();

      $error_codes = _hosting_task_error_codes();

      foreach ($error_codes as $code => $message) {
        $options[$code] = $message;
      }

      $this->value_options = $options;
    }
  }
}

