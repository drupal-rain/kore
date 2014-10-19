<?php

/**
 * Implements hook_preprocess_HOOK().
 */
function kore_preprocess_kitem(&$vars) {
  $id = $vars['type'];
  if ($id == 'default') {
    return;
  }

  $callback = kitem_plugin_get_function($id, 'preprocess');
  if ($callback) {
    $callback($vars);
  }

  kitem_plugin_attach($id);
}

/**
 * Implements hook_process_HOOK().
 */
function kore_process_kitem(&$vars) {
  if ($vars['type'] == 'default') {
    return;
  }
  $callback = kitem_plugin_get_function($vars['type'], 'process');
  if ($callback) {
    $callback($vars);
  }
}

// =============================================================================
// Plugin

/**
 * Wrapper for ctools_get_plugins() to get kpane plugins.
 */
function kitem_plugin_get_plugins($id = NULL) {
  ctools_include('plugins');
  $plugins = ctools_get_plugins('kore', 'kitem', $id);

  return $plugins;
}

/**
 * Get optional callback function of plugin.
 */
function kitem_plugin_get_function($id, $callback) {
  ctools_include('plugins');
  $function = ctools_plugin_load_function('kore', 'kitem', $id, $callback);
  // Allow to use default name of callback: MODULE_kitem_PLUGIN_CALLBACK().
  if (!$function) {
    $plugin = ctools_get_plugins('kore', 'kitem', $id);
    $function_tmp = $plugin['module'] . '_kitem_' . $id . '_' . str_replace(' ', '_', $callback);
    if (function_exists($function_tmp)) {
      $function = $function_tmp;
    }
  }

  return $function;
}

/**
 * Attach css, js, etc.
 */
// @todo Finish the design and work.
function kitem_plugin_attach($id) {
  $plugin = kitem_plugin_get_plugins($id);
  // @todo Support other input format?
  if (isset($plugin['css'])) {
    drupal_add_css($plugin['path'] . '/' . $plugin['css']);
  }
  if (isset($plugin['js'])) {
    drupal_add_js($plugin['path'] . '/' . $plugin['js']);
  }
}
