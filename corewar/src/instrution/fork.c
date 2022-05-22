/*
** EPITECH PROJECT, 2022
** Corewar [WSL : Manjaro]
** File description:
** fork
*/

#include "corewar.h"

static int create_doppelganger(warrior_t *warrior, corewar_t *corewar, int ind)
{
    create_warrior(corewar, warrior->filename);
    if (!corewar->warrior_list.head->prev)
        return FAILURE;
    corewar->warrior_list.head->prev->pc = warrior->pc;
    corewar->warrior_list.head->prev->instruction_address = ind;
    set_warriors_in_mem(corewar, corewar->warrior_list.head->prev);
    return SUCCESS;
}

int instruction_fork(warrior_t *warrior, corewar_t *corewar)
{
    int index = 0;
    int old_pc = 0;

    if (!warrior || !corewar)
        return FAILURE;
    old_pc = warrior->pc;
    warrior->pc += 1;
    warrior->cycle_rest = 800;
    index = from_byte_to_nbr(warrior, corewar, IND_SIZE);
    index = (old_pc + index) % IDX_MOD;
    create_doppelganger(warrior, corewar, index);
    return SUCCESS;
}
