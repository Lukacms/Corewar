/*
** EPITECH PROJECT, 2022
** Corewar [WSL: Manjaro]
** File description:
** generate_warriors
*/

#include "corewar.h"
#include "my.h"

static int get_parameters(corewar_t *corewar, char ***tmp, int *counter)
{
    if (my_strcmp((*tmp)[0], "-a") == 0) {
        *tmp += 1;
        corewar->params->a_parameter = my_strdup((*tmp)[0]);
        *tmp += 1;
        *counter += 2;
    }
    if (my_strcmp((*tmp)[0], "-n") == 0) {
        *tmp += 1;
        corewar->params->n_parameter = my_strdup((*tmp)[0]);
        *tmp += 1;
        *counter += 2;
    }
    return SUCCESS;
}

int generate_warriors(corewar_t *corewar, int argc, char * const argv[])
{
    char **tmp = argv;
    int counter = 1;

    tmp += 1;
    if (my_strcmp(tmp[0], "-dump") == 0) {
        tmp += 1;
        corewar->dump_cycles = my_getnbr(tmp[0]);
        tmp += 1;
        counter += 2;
    }
    while (counter < argc) {
        get_parameters(corewar, &tmp, &counter);
        get_parameters(corewar, &tmp, &counter);
        create_warrior(corewar, tmp[0]);
        tmp += 1;
        counter += 1;
    }
    return SUCCESS;
}