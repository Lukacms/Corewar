/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** live
*/

#include <stddef.h>
#include "corewar.h"

int live(warrior_t *warrior, corewar_t *corewar)
{
    if (!corewar || !warrior)
        return FAILURE;
    my_printf("The player %d(%s)is alive.", warrior->id, warrior->name);
    warrior->pc += 2;
    return SUCCESS;
}
