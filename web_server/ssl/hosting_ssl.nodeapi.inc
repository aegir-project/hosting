<?php
/**
 * @file
 * NodeAPI functions for the Hosting SSL module.
 */

/**
 * This SSL key is a custom, Aegir generated one.
 */
define('HOSTING_SSL_CUSTOM_KEY', 'null');

/**
 * Form API code to extend the site form with SSL fields.
 */
function hosting_ssl_site_form(&$form, &$form_state, $form_id) {
  $node = $form['#node'];

  $new_site = TRUE;
  $ssl_available = FALSE;
  // Only allow the user to modify these values when the platform is SSL enabled.
  if (isset($node->nid)) {
    $new_site = FALSE;
    $platform = node_load($node->platform);
    $server = node_load($platform->web_server);

    if ($server->services['http']->ssl_enabled) {
      $ssl_available = TRUE;
    }
  }
  
  _hosting_site_field($form, $node, 'hosting_ssl_wrapper', array(
    '#type' => 'fieldset',
    '#title' => t('SSL Settings'),
    '#default_value' => NULL,
  ), 'filter_xss', $ssl_available);

  _hosting_site_field($form['hosting_ssl_wrapper'], $node, 'ssl_enabled', array(
    '#type' => 'radios',
    '#title' => t('Encryption'),
    '#options' => hosting_ssl_status_options(),
    '#description' => t('Enabling encryption will publish your site on both HTTP and HTTPS ports, allowing you to redirect users to the more secure version for certain pages that require the additional security. Requiring encryption will automatically redirect all unencrypted traffic to your HTTPS site.'),
    '#required' => TRUE,
    '#default_value' => (isset($node->ssl_enabled)) ? $node->ssl_enabled : HOSTING_SSL_DISABLED,
    '#access' => user_access('create ssl certificate'),
  ), 'hosting_ssl_status_options', $ssl_available);

  _hosting_site_field($form['hosting_ssl_wrapper'], $node, 'ssl_key', array(
    '#type' => 'radios',
    '#title' => t('Encryption key'),
    '#description' => t("Choose an existing SSL certificate. If you do not wish to use any of your existing certificates, you may choose to generate a new one."),
    '#options' => hosting_ssl_get_keys(NULL, TRUE),
    '#required' => TRUE,
    '#default_value' => (isset($node->ssl_key) && $node->ssl_key > 0) ? $node->ssl_key : HOSTING_SSL_CUSTOM_KEY,
    '#access' => user_access('create ssl certificate'),
    '#states' => array(
      'visible' => array(
        ':input[name="ssl_enabled"]' => array('!value' => 0),
      ),
    ),
  ), 'hosting_ssl_output_key', $ssl_available, !$new_site);

  _hosting_site_field($form['hosting_ssl_wrapper'], $node, 'ssl_key_new', array(
    '#type' => 'textfield',
    '#title' => t('New encryption key'),
    '#description' => t("A name for the certificate, often relating to the domain name. This field should only contain lower case alpha-numeric and '_', '-' or '.' characters. If the SSL certificate is not found in config/ssl.d, Aegir will automatically generate a self-signed certificate for you. You can replace the generated with a properly signed version later. Any required intermediate certificates can be added in a file called config/ssl.d/&lt;name&gt;/openssl_chain.crt"),
    '#default_value' => '',
    '#access' => user_access('create ssl certificate'),
    '#states' => array(
      'visible' => array(
        ':input[name="ssl_enabled"]' => array('!value' => 0),
        ':input[name="ssl_key"]' => array('value' => HOSTING_SSL_CUSTOM_KEY),
      ),
    ),
  ), 'filter_xss', $ssl_available, FALSE);
}

/**
 * Implemensts hook_hosting_site_options_alter
 */
function hosting_ssl_hosting_site_options_alter(&$return, $node) {
  // Disable the ssl key fields by default.
  if (!count(hosting_ssl_get_servers())) {
    $return['ssl_enabled'] = FALSE;
  }

  $return['ssl_key'] = FALSE;
  $return['ssl_key_new'] = FALSE;

  // Test if ssl has been enabled.
  //if (isset($node->ssl_enabled)) {
  if (isset($node->ssl_enabled) && $node->ssl_enabled) {

    $keys = hosting_ssl_get_keys($node->client, TRUE);
    // Return the list of valid keys, including the special 'new key' option.
    $return['ssl_key'] = array_keys($keys);

    // Properly default this value so things dont fall apart later.
    if (count($return['ssl_key']) == 1) {
      $node->ssl_key = HOSTING_SSL_CUSTOM_KEY;
    }

    // the user has chosen to enter a new key
    if ($node->ssl_key == HOSTING_SSL_CUSTOM_KEY) {
      // default the new key to the site's domain name, after filtering.
      $default = hosting_ssl_filter_key($node->title);
      $return['ssl_key_new'] = (!empty($default)) ? $default : TRUE;
    }

    // we need to ensure that the return value is properly indexed, otherwise it
    // gets interpreted as an object by jquery.
    $return['profile'] = array_values(array_intersect($return['profile'], hosting_ssl_get_profiles()));

    $return['platform'] = array_values(array_intersect($return['platform'], hosting_ssl_get_platforms()));
  }
}


/**
 * Implements hook_nodeapi_TYPE_OP().
 */
function hosting_ssl_nodeapi_site_view(&$node, $teaser = FALSE) {
  $node->content['info']['ssl_enabled'] = array(
    '#type' => 'item',
    '#title' => t('Encryption'),
    '#markup' => hosting_ssl_status_options((isset($node->ssl_enabled)) ? $node->ssl_enabled : HOSTING_SSL_DISABLED),
    '#weight' => 6,
  );

  if (isset($node->ssl_enabled) && $node->ssl_enabled == TRUE) {
    $node->content['info']['ssl_key'] = array(
      '#type' => 'item',
      '#title' => t('Encryption key'),
      '#value' => hosting_ssl_output_key($node->ssl_key),
      '#description' => hosting_ssl_get_key($node->ssl_key) ? t("This site is using SSL certificates located at %path.", array('%path' => sprintf("config/ssl.d/%s/", hosting_ssl_output_key($node->ssl_key)))) : t("(key deleted)"),
      '#weight' => 7,
    );
  }
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function hosting_ssl_get_key($cid) {
  static $cache = array();

  if (!isset($cache[$cid])) {
    $cache[$cid] = db_query("SELECT ssl_key FROM {hosting_ssl_cert} WHERE cid = :cid", array(':cid' => $cid))->fetchField();
  }
  return $cache[$cid];
}

/**
 * Get an Array of all IP's associated with an SSL certificate.
 */
function hosting_ssl_get_ip($cid) {
  $result = db_query("SELECT h.name AS server_name, ips.ip_address
                        FROM {hosting_ssl_cert_ips} cert
                  INNER JOIN {hosting_ip_addresses} ips
                          ON cert.ip_address = ips.id
                  INNER JOIN {hosting_context} h
                          ON h.nid = ips.nid
                       WHERE cid = :cid",
                      array(':cid' => $cid));
  $ip_addresses = array();
  foreach ($result as $record) {
    $ip_addresses[$record->server_name] = $record->ip_address;
  }
  return $ip_addresses;
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function hosting_ssl_output_key($cid) {
  return filter_xss(hosting_ssl_get_key($cid));
}

/**
 * Output filter for SSL enabled field.
 */
function hosting_ssl_status_options($status = NULL) {
  $options = array(
    HOSTING_SSL_DISABLED => t('Disabled'),
    HOSTING_SSL_ENABLED => t('Enabled'),
    HOSTING_SSL_REQUIRED => t('Required'),
  );

  if (!is_null($status)) {
    return $options[$status];
  }
  return $options;

}


/**
 * Filter disallowed characters from a ssl certificate key.
 *
 * Only lowercase alphanumeric- and '.', '_' or '-' characters are allowed for ssl keys.
 */
function hosting_ssl_filter_key($key) {
  return strtolower(preg_replace("/[^\w\.\-]/", "", $key));
}

/**
 * Implements hook_nodeapi_TYPE_OP().
 */
function hosting_ssl_nodeapi_site_validate($node, &$form) {
  if ($node->ssl_enabled) {
    // TODO: find a way to avoid calling this function multiple times in hook_validate
    $valid_options = hosting_site_available_options($node);

    if ($node->ssl_key == HOSTING_SSL_CUSTOM_KEY) {
      if (!strlen($node->ssl_key_new)) {
        form_set_error('ssl_key_new', t("The encryption key field is required to enable us to generate a new SSL certificate for your site."));
      }
      else {
        $key = hosting_ssl_filter_key($node->ssl_key_new);

        if (($node->ssl_key_new != $key) || !strlen($key)) {
          form_set_error('ssl_key_new', t("The encryption key field should only contain lower case alpha-numeric and '_', '-' or '.' characters."));
        }

        if (!ctype_alnum($key[0])) {
          form_set_error('ssl_key_new', t("The encryption key field must start with an alpha-numeric character."));
        }

        if ($key == HOSTING_SSL_CUSTOM_KEY) {
          form_set_error('ssl_key_new', t("This encryption key value is reserved for internal use, please choose another"));
        }
      }
    }
    else {
      if (!in_array($node->ssl_key, $valid_options['ssl_key'])) {
        form_set_error('ssl_key', t("You have chosen an invalid SSL key"));
      }
    }
    // TODO, check that the server to host this site has ssl enabled.
    // if (!empty($node->platform)) {
      // $platform = node_load($node->platform);
      // $server = node_load($platform->web_server);
      // $server->services['http']->type == 'apache_ssl' or nginx_ssl???
    // }
  }
}

/**
 * Implements hook_nodeapi_TYPE_OP().
 */
function hosting_ssl_nodeapi_site_presave(&$node) {
  if (!isset($node->ssl_key)) {
    $node->ssl_key = HOSTING_SSL_CUSTOM_KEY;
  }
  if (!isset($node->ssl_enabled)) {
    $node->ssl_enabled = HOSTING_SSL_DISABLED;
  }
  // This creates the SSL key for the site, if required.
  $node->ssl_key = hosting_ssl_save_key($node);
}

/**
 * Implements hook_nodeapi_TYPE_OP().
 */
function hosting_ssl_nodeapi_site_insert($node) {
  $id = db_insert('hosting_ssl_site')
    ->fields(array(
      'vid' => $node->vid,
      'nid' => $node->nid,
      'ssl_enabled' => $node->ssl_enabled,
      'ssl_key' => $node->ssl_key,
    ))
    ->execute();
}

/**
 * Implements hook_nodeapi_TYPE_OP().
 */
function hosting_ssl_nodeapi_site_update($node) {
  // check if an existing record is there
  $result = db_query("SELECT ssl_enabled FROM {hosting_ssl_site} WHERE vid = :vid", array(':vid' => $node->vid));
  if (!($obj = $result->fetch())) {
    hosting_ssl_nodeapi_site_insert($node);
  }
  else {
    if ($node->site_status == HOSTING_SITE_DELETED || (!$node->ssl_enabled && $node->ssl_key != 0))  {
      hosting_ssl_clean_keys($node);
    }

    db_update('hosting_ssl_site')
      ->fields(array(
        'ssl_enabled' => $node->ssl_enabled,
        'ssl_key' => $node->ssl_key,
      ))
      ->condition('vid', $node->vid)
      ->execute();
  }
}

/**
 * Implements hook_node_load().
 */
function hosting_ssl_node_load($nodes, $types) {
  foreach ($nodes as $k => $node) {
    $result = db_query("SELECT ssl_enabled, ssl_key FROM {hosting_ssl_site} WHERE vid = :vid",
      array(':vid' => $node->vid)
      )->fetchObject();
    if ($result) {
      $nodes[$k]->ssl_enabled = $result->ssl_enabled;
      $nodes[$k]->ssl_key = $result->ssl_key;
    }
  }
}

/**
 * Implements hook_nodeapi_TYPE_OP().
 */
function hosting_ssl_nodeapi_site_delete($node) {
  hosting_ssl_clean_keys($node);
  db_delete('hosting_ssl_site')
    ->condition('nid', $node->nid)
    ->execute();
}

/**
 * Implements hook_nodeapi_TYPE_OP().
 */
function hosting_ssl_nodeapi_site_delete_revision($node) {
  db_delete('hosting_ssl_site')
    ->condition('vid', $node->vid)
    ->execute();
}


/**
 * Store the SSL Cert key in the database.
 */
function hosting_ssl_save_key($node) {
  if (empty($node->ssl_enabled)) {
    return 0;
  }

  $client = hosting_get_client($node->client);

  if ($node->ssl_key == HOSTING_SSL_CUSTOM_KEY && !empty($node->ssl_key_new)) {
    $ssl_key = $node->ssl_key_new;
    $result = db_query("SELECT * FROM {hosting_ssl_cert} WHERE ssl_key = :ssl_key", array(':ssl_key' => $ssl_key));
    if ($obj = $result->fetch()) {
      // update
      if ($node->client != NULL) {
        $obj->client = $client->nid;
      }
      drupal_write_record("hosting_ssl_cert", $obj, 'cid');
      $node->ssl_key = $obj->cid;
    }
    else {
      // insert
      $obj = new stdClass();
      $obj->ssl_key = $ssl_key;
      $obj->client = $client->nid;
      $obj->status = 0;
      drupal_write_record("hosting_ssl_cert", $obj);
      if (!hosting_ip_allocate($obj, $node)) {
        form_set_error('ssl_key_new', t("Unable to allocate IP address for certificate, assuming SNI (Server Name Indication) will work (incompatible with Safari and IE on Windows XP, Android 2.2, etc)."));
      }
      $node->ssl_key = $obj->cid;
    }
  }

  return $node->ssl_key;
}

/**
 * Retrieve an associated array of possible keys.
 *
 * @param $client
 *   The client to filter the keys by.
 * @param $ask_custom
 *   Include the special 'generate new key' value used by the site form.
 *
 * @return array
 */
function hosting_ssl_get_keys($client = NULL, $ask_custom = FALSE) {
  $keys = array();

  if ($ask_custom == TRUE) {
    $keys[HOSTING_SSL_CUSTOM_KEY] = t("Generate a new encryption key.");
  }

  $args = array();
  $query = "SELECT cid, ssl_key FROM {hosting_ssl_cert}";

  if (!is_null($client)) {
    $client = hosting_get_client($client);
    if ($client) {
      $query .= " WHERE client = :client";
      $args[':client'] = $client->nid;
    }
  }
  $result = db_query($query, $args);

  while ($obj = $result->fetchObject()) {
    if (count($obj->ssl_key)) {
      $keys[$obj->cid] = $obj->ssl_key;
    }
  }

  return $keys;
}

/**
 * Remove unused SSL keys from the system (but not from the backend).
 *
 * This is designed to be ran on a site's delete task or the site node's deletion.
 */
function hosting_ssl_clean_keys($node) {
  // Check if there are still sites using this site's certificate.
  if (!db_query("SELECT * FROM {hosting_ssl_site} siteA
                   INNER JOIN {hosting_ssl_site} siteB ON siteA.ssl_key = siteB.ssl_key
                   INNER JOIN {hosting_site} s ON s.nid = siteA.nid
                     WHERE siteA.nid <> siteB.nid
                       AND siteA.ssl_enabled = :siteA_ssl_enabled
                       AND siteB.nid = :siteB_nid;",
                 array(
                   ':siteA_ssl_enabled' => 1,
                   ':siteB_nid' => $node->nid,
                 ))->fetchField()) {
    // We need to fetch the ssl_key field from the DB because the object comes
    // from the node edit, so it's gone.
    $ssl_key = db_query('SELECT ssl_key FROM {hosting_ssl_site} WHERE nid = :nid',
      array(
        ':nid' => $node->nid,
      )
    )->fetchField();
    drupal_set_message(t("cleaning up unused certificate %cert associated with site %site", array('%cert' => $ssl_key, '%site' => $node->nid)));
    db_delete('hosting_ssl_cert')
      ->condition('cid', $ssl_key)
      ->execute();
    db_delete('hosting_ssl_cert_ips')
      ->condition('cid', $ssl_key)
      ->execute();
  }
}
