/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** add_cmd_node
*/

#include <stdlib.h>
#include "redcode.h"

static void init_node(opnode_t *node)
{
    node->head = NULL;
    node->fun_name = NULL;
    node->size = 0;
    node->cycle = '\0';
    node->type = NOTHING;
    node->prev = node;
    node->next = node;
}

static void put_node_in_list(opnode_t *node, infos_t *infos)
{
    if (!infos->head)
        infos->head = node;
    else {
        node->prev = infos->head->prev;
        node->next = infos->head;
        infos->head->prev->next = node;
        infos->head->prev = node;
    }
}

int add_opnode(infos_t *infos, char *line, int y)
{
    opnode_t *node = NULL;

    if (!infos || !line || !(node = malloc(sizeof(opnode_t))))
        return FAILURE;
    init_node(node);
    if (infos_in_opnode(line, node, y) != SUCCESS)
        return FAILURE;
    infos->header.prog_size += count_node_size(node);
    infos->size += 1;
    put_node_in_list(node, infos);
    return SUCCESS;
}
