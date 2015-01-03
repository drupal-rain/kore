<?php

/**
 * @file Interface for Field component.
 */

namespace Drupal\kore\Field;


interface Field {

  public static function info();

  public static function schema($field);

  public static function settings_form($field, $instance, $has_data);

  public static function is_empty($item, $field);

}
