<?php

/**
 * @file
 * Image metatag feeds tamper.
 */

$plugin = array(
  'form'     => 'drupalmel_feeds_tamper_image_metatag_form',
  'callback' => 'drupalmel_feeds_tamper_image_metatag_callback',
  'name'     => 'Image metatag',
  'category' => 'DrupalMel',
);

/**
 * Feeds tamper form callback.
 */
function drupalmel_feeds_tamper_image_metatag_form($importer, $element_key, $settings) {
  $form['info'] = array(
    '#markup' => t('Fetch image URL from metatag.'),
  );

  return $form;
}

/**
 * Feeds tamper callback.
 */
function drupalmel_feeds_tamper_image_metatag_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  $item = $result->items[$item_key];
  $request = drupal_http_request($item['url']);
  if ($request->code == 200) {
    $html = new DOMDocument();
    @$html->loadHTML($request->data);
    foreach ($html->getElementsByTagName('meta') as $meta) {
      if ($meta->getAttribute('property') == 'og:image') {
        $field = $meta->getAttribute('content');

        return;
      }
    }
  }
}
