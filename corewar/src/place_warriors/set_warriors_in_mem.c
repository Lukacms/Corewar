/*
** EPITECH PROJECT, 2022
** Corewar [WSL: Manjaro]
** File description:
** place_warrior_loop
*/

#include "corewar.h"

int set_warriors_in_mem(corewar_t *corewar, warrior_t *warrior)
{
    int count = (4 + 128 + 2024);
    char character = '0';
    int i = 0;
    int index = 0;

    while (count < warrior->size) {
        character = warrior->warrior_code[i];
        index = (warrior->instruction_address + i) % MEM_SIZE;
        corewar->memory[index] = character;
        i += 1;
        count += 1;
    }
    return SUCCESS;
}

int set_warriors_in_mem_loop(corewar_t *corewar)
{
    warrior_t *tmp = {0};

    if (!corewar || !corewar->warrior_list.head)
        return FAILURE;
    tmp = corewar->warrior_list.head;
    for (u_int i = 0; i < corewar->warrior_list.nbr_of_warriors; i++) {
        set_warriors_in_mem(corewar, tmp);
        tmp = tmp->next;
    }
    int i = 0;
    return SUCCESS;
}
