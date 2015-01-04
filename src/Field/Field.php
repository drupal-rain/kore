<?php

/**
 * @file Interface for Field component.
 */

namespace Drupal\kore\Field;


interface Field {

  /**
   * hook_field_info().
   */
  public static function info();

  /**
   * hook_field_schema().
   */
  public static function schema($field);

  /**
   * hook_field_settings_form().
   */
  public static function settings_form($field, $instance, $has_data);

  /**
   * hook_field_instance_settings_form().
   */
  public static function hook_field_instance_settings_form($field, $instance);

  /**
   * hook_field_is_empty().
   */
  public static function is_empty($item, $field);

}
