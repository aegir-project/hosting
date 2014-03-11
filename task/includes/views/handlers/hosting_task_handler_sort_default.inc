<?php

/**
 * Handle the default hosting task sort order.
 */
class hosting_task_handler_sort_default extends views_handler_sort {
  function query() {
    $this->query->add_orderby(NULL, "FIELD(task_status, 0, -1, '>0')", 'ASC', '_' . $this->field);
    $this->query->add_orderby(NULL, 'executed', 'DESC', '_' . $this->field);
    $this->query->add_orderby(NULL, 'node.created', 'DESC', '_' . $this->field);
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['order']['#access'] = FALSE;
  }
}
