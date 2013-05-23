<?php

class views_handler_field_hosting_platform_release extends views_handler_field {
  function render($values) {
    $node = node_load($values->nid);
    return l("{$node->release->title} {$node->release->version}", "node/{$node->release->nid}");
  }
}
