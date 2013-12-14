<?php

/**
* Implements hook_rules_action_info().
*/
function og_roles_rules_rules_action_info()
{
    $actions = array();
    $actions['og_roles_rules_grant'] = array(
        'label' => t('Grant a user an OG role'),
        'parameter' => array(
            'user' => array(
                'type' => 'user',
                'label' => t('User'),
                'wrapped' => TRUE,
            ),
            'group' => array(
                'type' => array_keys(og_get_all_group_entity()),
                'label' => t('Group'),
                'wrapped' => TRUE,
            ),
            'role' => array(
                'type' => 'integer',
                'label' => t('The role ID.'),
                'default_mode' => 'input',
            ),
        ),
       'group' => t('Organic groups'),
    );

    $actions['og_roles_rules_revoke'] = array(
        'label' => t('Revoke an OG role from a user.'),
        'parameter' => array(
            'user' => array(
                'type' => 'user',
                'label' => t('User'),
                'wrapped' => TRUE,
            ),
            'group' => array(
                'type' => array_keys(og_get_all_group_entity()),
                'label' => t('Group'),
                'wrapped' => TRUE,
            ),
            'role' => array(
                'type' => 'integer',
                'label' => t('The role ID.'),
                'default_mode' => 'input',
            ),
        ),
       'group' => t('Organic groups'),
    );

    return $actions;
}

function og_roles_rules_grant($user, EntityDrupalWrapper $group, $role)
{
    og_role_grant($group->type(), $group->getIdentifier(), $user->getIdentifier(), $role);
}

function og_roles_rules_revoke($user, EntityDrupalWrapper $group, $role)
{
    og_role_revoke($group->type(), $group->getIdentifier(), $user->getIdentifier(), $role);
}
