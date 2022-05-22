/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** get_type_of_arg
*/

#include <stdlib.h>
#include "corewar.h"

static int check_in_for(argument_t *arg, unsigned char byte, int i)
{
    static unsigned char reg_cpy[3] = { 4, 16, 64 };
    static unsigned char dir_cpy[3] = { 8, 32, 128 };
    static unsigned char ind_cpy[3] = { 12, 48, 192 };

    if (!arg)
        return FAILURE;
    if ((arg->ind[i] &= byte) == ind_cpy[i]) {
        arg->t_argrs[i] = T_IND;
        return SUCCESS;
    }
    if ((arg->dir[i] &= byte) == dir_cpy[i]) {
        arg->t_argrs[i] = T_DIR;
        return SUCCESS;
    }
    if ((arg->reg[i] &= byte) == reg_cpy[i]) {
        arg->t_argrs[i] = T_REG;
        return SUCCESS;
    }
    return SUCCESS;
}

static int parse_byte(argument_t *arg, unsigned char byte)
{
    if (!arg)
        return FAILURE;
    for (int i = 0; i < 3; i++)
        if (check_in_for(arg, byte, i) == FAILURE)
            return FAILURE;
    return SUCCESS;
}

argument_t *get_type_of_arg(unsigned char byte)
{
    argument_t *arg = malloc(sizeof(argument_t));

    if (!arg)
        return NULL;
    arg->reg[0] = 4;
    arg->reg[1] = 16;
    arg->reg[2] = 64;
    arg->dir[0] = 8;
    arg->dir[1] = 32;
    arg->dir[2] = 128;
    arg->ind[0] = 12;
    arg->ind[1] = 48;
    arg->ind[2] = 192;
    if (parse_byte(arg, byte) == FAILURE)
        return NULL;
    return arg;
}
