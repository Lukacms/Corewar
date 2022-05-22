/*
** EPITECH PROJECT, 2022
** Corewar [WSL : Manjaro]
** File description:
** free_corewar
*/

#include <stdlib.h>
#include "corewar.h"

static int free_list(corewar_t *corewar)
{
    warrior_t *tmp = corewar->warrior_list.head;

    for (u_int i = 0; i < corewar->warrior_list.nbr_of_warriors; i += 1) {
        if (!tmp->save || !tmp->reg || !tmp->warrior_code
            || !tmp->filename || !tmp->name)
                return FAILURE;
        free(tmp->save);
        free(tmp->reg);
        free(tmp->filename);
        free(tmp->name);
        tmp = tmp->next;
    }
    return SUCCESS;
}

int free_corewar(corewar_t *corewar)
{
    if (!corewar)
        return FAILURE;
    if (corewar->params)
        free(corewar->params);
    if (corewar->warrior_list.head)
        free_list(corewar);
    if (corewar)
        free(corewar);
    return SUCCESS;
}