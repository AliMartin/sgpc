<?php
/**
 * @file
 * sgpc_updates.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function sgpc_updates_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: committee.
  $roles['committee'] = array(
    'name' => 'committee',
    'weight' => 4,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 3,
  );

  // Exported role: member.
  $roles['member'] = array(
    'name' => 'member',
    'weight' => 5,
  );

  return $roles;
}
