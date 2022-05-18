/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** param_infos
*/

#include <sys/types.h>
#include <stdlib.h>
#include "redcode.h"

static const param_type_t param[] = {
    {.type = T_REG, .handler = &reg_handler},
    {.type = T_DIR, .handler = &dir_handler},
    {.type = T_IND, .handler = &ind_handler},
    {.type = T_IND | T_REG, .handler = &reg_ind_handler},
    {.type = T_REG | T_DIR, .handler = &reg_dir_handler},
    {.type = T_IND | T_DIR, .handler = &ind_dir_handler},
    {.type = T_IND | T_REG | T_DIR, .handler = &reg_dir_ind_handler},
    {0}
};

int param_infos(args_t *node, op_t op, char *arg, u_int index)
{
    int status = 0;

    if (!node || !arg || !op.type[index])
        return print_error(PARSER_ERR_POINTER, 0, FAILURE);
    for (u_int i = 0; param[i].handler; i += 1) {
        if (param[i].type == op.type[index]) {
            status = param[i].handler;
            break;
        }
    }
    if (status != SUCCESS)
        return print_error(PARSER_ERR_ARGTYPE, 0, FAILURE);
    return SUCCESS;
}
