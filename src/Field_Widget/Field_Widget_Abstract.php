<?php

/**
 * @file
 */


namespace Drupal\kore\Field_Widget;


abstract class Field_Widget_Abstract implements Field_Widget {

  public static function info() {
    return NULL;
    /*
    return array(
      'WIDGET' => array(
        'label' => t('WIDGET name'),
        'field types' => array('FIELD_TYPE_1', 'FIELD_TYPE_2'),
        'settings' => array(
          'var_1' => '',
          'var_2' => '',
        ),
      ),
    );
    */
  }

  public static function settings_form($field, $instance) {
    return array();
  }

  public static function form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
    return array();
  }

}
