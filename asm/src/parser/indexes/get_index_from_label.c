/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** check_if_index
*/

#include <sys/types.h>
#include "redcode.h"
#include "my.h"

int get_index_from_label(char *label, infos_t *infos)
{
    int size = 0;
    opnode_t *node = NULL;

    if (!infos || !label || !(node = infos->head))
        return 0;
    for (u_int i = 0; i < infos->size; i++) {
        if (node->fun_name && my_strcmp(label, node->fun_name) == SUCCESS)
            return size;
        size += count_node_size(node);
        node = node->next;
    }
    return 0;
}
