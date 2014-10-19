<?php

$plugin = array(
  'css' => 'media.css',
);

function kore_kitem_media_preprocess(&$vars) {
  $item = &$vars['item'];
  $settings = &$vars['settings'];

  // @todo A helper for this.
  if (!isset($settings['image_position'])) {
    $settings['image_position'] = 'pull-left';
  }

  $vars['image_position'] = $settings['image_position'];

}
