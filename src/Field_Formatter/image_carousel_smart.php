<?php

/**
 * @file
 */


namespace Drupal\kore\Field_Formatter;


class image_carousel_smart extends Field_Formatter_Abstract {

  public static function info() {
    return array(
      'image_carousel_smart' => array(
        'label' => t('Smart carousel'),
        'field types' => array('image'),
      ),
    );
  }

  public static function settings_form($field, $instance, $view_mode, $form, &$form_state) {
    $form['img'] = \Drupal\kore\Theme\img::settings_form('img', 'img', array());

    return $form;
  }

  public static function settings_summary($field, $instance, $view_mode) {
    return 'Summary';
  }

  public static function view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
    $element = array();
    foreach ($items as $delta => $item) {
      $element[$delta] = theme('img', array('file' => (object)$item));
    }

    return $element;
  }

}
