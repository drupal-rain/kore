<?php

/**
 * Theme function for 'datetime_ago'.
*/
function theme_datetime_ago($vars) {
  libraries_load('moment');
  ctools_add_js('datetime_ago', 'kore');
  $data = 'timestamp:' . $vars['timestamp'] . '; end:' . $vars['end'];
  $vars['attributes']['class'][] = 'datetime-ago';

  $output = '<span' . drupal_attributes($vars['attributes']) . ' data-moment data-options="' . $data . '">';
  $output .= format_date($vars['timestamp'], $vars['type'], $vars['format']);
  $output .= '</span>';

  return $output;
}
