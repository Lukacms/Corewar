/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** dir_handler
*/

#include "redcode.h"
#include "my.h"

int dir_handler(char *param, args_t *node)
{
    if (!param || !node)
        return print_error(PARSER_ERR_POINTER, 0, FAILURE);
    node->type = T_DIR;
    return SUCCESS;
}
