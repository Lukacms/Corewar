/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** compile_line
*/

#include <stdio.h>
#include "redcode.h"

static const param_type_handler_s compile_params[] = {
    {.type = T_REG, .handler = &compile_direct},
    {.type = T_DIR, .handler = &compile_indirect},
    {.type = T_IND, .handler = &compile_register},
    {0}
};

int compile_line(opnode_t *line, FILE *fd)
{
    if (!line || !fd)
        return FAILURE;
    return SUCCESS;
}
