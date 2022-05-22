/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** dir_handler
*/

#include <stdbool.h>
#include "redcode.h"
#include "my.h"

int dir_handler(char *param, args_t *node)
{
    int size = 0;

    if (!param || !node)
        return FAILURE;
    if ((size = my_strlen(param)) < 2)
        return FAILURE;
    if (param[0] != DIRECT_CHAR)
        return FAILURE;
    node->type = T_DIR;
    if (param[1] == LABEL_CHAR) {
        node->is_lab = true;
        node->type = T_LAB;
    }
    node->arg = my_strdup(param + ((node->is_lab) ? 2 : 1));
    return SUCCESS;
}
