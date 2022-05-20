/*
** EPITECH PROJECT, 2022
** Corewar [WSL : Manjaro]
** File description:
** zjump
*/

#include "corewar.h"

int instruction_zjump(warrior_t *warrior, corewar_t *corewar)
{
    int index = 0;
    int old_pc = 0;

    if (!warrior || !corewar)
        return FAILURE;
    warrior->cycle_rest = 20;
    old_pc = warrior->pc;
    warrior->pc += 1;
    if (warrior->carry == 1)
        return SUCCESS;
    index = from_byte_to_nbr(warrior, corewar, IND_SIZE);
    warrior->pc = warrior->instruction_address + (old_pc + index) % IDX_MOD;
    return SUCCESS;
}
