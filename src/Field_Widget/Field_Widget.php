<?php
/**
 * Created by PhpStorm.
 * User: Kolier
 * Date: 2015-01-04
 * Time: 05:53
 */

namespace Drupal\kore\Field_Widget;


interface Field_Widget {

  public static function info();

  public static function settings_form($field, $instance);

  public static function form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element);

}
