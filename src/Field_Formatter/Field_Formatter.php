<?php

/**
 * @file
 */


namespace Drupal\kore\Field_Formatter;

// hook_field_formatter_*().
interface Field_Formatter {

  /**
   * hook_field_formatter_info().
   */
  public static function info();

  /**
   * hook_field_formatter_settings_form().
   */
  public static function settings_form($field, $instance, $view_mode, $form, &$form_state);

  /**
   * hook_field_formatter_settings_summary().
   */
  public static function settings_summary($field, $instance, $view_mode);

  /**
   * hook_field_formatter_prepare_view().
   */
  public static function prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items, $displays);

  /**
   * hook_field_formatter_view().
   */
  public static function view($entity_type, $entity, $field, $instance, $langcode, $items, $display);

}
