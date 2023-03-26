<?php
/**
 * @file
 * sgpc_updates.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sgpc_updates_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'background_image';
  $context->description = 'Background images';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
        '~report/*' => '~report/*',
        '~reports' => '~reports',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'bg_image' => array(
      'bg_image_node_ref_nid' => '0',
      'bg_image_weight' => '0',
      'bg_image_style' => '',
      'override_css_settings' => 0,
      'css_settings' => array(
        'bg_image_selector' => '#wrap',
        'bg_image_color' => '#FFFFFF',
        'bg_image_x' => 'center',
        'bg_image_y' => 'top',
        'bg_image_attachment' => 'scroll',
        'bg_image_repeat' => 'no-repeat',
        'bg_image_background_size' => '',
        'bg_image_background_size_ie8' => 0,
        'bg_image_media_query' => 'all',
        'bg_image_important' => 1,
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Background images');
  $export['background_image'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'membership_instruction';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user/register' => 'user/register',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-4' => array(
          'module' => 'block',
          'delta' => '4',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['membership_instruction'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'pdf_button';
  $context->description = 'Display PDF links';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'report/*' => 'report/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'print_ui-print-links' => array(
          'module' => 'print_ui',
          'delta' => 'print-links',
          'region' => 'content',
          'weight' => '-8',
        ),
        'printfriendly-printfriendly' => array(
          'module' => 'printfriendly',
          'delta' => 'printfriendly',
          'region' => 'content',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Display PDF links');
  $export['pdf_button'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sidebar_blocks';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~user' => '~user',
        '~user/*' => '~user/*',
        '~email' => '~email',
        '~email/*' => '~email/*',
        '~forum*' => '~forum*',
        '~forums/*' => '~forums/*',
        '~report/*' => '~report/*',
        '~reports' => '~reports',
        '~find-a-supervisor' => '~find-a-supervisor',
        '~cart' => '~cart',
        '~checkout' => '~checkout',
        '~checkout/*' => '~checkout/*',
        '~membership*' => '~membership*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-future_events-block_1' => array(
          'module' => 'views',
          'delta' => 'future_events-block_1',
          'region' => 'sidebar_first',
          'weight' => '-14',
        ),
        'views-news-block_1' => array(
          'module' => 'views',
          'delta' => 'news-block_1',
          'region' => 'sidebar_first',
          'weight' => '-12',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['sidebar_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-user-menu' => array(
          'module' => 'system',
          'delta' => 'user-menu',
          'region' => 'user_menu',
          'weight' => '-10',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'user_menu',
          'weight' => '-9',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
        'block-2' => array(
          'module' => 'block',
          'delta' => '2',
          'region' => 'footer_second',
          'weight' => '-10',
        ),
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'footer_third',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['site'] = $context;

  return $export;
}
