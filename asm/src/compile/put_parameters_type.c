/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** put_parameters_type
*/

#include <stdio.h>
#include <stdbool.h>
#include "redcode.h"

static const param_type_handler_s compile_params[] = {
    {.type = T_REG, .bit = 0b01},
    {.type = T_DIR, .bit = 0b10},
    {.type = T_LAB, .bit = 0b10},
    {.type = T_IND, .bit = 0b11},
    {0}
};

static int get_param_bit(args_t *param)
{
    for (unsigned int i = 0; compile_params[i].bit; i++) {
        if (param->type == compile_params[i].type)
            return compile_params[i].bit;
    }
    return 0b0;
}

int put_parameters_type(opnode_t *line, FILE *fd)
{
    char type = 0b0;
    args_t *param = NULL;

    if (!line || !fd || !(param = line->head))
        return FAILURE;
    if (!line->params_type)
        return SUCCESS;
    for (unsigned int i = 0; i < 4; i += 1) {
        type <<= 2;
        if (i < line->size)
            type |= get_param_bit(param);
        param = param->next;
    }
    fwrite(&type, ONEARG, 1, fd);
    return SUCCESS;
}
