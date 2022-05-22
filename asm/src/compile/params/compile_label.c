/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** compile_label
*/

#include "redcode.h"
#include "my.h"

int compile_label(args_t *param, FILE *fd)
{
    int offset = 0x0;

    if (!param || !fd)
        return FAILURE;
    offset |= param->offset;
    print_reversed_bytes(offset, fd, 8);
    return SUCCESS;
}
