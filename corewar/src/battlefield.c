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

    while (true) {
        if (launch_which_instruction(corewar) != SUCCESS)
            return FAILURE;
        cycles += 1;
    }
    return SUCCESS;
}