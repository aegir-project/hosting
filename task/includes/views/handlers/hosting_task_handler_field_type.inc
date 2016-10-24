<?php
/**
 * @file Views handler for the Hosting task module.
 */

/**
 * Filter by task type
 */
class hosting_task_handler_field_type extends views_handler_field {

  function option_definition() {
    $options = parent::option_definition();
    $options['type_format'] = array('default' => 'text');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form['type_format'] = array(
      '#type' => 'radios',
      '#title' => t('Display mode'),
      '#options' => array(
        'raw' => t('Raw value'),
        'text' => t('Text value'),
      ),
      '#default_value' => isset($this->options['type_format'])? $this->options['type_format']: 'title',
      '#description' => t('Output the machine-name or human name of the task type.'),
    );
    parent::options_form($form, $form_state);
  }

  function render($values) {
    $value = $this->get_value($values);
    switch ($this->options['type_format']) {
      case 'text':
        return hosting_task_type_name($value);
      default:
        return $value;
    }
  }
}

