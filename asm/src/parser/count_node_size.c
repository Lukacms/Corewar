/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** count_node_size
*/

#include <stdlib.h>
#include <stdbool.h>
#include "redcode.h"

static int param_type(args_t *param)
{
    if (param->is_lab || param->type == T_IND)
        return IND_SIZE;
    if (param->type == T_DIR)
        return DIR_SIZE;
    if (param->type == T_REG)
        return REG_TRUE_SIZE;
    return 0;
}

int count_node_size(opnode_t *opnode)
{
    int size = 0;
    args_t *param = NULL;

    if (!opnode || !(param = opnode->head))
        return size;
    if (opnode->type != NOTHING)
        size += 1;
    if (opnode->params_type)
        size += 1;
    for (unsigned int i = 0; i < opnode->size; i += 1) {
        size += param_type(param);
        param = param->next;
    }
    return size;
}
