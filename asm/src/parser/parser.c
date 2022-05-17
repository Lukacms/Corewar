/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** parser
*/

#include "redcode.h"

static int is_comment(char c)
{
    if (!c)
        return 1;
    if (c == COMMENT_CHAR)
        return 1;
    return 0;
}

int parser(infos_t *infos)
{
    int size = 0;

    if (!infos || !infos->file)
        return FAILURE;
    if ((size = array_size(infos->file)) <= 2)
        return FAILURE;
    for (unsigned int i = 2; infos->file[i]; i += 1) {
        if (is_comment(infos->file[i][0]))
            continue;
        if (add_opnode(infos, infos->file[i], i + 1) != SUCCESS)
            return FAILURE;
    }
    return SUCCESS;
}
