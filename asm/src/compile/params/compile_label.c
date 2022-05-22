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
    if (!param || !fd)
        return FAILURE;
    fwrite(&param->offset, IND_SIZE, ONEARG, fd);
    return SUCCESS;
}
