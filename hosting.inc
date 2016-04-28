<?php

/**
 * @file
 *
 * General purpose Hosting module functions.
 *
 * These can be used by both the frontend Hosting module and drush commands.
 */

/**
 * Check if a hostname provided is an ip address.
 *
 * @param string $hostname
 *   The hostname to check.
 *
 * @return bool
 *   TRUE is the $hostname is a valid IP address, FALSE otherwise.
 */
function _hosting_valid_ip($hostname) {
  return is_string(inet_pton($hostname));
}

/**
 * Check if the FQDN provided is valid.
 *
 * @param string $fqdn
 *   The Fully Qualified Domain Name (FQDN) to validate.
 *
 * @return int
 *   An integer greater than 0 if the $fqdn is valid, or 0 or FALSE if it not
 *   valid.
 */
function _hosting_valid_fqdn($fqdn) {
  // Regex is an implementation of RFC1035, a little relaxed to allow
  // commonly registered hostnames (e.g. domaines starting with digits).
  return preg_match("/^([a-z0-9]([a-z0-9-]*[a-z0-9])?\.?)+$/i", $fqdn);
}

/**
 * Check if the FQDN provided is valid.
 *
 * This is a different function because wildcards are not part of the
 * RFC and may not be allowed everywhere. For example, the main site
 * title shouldn't have a wildcard entry.
 *
 * @param string $fqdn
 *   The Fully Qualified Domain Name (FQDN) to validate.
 *
 * @return bool
 *   TRUE if the $fqdn is valid, or FALSE if it not valid.
 */
function _hosting_valid_fqdn_wildcard($fqdn) {
  // Regex is an implementation of RFC1035, but allows "star" for wildcards.
  return preg_match("/^(\*\.)?([a-z0-9]([a-z0-9-]*[a-z0-9])?\.?)+$/i", $fqdn) &&
    !preg_match("/^(\*\.)[^.]*$/", $fqdn); // don't allow wildcards on TLDs
}

/**
 * Format a timestamp as a string in a friendly way.
 *
 * @param int $ts
 *   The timestamp to format as a an interval.
 *
 * @return string
 *   Returns a string representing the given timestamp:
 *   - If the timestamp is the current time: 'Now'.
 *   - If the timestamp is 0 or FALSE: 'Never'
 *   - Otherwise formatted as 'X ago' where 'X' is for example 1 year or 1
 *     minute etc.
 *
 * @see format_interval()
 */
function hosting_format_interval($ts) {
  if ($ts == REQUEST_TIME) {
    return t('Now');
  }
  if ($ts <= 1) {
    // Treats the UNIX EPOCH as never.
    return t('Never');
  }

  return t("@interval ago", array("@interval" => format_interval(REQUEST_TIME - $ts, 1)));
}

/**
 * Make a path canonical.
 *
 * This removes duplicate slashes, trailing slashes and /./ occurences. It does
 * not (yet?) resolve .. instances.
 */
function hosting_path_normalize($path) {
  return rtrim(preg_replace('/(\/\/*\.)?\/\/*/', '/', $path), '/');
}

/**
 * Shim to preserve API stability. Deprecated. Use hosting_get_hostmaster_site_nid().
 *
 * @deprecated
 */
function hosting_get_hostmaster_nid() {
  return hosting_get_hostmaster_site_nid();
}

/**
 * Helper function to get the node ID of the Aegir front-end site.
 */
function hosting_get_hostmaster_site_nid() {
  return variable_get('aegir_hostmaster_site_nid', NULL);
}

/**
 * Helper function to get the node ID of the Aegir platform.
 */
function hosting_get_hostmaster_platform_nid() {
  $hostmaster_site = node_load(hosting_get_hostmaster_site_nid());
  return $hostmaster_site->platform;
}
