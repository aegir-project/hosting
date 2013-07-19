<?php

/**
 * Sort handler for package site counts.
 */
class views_handler_sort_hosting_package_site_count extends views_handler_sort {

  /**
   * Called to add the sort to a query.
   */
  function query() {
    // Add the field.
    $this->query->add_orderby(NULL, NULL, $this->options['order'], $this->field);
  }

}

