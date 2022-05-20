/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** live
*/

#include <stddef.h>
#include "corewar.h"
#include "my.h"

int live(warrior_t *warrior, corewar_t *corewar)
{
    int number = 0;

    if (!corewar || !warrior)
        return FAILURE;
    warrior->pc += 1;
    number = from_byte_to_nbr(warrior, corewar, 4);
    my_printf("The player %d(%s)is alive.\n", number, warrior->name);
    return SUCCESS;
}
