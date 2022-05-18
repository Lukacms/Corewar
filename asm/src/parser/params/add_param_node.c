/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** add_param_node
*/

#include <sys/types.h>
#include <stdlib.h>
#include "redcode.h"

static void init_node(args_t *node)
{
    node->arg = NULL;
    node->type = 0;
    node->prev = node;
    node->next = node;
}

static void put_node_in_list(args_t *node, opnode_t *op)
{
    if (!op->head)
        op->head = node;
    else {
        node->prev = op->head->prev;
        node->next = op->head;
        op->head->prev->next = node;
        op->head->prev = node;
    }
}

int add_param_node(opnode_t *opnode, op_t op, char *arg, u_int i)
{
    args_t *node = NULL;

    if (!opnode || !arg)
        return print_error(PARSER_ERR_POINTER, 0, FAILURE);
    if (!(node = malloc(sizeof(args_t))))
        return print_error(PARSER_ERR_MALLOC, 0, FAILURE);
    init_node(node);
    if (param_infos(node, op, arg, i) != SUCCESS)
        return FAILURE;
    put_node_in_list(node, opnode);
    return SUCCESS;
}
