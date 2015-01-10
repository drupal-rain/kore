<?php

/**
 * @file Interface for Field Display Component.
 *
 * It can be used to create extra field, extra fields.
 * It can be used to override current field.
 *
 * Name convention:
 *   - [Entity Type]__[Field]
 *   - [Entity Type]__[Bundle]__[Field]
 *   - @consider [Entity Type]__[Bundle]__[View Mode]__[Field]
 */

namespace Drupal\kore\Field_Display;

interface Field_Display {

  /**
   * @Implements hook_field_extra_fields().
   */
  public static function info();

  /**
   * @Implements hook_field_attach_view_alter().
   *
   * Multiple usage, alter $output or return a newly created element.
   */
  public static function view_alter(&$output, $context);

}
