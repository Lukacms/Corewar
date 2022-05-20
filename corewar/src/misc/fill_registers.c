/*
** EPITECH PROJECT, 2022
** Corewar [WSL: Manjaro]
** File description:
** fill_registers
*/

#include "corewar.h"

int fill_registers(corewar_t *corewar, warrior_t *warrior, int *registers)
{
    if (!corewar || !warrior || !registers)
        return FAILURE;
    registers[0] = corewar->memory[warrior->pc + 1];
    registers[1] = corewar->memory[warrior->pc + 2];
    registers[2] = corewar->memory[warrior->pc + 3];
    return SUCCESS;
}