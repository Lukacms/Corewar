/*
** EPITECH PROJECT, 2022
** Corewar [WSL: Manjaro]
** File description:
** add
*/

#include "corewar.h"

void add(warrior_t *warrior, int nbr_register,
        int nbr_register_sec, int results)
{
    int reg = warrior->reg[nbr_register];
    int reg_sec = warrior->reg[nbr_register_sec];

    reg = reg + reg_sec;
    if (reg == 0)
        warrior->carry = 1;
    else
        warrior->carry = 0;
    warrior->reg[results] = reg;
    return;
}