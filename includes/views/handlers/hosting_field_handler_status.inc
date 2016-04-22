<?php

/**
 * A base handler for status fields.
 *
 * @ingroup views_field_handlers
 */
class hosting_field_handler_status extends views_handler_field {
  /**
   * Constructor; calls to base object constructor.
   */
  function construct() {
    parent::construct();
    $this->additional_fields = array('verified');
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['status_mode'] = array('default' => 'text');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form['status_mode'] = array(
      '#type' => 'radios',
      '#title' => t('Display mode'),
      '#options' => array(
        'text' => t('Text'),
        'image' => t('Image'),
        'text_image' => t('Text & Image'),
        'class' => t('CSS class'),
      ),
      '#default_value' => isset($this->options['status_mode']) ? $this->options['status_mode'] : 'text',

      '#description' => t("Display mode of status values.")
    );
    parent::options_form($form, $form_state);
  }

}
