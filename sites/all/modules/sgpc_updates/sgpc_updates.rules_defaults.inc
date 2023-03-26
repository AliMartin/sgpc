<?php
/**
 * @file
 * sgpc_updates.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function sgpc_updates_default_rules_configuration() {
  $items = array();
  $items['rules_membership_has_expired_send_email'] = entity_import('rules_config', '{ "rules_membership_has_expired_send_email" : {
      "LABEL" : "Membership has expired - send email",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_update" : [] },
      "IF" : [
        { "NOT user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "6" : "6" } } } }
      ],
      "DO" : [
        { "component_rules_sends_email_to_user_membership_expired" : { "user" : [ "account" ] } }
      ]
    }
  }');
  $items['rules_message'] = entity_import('rules_config', '{ "rules_message" : {
      "LABEL" : "message",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_login" : [] },
      "DO" : []
    }
  }');
  $items['rules_prime_first_email_reminder'] = entity_import('rules_config', '{ "rules_prime_first_email_reminder" : {
      "LABEL" : "Prime first email reminder",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_scheduler", "commerce_license" ],
      "ON" : { "commerce_license_insert" : [] },
      "DO" : [
        { "schedule" : {
            "component" : "rules_sends_email_to_user_first_warning",
            "date" : "+5 minutes",
            "identifier" : "Sends email to User - first warning",
            "param_user" : [ "commerce-license:owner" ]
          }
        }
      ]
    }
  }');
  $items['rules_prime_second_email_reminder'] = entity_import('rules_config', '{ "rules_prime_second_email_reminder" : {
      "LABEL" : "Prime second email reminder",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_scheduler", "commerce_license" ],
      "ON" : { "commerce_license_insert" : [] },
      "DO" : [
        { "schedule" : {
            "component" : "rules_sends_email_to_user_second_warning",
            "date" : "+10 minutes",
            "identifier" : "Sends email to User - first warning",
            "param_user" : [ "commerce-license:owner" ]
          }
        }
      ]
    }
  }');
  $items['rules_redirect_on_login'] = entity_import('rules_config', '{ "rules_redirect_on_login" : {
      "LABEL" : "Redirect on login",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_login" : [] },
      "DO" : [ { "redirect" : { "url" : "forum\\/" } } ]
    }
  }');
  $items['rules_send_email_to_committee_when_a_new_member_wants_to_join'] = entity_import('rules_config', '{ "rules_send_email_to_committee_when_a_new_member_wants_to_join" : {
      "LABEL" : "Send email to committee when a new member wants to join",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "3" : "3" } },
            "subject" : "A new member would like to join SGPC",
            "message" : "[account:edit-url]\\r\\n"
          }
        }
      ]
    }
  }');
  $items['rules_sends_email_to_user_first_warning'] = entity_import('rules_config', '{ "rules_sends_email_to_user_first_warning" : {
      "LABEL" : "Sends email to User - first warning",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "user" : { "label" : "User", "type" : "user" } },
      "ACTION SET" : [
        { "mail" : {
            "to" : "[user:mail]",
            "subject" : "Your SGPC membership will expire in 1 month",
            "message" : "Dear SGPC member\\r\\n\\r\\nYour membership to The Solent Group for Psychotherapists and Counsellors will expire in one month\\u0027s time. To renew your membership please login to your account at https:\\/\\/www.sgpc.co.uk\\/user.\\r\\n\\r\\nKind regards,\\r\\n\\r\\nThe Committee\\r\\nThe Solent Group for Psychotherapists and Counsellors",
            "from" : "no-reply@sgpc.co.uk",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_sends_email_to_user_membership_expired'] = entity_import('rules_config', '{ "rules_sends_email_to_user_membership_expired" : {
      "LABEL" : "Sends email to User - membership expired",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "user" : { "label" : "User", "type" : "user" } },
      "ACTION SET" : [
        { "mail" : {
            "to" : "[user:mail]",
            "subject" : "Your SGPC membership will expire in two weeks time",
            "message" : "Dear SGPC member\\r\\n\\r\\nYour membership to The Solent Group for Psychotherapists and Counsellors has expired. To renew your membership please login to your account at https:\\/\\/www.sgpc.co.uk\\/user.\\r\\n\\r\\nKind regards,\\r\\n\\r\\nThe Committee\\r\\nThe Solent Group for Psychotherapists and Counsellors",
            "from" : "no-reply@sgpc.co.uk",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_sends_email_to_user_second_warning'] = entity_import('rules_config', '{ "rules_sends_email_to_user_second_warning" : {
      "LABEL" : "Sends email to User - second warning",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "user" : { "label" : "User", "type" : "user" } },
      "ACTION SET" : [
        { "mail" : {
            "to" : "[user:mail]",
            "subject" : "Your SGPC membership will expire in two weeks time",
            "message" : "Dear SGPC member\\r\\n\\r\\nYour membership to The Solent Group for Psychotherapists and Counsellors will expire in two week\\u0027s time. To renew your membership please login to your account at https:\\/\\/www.sgpc.co.uk\\/user.\\r\\n\\r\\nIf you have already renewed your membership then you can ignore this email.\\r\\n\\r\\nKind regards,\\r\\n\\r\\nThe Committee\\r\\nThe Solent Group for Psychotherapists and Counsellors",
            "from" : "no-reply@sgpc.co.uk",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
