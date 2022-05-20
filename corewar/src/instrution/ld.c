/*
** EPITECH PROJECT, 2022
** Corewar [WSL : Manjaro]
** File description:
** ld
*/

#include "corewar.h"

unsigned char DIRECT = 144;
unsigned char INDIRECT = 208;

int ld(warrior_t *warrior, corewar_t *corewar)
{
    int value = 0;
    int reg = 0;

    if (!warrior || !corewar)
        return FAILURE;
    warrior->cycle_rest = 5;
    warrior->pc += 1;
    if ((unsigned char){corewar->memory[warrior->pc]} == DIRECT) {
        warrior->pc += 1;
        value = from_byte_to_nbr(warrior, corewar, DIR_SIZE);
    }
    else if ((unsigned char){corewar->memory[warrior->pc]} == INDIRECT) {
        warrior->pc += 1;
        value = from_byte_to_nbr(warrior, corewar, IND_SIZE);
    }
    reg = corewar->memory[warrior->pc];
    warrior->reg[reg] = value;
    warrior->pc += 1;
    return SUCCESS;
}