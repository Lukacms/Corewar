/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** check_if_index
*/

#include <sys/types.h>
#include "redcode.h"

static int is_param_an_index(args_t *param, int onset, infos_t *infos)
{
    int label_pos = 0;

    if (!param->is_lab)
        return SUCCESS;
    label_pos = get_index_from_label(param->arg, infos);
    param->offset = label_pos - onset;
    if (param->type == T_DIR)
        param->offset = my_getnbr(param->arg);
    return SUCCESS;
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
        for (u_int j = 0; j < node->size; j++) {
            status |= is_param_an_index(param, onset, infos);
            param = param->next;
        }
        onset += count_node_size(node);
        node = node->next;
    }
    return SUCCESS;
}
