<?php

/**
 * Handle the default hosting task sort order.
 */
class hosting_task_handler_sort_hosting_task_default extends views_handler_sort {
  function query() {
    $this->query->add_orderby(NULL, 'FIELD(task_status,"0")', 'DESC', '_' . $this->field);
    $this->query->add_orderby(NULL, 'FIELD(task_status,"-1")', 'DESC', '_' . $this->field);
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['order']['#access'] = FALSE;
  }
}
