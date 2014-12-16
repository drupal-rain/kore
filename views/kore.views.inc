<?php

/**
 * Implements hook_views_data_alter().
 */
function kore_views_data_alter(&$data) {
  // Alter the entity generated entries in 'views_entity_node' to map node and kdata.
  // So all the properties and fields will be shown.
  /*
  $data_tmp = &$data['views_entity_node'];
  foreach (node_type_get_names() as $name => $label) {
    if (kore_node_type_kdata_enabled($name)) {
      $kdata_bundles = kore_node_type_kdata_get_bundles($name);
      foreach ($kdata_bundles as $bundle) {
        $data_tmp[$bundle]['relationship']['group'] = t('@node_type kdata', array('@node_type' => $label));
        $data_tmp[$bundle]['relationship']['handler'] = 'views_handler_relationship';
        // @tips If need more complex situation, add 'join handler' to it.
        //   Like when multiple kdata attached to the same node and need to figure out
        //   which one is the right data to display.
        $data_tmp[$bundle]['relationship']['base'] = 'eck_' . $name;
        $data_tmp[$bundle]['relationship']['base field'] = 'nid';
        $data_tmp[$bundle]['relationship']['relationship table'] = 'node';
        $data_tmp[$bundle]['relationship']['relationship field'] = 'nid';
        $data_tmp[$bundle]['relationship']['extra'][] = array(
          'field' => 'type',
          'value' => $bundle,
        );
      }
    }
  }
  */
  // Add 'join' to eck_[Kdata] tables.
  foreach (node_type_get_names() as $name => $label) {
    if (kore_node_type_kdata_enabled($name)) {
      $data['eck_' . $name]['table']['join']['node'] = array(
        'left_field' => 'nid',
        'field'      => 'nid',
      );
    }
  }
}
