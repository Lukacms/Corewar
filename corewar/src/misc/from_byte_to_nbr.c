/*
** EPITECH PROJECT, 2022
** Corewar [WSL: Manjaro]
** File description:
** from_byte_to_nbr
*/

#include "corewar.h"

static int read_indirect(warrior_t *warrior, corewar_t *corewar)
{
    unsigned char tmp = 0;
    int tmp2 = 0;
    int results = 0;
    int *pc = {0};

    pc = &warrior->pc;
    for (int offset = 8; offset >= 0; offset -= 8, *pc += 1, tmp = 0) {
        tmp = corewar->memory[*pc];
        tmp2 = tmp;
        tmp2 = tmp2 << offset;
        results = results | tmp2;
    }
    return results;
}

static int read_direct(warrior_t *warrior, corewar_t *corewar)
{
    unsigned char tmp = 0;
    int tmp2 = 0;
    int results = 0;
    int *pc = {0};

    pc = &warrior->pc;
    for (int offset = 24; offset >= 0; offset -= 8, *pc += 1, tmp = 0) {
        tmp = corewar->memory[*pc];
        tmp2 = tmp;
        tmp2 = tmp2 << offset;
        results = results | tmp2;
    }
    return results;
}

int from_byte_to_nbr(warrior_t *warrior, corewar_t *corewar, int opt)
{
    if (!warrior || !corewar || !corewar->memory)
        return -1;
    if (opt == DIR_SIZE)
        return read_direct(warrior, corewar);
    return read_indirect(warrior, corewar);
}