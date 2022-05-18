/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** param_infos
*/

#include <sys/types.h>
#include <stdlib.h>
#include "redcode.h"
#include "my.h"

int param_infos(args_t *node, op_t op, char *arg, u_int i)
{
    if (!node || !arg || !op.type[i])
        return print_error(PARSER_ERR_POINTER, 0, FAILURE);
    return SUCCESS;
}
