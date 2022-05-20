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
    {.type = T_REG, .param_handler = &reg_handler},
    {.type = T_DIR, .param_handler = &dir_handler},
    {.type = T_IND, .param_handler = &ind_handler},
    {.type = T_IND | T_REG, .param_handler = &reg_ind_handler},
    {.type = T_REG | T_DIR, .param_handler = &reg_dir_handler},
    {.type = T_IND | T_DIR, .param_handler = &ind_dir_handler},
    {.type = T_IND | T_REG | T_DIR, .param_handler = &reg_dir_ind_handler},
    {0}
};

int param_infos(args_t *node, op_t op, char *arg, u_int index)
{
    int status = 0;

    if (!node || !arg || !op.type[index - 1])
        return print_error(PARSER_ERR_POINTER, 0, FAILURE);
    for (u_int i = 0; param[i].param_handler; i += 1) {
        if (param[i].type == op.type[index - 1]) {
            status = param[i].param_handler(arg, node);
            break;
        }
    }
    if (status != SUCCESS || check_param_pos(&node->arg, op, index))
        return print_error(PARSER_ERR_ARGTYPE, 0, FAILURE);
    if (node->type == T_LAB)
        return is_label(node->arg);
    return SUCCESS;
}
