/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** compile
*/

#include <sys/types.h>
#include "redcode.h"

static int compile_instructions(infos_t *infos)
{
    opnode_t *instruction = infos->head;
    int status = 0;

    if (!instruction)
        return FAILURE;
    for (u_int i = 0; i < infos->size; i += 1) {
        status |= compile_line(instruction, infos->fd);
        instruction = instruction->next;
    }
    return status;
}

int compile(infos_t *infos)
{
    if (!infos)
        return FAILURE;
    if (create_header(infos) != SUCCESS)
        return FAILURE;
    if (compile_instructions(infos) != SUCCESS)
        return FAILURE;
    free_collected_infos(infos);
    return SUCCESS;
}
