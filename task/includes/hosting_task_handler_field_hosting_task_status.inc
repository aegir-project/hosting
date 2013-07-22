<?php
/**
 * @file
 */

/**
 * @ingroup views_field_handlers
 */
class hosting_task_handler_field_hosting_task_status extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();

    $options['alter']['contains']['status_mode'] = array('default' => 'raw');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    if ($this->allow_advanced_render()) {
      $form['alter']['status_mode'] = array(
        '#type' => 'radios',
        '#title' => t('Display mode'),
        '#options' => array(
          'raw' => t('Raw value'),
          'text' => t('Text value'),
          'class' => t('CSS class'),
        ),
        '#default_value' => $this->options['alter']['status_mode'],
        '#description' => t(''),
      );
    }
  }

  function render($values) {
    $value = $values->{$this->field_alias};
    switch ($this->options['alter']['status_mode']) {
      case 'text':
        return _hosting_parse_error_code($value);

      case 'class':
        return hosting_task_status_class($value);
    }
    return $value;
  }
}
