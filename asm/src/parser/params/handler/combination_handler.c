/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** combination_handler
*/

#include "redcode.h"
#include "my.h"

int reg_dir_handler(char *param, args_t *node)
{
    if (!param || !node)
        return print_error(PARSER_ERR_POINTER, 0, FAILURE);
    if (reg_handler(param, node) && dir_handler(param, node))
        return FAILURE;
    return SUCCESS;
}

int ind_dir_handler(char *param, args_t *node)
{
    if (!param || !node)
        return print_error(PARSER_ERR_POINTER, 0, FAILURE);
    if (ind_handler(param, node) && dir_handler(param, node))
        return FAILURE;
    return SUCCESS;
}

int reg_ind_handler(char *param, args_t *node)
{
    if (!param || !node)
        return print_error(PARSER_ERR_POINTER, 0, FAILURE);
    if (reg_handler(param, node) && ind_handler(param, node))
        return FAILURE;
    return SUCCESS;
}

int reg_dir_ind_handler(char *param, args_t *node)
{
    if (!param || !node)
        return print_error(PARSER_ERR_POINTER, 0, FAILURE);
    if (reg_handler(param, node) && ind_handler(param, node) &&
        dir_handler(param, node))
        return FAILURE;
    return SUCCESS;
}
