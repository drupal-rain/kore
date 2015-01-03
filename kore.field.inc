<?php

// =============================================================================
// Hooks

// -----------------------------------------------------------------------------
// field type

/**
 * Implements hook_field_info().
 */
function kore_field_info() {
  return kore_invoke_all('Field', 'info');
}

/**
 * Implements hook_field_settings_form().
 */
function kore_field_settings_form($field, $instance, $has_data) {
  $class = kore_component_get_class('Field', $field['type']);
  return $class::settings_form($field, $instance, $has_data);
}

/**
 * Implements hook_field_is_empty().
 */
function kore_field_is_empty($item, $field) {
  $class = kore_component_get_class('Field', $field['type']);
  return $class::settings_form($item, $field);
}

// -----------------------------------------------------------------------------
// field widget

/**
 * Implements hook_field_widget_info().
 */
function kore_field_widget_info() {
  return kore_invoke_all('Field_Widget', 'info');
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
  return kore_invoke_all('Field_Formatter', 'info');
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
