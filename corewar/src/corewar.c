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

    corewar->params = malloc(sizeof(parameters_t));
    if (!corewar || arg_handling(argc, argv, corewar) != SUCCESS
        || !corewar->params)
        return FAILURE;
    generate_warriors(corewar, argc, argv);
    return SUCCESS;
}
