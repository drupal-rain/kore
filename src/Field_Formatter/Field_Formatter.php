<?php

/**
 * @file
 */


namespace Drupal\kore\Field_Formatter;

// hook_field_formatter_*().
interface Field_Formatter {

  public static function info();

  public static function settings_form($field, $instance, $view_mode, $form, &$form_state);

  public static function settings_summary($field, $instance, $view_mode);

  public static function prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items, $displays);

  public static function view($entity_type, $entity, $field, $instance, $langcode, $items, $display);

}
