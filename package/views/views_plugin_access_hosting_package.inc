<?php

/**
 * Access plugin that provides access control for package views.
 */
class views_plugin_access_hosting_package extends views_plugin_access {

  function summary_title() {
    return t('Hosting package');
  }

  function get_access_callback() {
    return array('hosting_package_views_access', array($this->display->display_plugin));
  }

  function access($account) {
    return hosting_package_views_access($this->display->display_plugin, $account);
  }

}
