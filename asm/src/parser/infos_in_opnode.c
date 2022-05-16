/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** infos_in_cmd_node
*/

#include <stdlib.h>
#include "redcode.h"
#include "my.h"

static const op_t op[] = {
    {"live", 1, {T_DIR}, LIVE, 10, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, LD, 5, "load"},
    {"st", 2, {T_REG, T_IND | T_REG}, ST, 5, "store"},
    {"add", 3, {T_REG, T_REG, T_REG}, ADD, 10, "addition"},
    {"sub", 3, {T_REG, T_REG, T_REG}, SUB, 10, "soustraction"},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, AND, 6,
    "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, OR, 6,
    "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, XOR, 6,
    "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {T_DIR}, ZJUMP, 20, "jump if zero"},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, LDI, 25,
    "load index"},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, STI, 25,
    "store index"},
    {"fork", 1, {T_DIR}, FORK, 800, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, LLD, 10, "long load"},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, LLDI, 50,
    "long load index"},
    {"lfork", 1, {T_DIR}, LFORK, 1000, "long fork"},
    {"aff", 1, {T_REG}, AFF, 2, "aff"},
    {0}
};

int infos_in_opnode(infos_t *infos, char *line, opnode_t *node)
{
    if (!infos || !line || !node)
        return FAILURE;
    return SUCCESS;
}
