<?php

/**
 * @file
 */

namespace Drupal\kore\Field_Formatter;


abstract class Field_Formatter_Abstract implements Field_Formatter {

  public static function info() {
    return NULL;
  }

  public static function settings_form($field, $instance, $view_mode, $form, &$form_state) {
    return $form;
  }

  public static function settings_summary($field, $instance, $view_mode) {
    return NULL;
  }

  public static function prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items, $displays) {
  }

  public static function view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
    return array();
  }

}