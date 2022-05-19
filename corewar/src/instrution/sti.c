/*
** EPITECH PROJECT, 2022
** Corewar [WSL: Manjaro]
** File description:
** sti
*/

#include "corewar.h"
#include "my.h"

int sti(warrior_t *warrior, corewar_t *corewar)
{
    int reg = 0;
    int *pc = &warrior->pc;
    int param_one = 0;
    int param_two = 0;

    if (!warrior || !corewar || !corewar->memory)
        return FAILURE;
    *pc += 2;
    reg = corewar->memory[*pc];
    *pc += 1;
    param_one = from_byte_to_nbr(warrior, corewar, T_DIR);
    param_two = from_byte_to_nbr(warrior, corewar, T_DIR);
    corewar->memory[*pc + (param_one + param_two) % IDX_MOD] = warrior->reg[reg];
    return SUCCESS;
}