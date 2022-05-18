/*
** EPITECH PROJECT, 2022
** Corewar [WSL: Manjaro]
** File description:
** place_warrior_loop
*/

#include "corewar.h"

static int set_warriors_in_mem(corewar_t *corewar, warrior_t *warrior)
{
    char character = 0;
    int i = 0;
    int index = 0;

    while (character != '\0') {
        character = warrior->warrior_code[i];
        index = (warrior->instruction_address + i) % MEM_SIZE;
        corewar->memory[index] = character;
        i += 1;
    }
    return SUCCESS;
}

int set_warriors_in_mem_loop(corewar_t *corewar)
{
    warrior_t *tmp = {0};

    if (!corewar || !corewar->warrior_list.head)
        return FAILURE;
    tmp = corewar->warrior_list.head;
    for (int i = 0; i < corewar->warrior_list.nbr_of_warriors; i++) {
        set_warriors_in_mem(corewar, tmp);
        tmp = tmp->next;
    }
    my_printf("MEM = %s\n", corewar->memory);
    return SUCCESS;
}