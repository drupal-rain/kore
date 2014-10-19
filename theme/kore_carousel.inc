<?php

function theme_kore_carousel($vars) {
  $items = $vars['items'];
  $settings = $vars['settings'];
  $attributes = $vars['attributes'];


  $settings_group = array(
    'instance' => 'owlcarousel_settings_kpane-single',
    'attributes' => array(
      'id' => array(
        'default' => drupal_html_id('owlcarousel_posts')
      ),
    ),
  );

  $items_group = array();
  foreach ($items as $item) {
    $variables = array(
      'type' => 'thumbnail',
      'item' => $item,
      'settings' => $settings,
    );

    $items_group[]['row'] = theme('kitem__thumbnail', $variables);
  }

  $element = NULL;
  if ($items_group) {
    $element = array(
      '#theme' => 'owlcarousel',
      '#items' => $items_group,
      '#settings' => $settings_group,
    );
  }

  return $element;
}
