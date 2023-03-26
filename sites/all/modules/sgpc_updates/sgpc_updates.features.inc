<?php
/**
 * @file
 * sgpc_updates.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sgpc_updates_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "captcha" && $api == "captcha") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function sgpc_updates_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function sgpc_updates_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'background_image' => array(
      'name' => t('Background image'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'event_calendar' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('A content type to create events for calendar.'),
      'has_title' => '1',
      'title_label' => t('Event Title'),
      'help' => '',
    ),
    'faq' => array(
      'name' => t('FAQ'),
      'base' => 'node_content',
      'description' => t('Add a <em>frequently asked question</em> to the website.'),
      'has_title' => '1',
      'title_label' => t('Question'),
      'help' => '',
    ),
    'news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => t('Add some <em>news</em> to the website.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'product_display' => array(
      'name' => t('Product display'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'testimonial' => array(
      'name' => t('Testimonial'),
      'base' => 'node_content',
      'description' => t('Add a <em>testimonial</em> to the website.'),
      'has_title' => '1',
      'title_label' => t('Author'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_profile2_type().
 */
function sgpc_updates_default_profile2_type() {
  $items = array();
  $items['personal'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "personal",
    "label" : "Personal profile",
    "weight" : "2",
    "data" : { "registration" : 1, "use_page" : 0 },
    "rdf_mapping" : []
  }');
  $items['public'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "public",
    "label" : "Public profile",
    "weight" : "0",
    "data" : { "registration" : 1, "use_page" : 0 },
    "rdf_mapping" : []
  }');
  $items['supervisor'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "supervisor",
    "label" : "Supervisor",
    "weight" : "3",
    "data" : { "registration" : 0, "use_page" : 0 },
    "rdf_mapping" : []
  }');
  return $items;
}
