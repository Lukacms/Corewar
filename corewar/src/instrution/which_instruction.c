/*
** EPITECH PROJECT, 2022
** Corewar [WSL: Manjaro]
** File description:
** which_instruction
*/

#include <stdlib.h>
#include "corewar.h"

static const instructions_t instructions[] = {
    {0x01, &instruction_live},
    {0x02, &instruction_ld},
    {0x04, &instruction_add},
    {0x05, &instruction_sub},
    {0x09, &instruction_zjump},
    {0x0b, &instruction_sti},
    {0x0c, &instruction_fork},
    {0x00, NULL},
};

static void warrior_rest(warrior_t *warrior)
{
    warrior->cycle_rest -= 1;
    return;
}

static int which_instruction(corewar_t *corewar, warrior_t *warrior)
{
    for (int i = 0; instructions[i].ptr != NULL; i += 1) {
        if (warrior->cycle_rest != 0) {
            warrior_rest(warrior);
            return SUCCESS;
        }
        if (instructions[i].instruction ==
            corewar->memory[warrior->pc])
            return instructions[i].ptr(warrior, corewar);
    }
    return SUCCESS;
}

int launch_which_instruction(corewar_t *corewar)
{
    u_int count = 0;
    warrior_t *tmp = {0};

    if (!corewar || !corewar->warrior_list.head)
        return FAILURE;
    tmp = corewar->warrior_list.head;
    while (count < corewar->warrior_list.nbr_of_warriors) {
        which_instruction(corewar, tmp);
        tmp = tmp->next;
        count += 1;
    }
    return SUCCESS;
}
