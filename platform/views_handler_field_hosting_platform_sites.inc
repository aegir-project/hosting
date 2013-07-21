<?php

class views_handler_field_hosting_platform_sites extends views_handler_field {
  function render($values) {
    $value = $values->{$this->field_alias};
    return hosting_site_count($value, array(HOSTING_SITE_ENABLED, HOSTING_SITE_DISABLED, HOSTING_SITE_QUEUED));;
  }
}
