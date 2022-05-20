/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** ind_handler
*/

#include "redcode.h"
#include "my.h"

int ind_handler(char *param, args_t *node)
{
    if (!param || !node)
        return FAILURE;
    if (param[0] == DIRECT_CHAR)
        return FAILURE;
    node->type = T_IND;
    if (param[0] == LABEL_CHAR)
        node->type = T_LAB;
    node->arg = my_strdup(param + ((node->type == T_IND) ? 0 : 1));
    return SUCCESS;
}
