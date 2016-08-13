<?php

/**
 * @file
 * Description metatag feeds tamper.
 */

$plugin = array(
  'form'     => 'drupalmel_feeds_tamper_description_metatag_form',
  'callback' => 'drupalmel_feeds_tamper_description_metatag_callback',
  'name'     => 'Description metatag',
  'category' => 'DrupalMel',
);

/**
 * Feeds tamper form callback.
 */
function drupalmel_feeds_tamper_description_metatag_form($importer, $element_key, $settings) {
  $form['info'] = array(
    '#markup' => t('Fetch description from metatag.'),
  );

  return $form;
}

/**
 * Feeds tamper callback.
 */
function drupalmel_feeds_tamper_description_metatag_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  $item = $result->items[$item_key];
  $metatags = get_meta_tags($item['url']);
  if (isset($metatags['description'])) {
    $field = $metatags['description'];
  }
}
