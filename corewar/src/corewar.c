/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** corewar
*/

#include "corewar.h"

int launch(int argc, char * const argv[])
{
    corewar_t *corewar = create_vm();

    if (!corewar)
        return FAILURE;
    return SUCCESS;
}
