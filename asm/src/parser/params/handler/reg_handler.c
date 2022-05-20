/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** reg_handler
*/

#include "redcode.h"
#include "my.h"

int reg_handler(char *param, args_t *node)
{
    int register_nb = 0;

    if (!param || !node)
        return FAILURE;
    if (param[0] != REG_CHAR)
        return FAILURE;
    if ((register_nb = my_getnbr(param + 1)) <= 0 || register_nb > 16)
        return FAILURE;
    node->arg = my_strdup(param);
    node->type = T_REG;
    return SUCCESS;
}
