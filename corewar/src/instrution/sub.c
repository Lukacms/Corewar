/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** sub
*/

#include "corewar.h"

void sub(warrior_t *warrior, int nbr_register,
        int nbr_register_sec, int results)
{
    int reg = 0;
    int reg_sec = 0;

    if (!warrior || !warrior->reg)
        return;
    reg = warrior->reg[nbr_register];
    reg_sec = warrior->reg[nbr_register_sec];
    reg = reg - reg_sec;
    if (reg == 0)
        warrior->carry = 1;
    else
        warrior->carry = 0;
    warrior->reg[results] = reg;
    return;
}

