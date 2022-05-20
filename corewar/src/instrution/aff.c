/*
** EPITECH PROJECT, 2022
** Corewar [WSL : Manjaro]
** File description:
** aff
*/

#include "corewar.h"
#include "my.h"

int instruction_aff(warrior_t *warrior, corewar_t *corewar)
{
    int reg = 0;

    if (!warrior || !corewar)
        return FAILURE;
    warrior->cycle_rest = 2;
    warrior->pc += 2;
    reg = corewar->memory[warrior->pc];
    my_printf("%c\n", warrior->reg[reg] % 256);
    warrior->pc += 1;
    return SUCCESS;
}
