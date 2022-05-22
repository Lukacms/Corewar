/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** check_if_index
*/

#include <sys/types.h>
#include "redcode.h"

static int is_param_an_index(args_t *param, int onset)
{
    int label_pos = 0;
}

int check_if_index(infos_t *infos)
{
    opnode_t *node = NULL;
    args_t *param = NULL;
    int onset = 0;
    int status = 0;

    if (!infos || !(node = infos->head))
        return FAILURE;
    for (u_int i = 0; i < infos->size; i++) {
        param = node->head;
        for (u_int i = 0; i < infos->size; i++) {
            status |= is_param_an_index(param, onset);
            node = node->next;
        }
        onset += count_node_size(node);
        node = node->next;
    }
    return SUCCESS;
}
