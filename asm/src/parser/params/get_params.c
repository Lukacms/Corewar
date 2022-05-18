/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** get_params
*/

#include <sys/types.h>
#include <stdlib.h>
#include "redcode.h"

int get_params(opnode_t *opnode, op_t op, char **args)
{
    if (!opnode || !args || !(*args))
        return print_error(PARSER_ERR_POINTER, 0, FAILURE);
    for (u_int i = 0; i < op.nbr_args && args[i]; i += 1) {
        if (add_param_node(opnode, op, args[i], i) != SUCCESS)
            return FAILURE;
    }
    opnode->size = op.nbr_args;
    return SUCCESS;
}
