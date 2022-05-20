/*
** EPITECH PROJECT, 2022
** Corewar [WSL: Manjaro]
** File description:
** battlefield
*/

#include <stdbool.h>
#include <unistd.h>
#include "corewar.h"
#include "my.h"

int battlefield(corewar_t *corewar)
{
    while (true) {
        if (launch_which_instruction(corewar) != SUCCESS)
            return FAILURE;
        if (corewar->dump_cycles == corewar->nbr_cycles)
            dump_memory(corewar);
        corewar->nbr_cycles += 1;
    }
    return SUCCESS;
}
