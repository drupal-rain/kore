<?php

/**
 * @file
 */


namespace Drupal\kore\Field_Display;

abstract class Field_Display_Abstract implements Field_Display {

  public static function info() {
    return NULL;
    /*
    return array(
      'field' => array(
        'label' => t(''),
        'description' => t(''),
        'weight' => 0,
      ),
    );
    */
  }

  public static function view_alter(&$output, $context) {
  }

}
