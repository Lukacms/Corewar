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
        return print_error(PARSER_ERR_POINTER, 0, FAILURE);
    node->type = T_IND;
    return SUCCESS;
}
