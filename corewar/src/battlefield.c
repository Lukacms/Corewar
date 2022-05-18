/*
** EPITECH PROJECT, 2022
** Corewar [WSL: Manjaro]
** File description:
** battlefield
*/

#include "corewar.h"
#include "my.h"

int battlefield(corewar_t *corewar)
{
    int cycles = 0;

    while (cycles < corewar->dump) {
        if (launch_which_instruction(corewar) != SUCCESS)
            return FAILURE;
        cycles += 1;
    }
    int i = 0;
    my_printf("MEM = %c\n", corewar->memory[0]);
    while (i < MEM_SIZE) {
        my_printf("%c", corewar->memory[i]);
        i += 1;
    }
    return SUCCESS;
}