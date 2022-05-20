/*
** EPITECH PROJECT, 2022
** Corewar [WSL: Manjaro]
** File description:
** sti
*/

#include "corewar.h"
#include "my.h"

int instruction_sti(warrior_t *warrior, corewar_t *corewar)
{
    int reg = 0;
    int *pc = &warrior->pc;
    int one = 0;
    int two = 0;

    if (!warrior || !corewar || !corewar->memory)
        return FAILURE;
    warrior->cycle_rest = 25;
    *pc += 2;
    reg = corewar->memory[*pc];
    *pc += 1;
    one = from_byte_to_nbr(warrior, corewar, IND_SIZE);
    two = from_byte_to_nbr(warrior, corewar, IND_SIZE);
    corewar->memory[*pc + (one + two) % IDX_MOD] = warrior->reg[reg];
    return SUCCESS;
}
