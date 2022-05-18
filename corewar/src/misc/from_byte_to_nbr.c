/*
** EPITECH PROJECT, 2022
** Corewar [WSL: Manjaro]
** File description:
** from_byte_to_nbr
*/

#include "corewar.h"

int from_byte_to_nbr(warrior_t *warrior, corewar_t *corewar)
{
    unsigned char tmp = 0;
    int tmp2 = 0;
    int results = 0;
    int *pc = {0};

    if (!warrior || !corewar || !corewar->memory)
        return -1;
    pc = &warrior->pc;
    for (int offset = 0; offset <= 24; offset += 8, *pc += 1, tmp = 0) {
        tmp = corewar->memory[*pc];
        tmp2 = tmp;
        tmp2 = tmp2 << offset;
        results = results | tmp2;
    }
    return results;
}