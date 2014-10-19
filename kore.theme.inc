<?php

/**
 *  Implements hook_theme().
 */
function kore_theme($existing, $type, $theme, $path) {
  $path = drupal_get_path('module', 'kore');

  $kitems = kitem_plugin_get_plugins();
  $kitems_registry = array();
  foreach ($kitems as $id => $plugin) {
    $kitems_registry['kitem__' . $id] = array(
      'base hook' => 'kitem',
      'path' => $plugin['path'],
      'template' => $id,
    );
  }

  return $kitems_registry + array(
    'kitem' => array(
      'variables' => array(
        'type' => 'default',
        'item' => array(),
        'settings' => array(),
      ),
      'file' => 'theme/kitem.inc',
      'template' => 'theme/kitem',
    ),
    'kore_image' => array(
      'variables' => array(
        'type' => 'image',
        'fid' => NULL,
        'path' => NULL,
        'width' => NULL,
        'height' => NULL,
        'alt' => NULL,
        'title' => NULL,
        'attributes' => array(),
        'style_name' => NULL,
        'link' => NULL,
        'picture' => NULL,
      ),
      'file' => 'theme/kore_image.inc',
    ),
    'kore_list_group' => array(
      'variables' => array(
        'label' => NULL,
        'items' => NULL,
        'items_active' => NULL,
        'items_disabled' => NULL,
      ),
      'file' => 'theme/kore_list_group.inc',
    ),
    'kore_media' => array(
      'variables' => array(
        'items' => array(),
        'settings' => array(),
        'attributes' => array(),
      ),
      'file' => 'theme/kore_media.inc',
    ),
    'kore_thumbnail' => array(
      'variables' => array(
        'items' => array(),
        'settings' => array(),
      ),
      'file' => 'theme/kore_thumbnail.inc',
      'template' => 'theme/kore_thumbnail', // @todo Transfer to theme function, Again!
    ),
    'kore_carousel' => array(
      'variables' => array(
        'items' => array(),
        'settings' => array(),
        'attributes' => array(),
      ),
      'file' => 'theme/kore_carousel.inc',
    ),
  );
}

// =============================================================================
// Alter

/**
 *  Implements hook_preprocess().
 */
function kore_preprocess_page(&$vars) {
  if (!isset($vars['node'])) {
    $menu_item = menu_get_item();
    // Do favor for page manager pages to add node object.
    if (strpos($menu_item['path'], 'node/%') !== FALSE) {
      $vars['node'] = node_load(arg(1));
    }
  }
  // Add node type specific template.
  if (isset($vars['node'])) {
    $vars['theme_hook_suggestions'][] = 'page__node__' . $vars['node']->type;
  }
}

// =============================================================================
// Utility

/**
 * Process $settings['attributes'] into template attributes arrays.
 */
function kore_attributes_process(&$vars, $attributes) {
  $indexes = array('classes_array', 'attributes_array', 'title_attributes_array', 'content_attributes_array');
  foreach ($indexes as $index) {
    if (isset($attributes[$index])) {
      $vars[$index] = array_merge($vars[$index], $attributes[$index]);
    }
  }
}


