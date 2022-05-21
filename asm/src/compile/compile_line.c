/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** compile_line
*/

#include <stdlib.h>
#include <stdio.h>
#include "redcode.h"

static const param_type_handler_s compile_params[] = {
    {.type = T_REG, .bit = 0b01, .handler = &compile_direct},
    {.type = T_DIR, .bit = 0b10, .handler = &compile_indirect},
    {.type = T_IND, .bit = 0b11, .handler = &compile_register},
    {0}
};

static int compile_param(args_t *param, FILE *fd)
{
    for (u_int i = 0; compile_params[i].handler; i += 1)
        if (compile_params[i].type == param->type)
            return compile_params[i].handler(param, fd);
    return FAILURE;
}

int compile_line(opnode_t *line, FILE *fd)
{
    args_t *param = NULL;
    int status = SUCCESS;
    int cmd = 0x0;

    if (!line || !fd || !(param = line->head))
        return FAILURE;
    cmd += line->type;
    fwrite(&cmd, ONEARG, 1, fd);
    for (nb_t i = 0; i < line->size; i += 1) {
        status |= compile_param(param, fd);
        param = param->next;
    }
    return status;
}
