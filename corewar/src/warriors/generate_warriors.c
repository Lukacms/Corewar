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
        corewar->dump = my_getnbr(tmp[0]);
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
    warrior_t *tmp2 = corewar->warrior_list.head;
    for (int i = 0; i < corewar->warrior_list.nbr_of_warriors; tmp2 = tmp2->next, i += 1) {
        my_printf("ID = %d, Address = %d Name = %s\n", tmp2->id, tmp2->instruction_address, tmp2->name);
    }
    return SUCCESS;
}