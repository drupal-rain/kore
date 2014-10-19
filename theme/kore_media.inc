<?php

// Bootstrap Media List
//

/**
 * $vars = array(
 *   'items' => array(),
 *   'settings' => array(
 *     'image' => TRUE,
 *     'image_position' => 'pull-left',
 *     'title' => TRUE,
 *     'title_tag' => 'h3',
 *     'body' => TRUE,
 *   ), // @todo Allow override individual item settings.
 * );
 */
function theme_kore_media($vars) {
  $items = $vars['items'];
  $settings = $vars['settings'];
  $attributes = $vars['attributes'];

  $output = '<ul class="media-list"' . drupal_attributes($attributes) . '>';

  foreach ($items as $item) {
    $variables = array(
      'type' => 'media_test',
      'item' => $item,
      'settings' => $settings,
    );
    $output .= theme('kitem__media_test', $variables);
  }

  $output .= '</ul>';

  return $output;
}
