<?php

// =============================================================================
// Hooks

// -----------------------------------------------------------------------------
// Field Type

/**
 * Implements hook_field_info().
 */
function kore_field_info() {
  return kore_component_invoke_all('Field', 'info');
}

/**
 * Implements hook_field_settings_form().
 */
function kore_field_settings_form($field, $instance, $has_data) {
  $class = kore_component_get_class('Field', $field['type']);
  return $class::settings_form($field, $instance, $has_data);
}

/**
 * Implements hook_field_instance_settings_form().
 */
function kore_field_instance_settings_form($field, $instance) {
  $class = kore_component_get_class('Field', $field['type']);
  return $class::instance_settings_form($field, $instance);
}

/**
 * Implements hook_field_is_empty().
 */
function kore_field_is_empty($item, $field) {
  $class = kore_component_get_class('Field', $field['type']);
  return $class::is_empty($item, $field);
}

/**
 * Implements hook_field_storage_update_field().
 */
function kore_field_storage_update_field($field, $prior_field, $has_data) {
  $class = kore_component_get_class('Field', $field['type']);
  return $class::storage_update_field($field, $prior_field, $has_data);
}

// -----------------------------------------------------------------------------
// field widget

/**
 * Implements hook_field_widget_info().
 */
function kore_field_widget_info() {
  return kore_component_invoke_all('Field_Widget', 'info');
}

/**
 * Implements hook_field_widget_settings_form().
 */
function kore_field_widget_settings_form($field, $instance) {
  $class = kore_component_get_class('Field_Widget', $instance['widget']['type']);
  return $class::settings_form($field, $instance);
}

/**
 * Implements hook_field_widget_form().
 */
function kore_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  $class = kore_component_get_class('Field_Widget', $instance['widget']['type']);
  return $class::form($form, $form_state, $field, $instance, $langcode, $items, $delta, $element);
}

// -----------------------------------------------------------------------------
// field_formatter

/**
 * Implements hook_field_formatter_info().
 */
function kore_field_formatter_info() {
  return kore_component_invoke_all('Field_Formatter', 'info');
}

/**
 * Implements hook_field_formatter_view().
 */
function kore_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $class = kore_component_get_class('Field_Formatter', $display['type']);
  return $class::view($entity_type, $entity, $field, $instance, $langcode, $items, $display);
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function kore_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $class = kore_component_get_class('Field_Formatter', $instance['display'][$view_mode]['type']);
  return $class::settings_form($field, $instance, $view_mode, $form, $form_state);
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function kore_field_formatter_settings_summary($field, $instance, $view_mode) {
  $class = kore_component_get_class('Field_Formatter', $instance['display'][$view_mode]['type']);
  return $class::settings_summary($field, $instance, $view_mode);
}


// -----------------------------------------------------------------------------
// Field Attach API, Optional

/**
 * Implements hook_field_load().
 */
function kore_field_load($entity_type, $entities, $field, $instances, $langcode, &$items, $age) {
  $func = kore_component_func('Field', $field['type'], 'load');
  if ($func) call_user_func_array($func, array($entity_type, $entities, $field, $instances, $langcode, &$items, $age));
}

/**
 * Implements hook_field_validate().
 */
function kore_field_validate($entity_type, $entity, $field, $instance, $langcode, $items, &$errors) {
  $func = kore_component_func('Field', $field['type'], 'validate');
  if ($func) call_user_func_array($func, array($entity_type, $entity, $field, $instance, $langcode, $items, &$errors));
}

/**
 * Implements hook_field_presave().
 */
function kore_field_presave($entity_type, $entity, $field, $instance, $langcode, &$items) {
  $func = kore_component_func('Field', $field['type'], 'presave');
  if ($func) call_user_func_array($func, array($entity_type, $entity, $field, $instance, $langcode, &$items));
}

/**
 * Implements hook_field_insert().
 */
function kore_field_insert($entity_type, $entity, $field, $instance, $langcode, &$items) {
  $func = kore_component_func('Field', $field['type'], 'insert');
  if ($func) call_user_func_array($func, array($entity_type, $entity, $field, $instance, $langcode, &$items));
}

/**
 * Implements hook_field_update().
 */
function kore_field_update($entity_type, $entity, $field, $instance, $langcode, &$items) {
  $func = kore_component_func('Field', $field['type'], 'update');
  if ($func) call_user_func_array($func, array($entity_type, $entity, $field, $instance, $langcode, &$items));
}

/**
 * Implements hook_field_delete().
 */
function kore_field_delete($entity_type, $entity, $field, $instance, $langcode, &$items) {
  $func = kore_component_func('Field', $field['type'], 'delete');
  if ($func) call_user_func_array($func, array($entity_type, $entity, $field, $instance, $langcode, &$items));
}

/**
 * Implements hook_field_delete_revision().
 */
function kore_field_delete_revision($entity_type, $entity, $field, $instance, $langcode, &$items) {
  $func = kore_component_func('Field', $field['type'], 'delete_revision');
  if ($func) call_user_func_array($func, array($entity_type, $entity, $field, $instance, $langcode, &$items));
}

/**
 * Implements hook_field_prepare_view().
 */
function kore_field_prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items) {
  $func = kore_component_func('Field', $field['type'], 'prepare_view');
  if ($func) call_user_func_array($func, array($entity_type, $entities, $field, $instances, $langcode, &$items));
}

/**
 * Implements hook_field_prepare_translation().
 */
function kore_field_prepare_translation($entity_type, $entity, $field, $instance, $langcode, &$items, $source_entity, $source_langcode) {
  $func = kore_component_func('Field', $field['type'], 'prepare_translation');
  if ($func) call_user_func_array($func, array($entity_type, $entity, $field, $instance, $langcode, &$items, $source_entity, $source_langcode));
}
