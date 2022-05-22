/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** ind_handler
*/

#include <stdbool.h>
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
        node->is_lab = true;
    node->arg = my_strdup(param + ((node->is_lab) ? 1 : 0));
    return SUCCESS;
}
