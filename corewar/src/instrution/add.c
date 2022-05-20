/*
** EPITECH PROJECT, 2022
** Corewar [WSL: Manjaro]
** File description:
** add
*/

#include <stdlib.h>
#include "corewar.h"

int add(warrior_t *warrior, corewar_t *corewar)
{
    int reg = 0;
    int reg_sec = 0;
    int *registers = malloc(sizeof(int) * 3);

    if (!warrior || !warrior->reg || !registers)
        return FAILURE;
    warrior->cycle_rest = 10;
    fill_registers(corewar, warrior, registers);
    reg = warrior->reg[registers[0]];
    reg_sec = warrior->reg[registers[1]];
    reg = reg + reg_sec;
    if (reg == 0)
        warrior->carry = 1;
    else
        warrior->carry = 0;
    warrior->reg[registers[3]] = reg;
    warrior->pc += 5;
    return SUCCESS;
}
