/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** check_param_pos
*/

#include <sys/types.h>
#include "redcode.h"

int check_param_pos(char **param, op_t op, u_int i)
{
    int index = 0;

    if (!param || !(*param))
        return FAILURE;
    index = my_strlen((*param)) - 1;
    if (i < op.nbr_args && (*param)[index] != SEPARATOR_CHAR)
        return FAILURE;
    else if (i < op.nbr_args) {
        (*param)[index] = '\0';
        return SUCCESS;
    }
    if (i == op.nbr_args && (*param)[index] == SEPARATOR_CHAR)
        return FAILURE;
    return SUCCESS;
}
