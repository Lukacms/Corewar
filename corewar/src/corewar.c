/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** corewar
*/

#include <stdlib.h>
#include "corewar.h"

int launch(int argc, char * const argv[])
{
    corewar_t *corewar = create_vm();

    if (!corewar)
        return FAILURE;
    corewar->params = malloc(sizeof(parameters_t));
    if (arg_handling(argc, argv, corewar) != SUCCESS || !corewar->params)
        return FAILURE;
    if (generate_warriors(corewar, argc, argv) == FAILURE 
        || set_warriors_in_mem_loop(corewar) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
