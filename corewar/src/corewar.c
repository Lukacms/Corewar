/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** corewar
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"

int launch(int argc, char * const argv[])
{
    corewar_t *corewar = create_vm();

    if (!corewar || argc < 2)
        return FAILURE;
    if (argv[1] && my_strcmp(argv[1], "-h") == 0)
        return display_help(SUCCESS, COREWAR_HELP);
    corewar->params = malloc(sizeof(parameters_t));
    if (check_parameters(argc, argv) != SUCCESS || !corewar->params)
        return FAILURE;
    if (generate_warriors(corewar, argc, argv) == FAILURE
        || set_warriors_in_mem_loop(corewar) == FAILURE)
        return FAILURE;
    if (battlefield(corewar) != SUCCESS) {
        free_corewar(corewar);
        return FAILURE;
    }
    free_corewar(corewar);
    return SUCCESS;
}
