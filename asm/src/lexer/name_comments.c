/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** name_comments
*/

#include <stdlib.h>
#include "redcode.h"
#include "my.h"

static int get_name(basics_t *bases, char *name)
{
    char **tmp = NULL;

    if (!name)
        return FAILURE;
    if (!(tmp = str_to_array_choice(name, SEPARATOR)))
        return FAILURE;
    if (array_size(tmp) != 2)
        return FAILURE;
    if (my_strcmp(NAME, tmp[0]))
        return FAILURE;
    if (my_strlen(tmp[1]) >= PROG_NAME_LENGTH)
        return FAILURE;
    if (!(bases->name = my_strdup(tmp[1])))
        return FAILURE;
    free_array((void **)tmp);
    return SUCCESS;
}

static int get_comment(basics_t *bases, char *name)
{
    char **tmp = NULL;

    if (!name)
        return FAILURE;
    if (!(tmp = str_to_array_choice(name, SEPARATOR)))
        return FAILURE;
    if (array_size(tmp) != 2)
        return FAILURE;
    if (my_strcmp(NAME, tmp[0]))
        return FAILURE;
    if (my_strlen(tmp[1]) >= COMMENT_LENGTH)
        return FAILURE;
    if (!(bases->name = my_strdup(tmp[1])))
        return FAILURE;
    free_array((void **)tmp);
    return SUCCESS;
}

int get_basics(infos_t *infos, basics_t *bases)
{
    int size = 0;

    if (!infos || !bases || !infos->file)
        return FAILURE_LEX;
    if ((size = array_size(infos->file)) < 2)
        return print_error(LEXER_FILE_ERR, 0, FAILURE_LEX);
    // if (get_name(bases, infos->file[0]) != SUCCESS)
    //     return print_error(LEXER_ERR_HEADER, 1, FAILURE_LEX);
    // if (get_comment(bases, infos->file[1]) != SUCCESS)
    //     return print_error(LEXER_ERR_HEADER, 2, FAILURE_LEX);
    return SUCCESS_LEX;
}
