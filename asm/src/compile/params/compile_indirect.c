/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** compile_indirect
*/

#include "redcode.h"
#include "my.h"

int compile_indirect(args_t *param, FILE *fd)
{
    int ind = 0b11;

    if (!param || !fd)
        return FAILURE;
    if (param->is_lab)
        return SUCCESS;
    ind |= my_getnbr(param->arg);
    fwrite(&ind, IND_SIZE, ONEARG, fd);
    return SUCCESS;
}
