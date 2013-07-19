<?php

/**
 * A handler to provide a count of sites using a given package.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_hosting_package_site_count extends views_handler_field {

  function query() {
    parent::query();
    $this->query->add_field(NULL, '(SELECT count(iid) FROM {hosting_package_instance} pi WHERE pi.package_id = node_hosting_package_instance_nid AND pi.platform = ' . $this->view->args[0] . ' AND pi.status = 1)', 'site_count');
  }

  function render($values) {
    return $values->site_count;
  }

  function click_sort($order) {
    $this->query->add_orderby(NULL, NULL, $order, $this->field);
  }

}
