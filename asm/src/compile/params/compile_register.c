/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** regiter
*/

#include <stdio.h>
#include "redcode.h"
#include "my.h"

int compile_register(args_t *param, FILE *fd)
{
    char reg = 0x0;

    if (!param || !fd)
        return FAILURE;
    reg |= my_getnbr(param->arg);
    fwrite(&reg, REG_TRUE_SIZE, ONEARG, fd);
    return SUCCESS;
}
