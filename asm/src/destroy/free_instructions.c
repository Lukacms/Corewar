/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** free_instructions
*/

#include <stdlib.h>
#include "redcode.h"

static void free_opnode(opnode_t *op)
{
    args_t *anchor = op->head;
    args_t *tmp = op->head;

    if (op->fun_name)
        free(op->fun_name);
    for (unsigned int i = 0; i < op->size; i++) {
        anchor = anchor->next;
        if (tmp->arg)
            free(tmp->arg);
        free(tmp);
        tmp = anchor;
    }
    free(op);
}

void free_instructions(infos_t *infos)
{
    opnode_t *anchor = NULL;
    opnode_t *tmp = NULL;

    if (!infos || !(anchor = infos->head))
        return;
    for (unsigned int i = 0; i < infos->size; i += 1) {
        tmp = anchor;
        anchor = anchor->next;
        free_opnode(tmp);
    }
}
