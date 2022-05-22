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

static int init_header(infos_t *infos, char **file)
{
    char **name = NULL;
    char **comment = NULL;
    int i = 0;

    if (!file || !(*file) || array_size(file) <= 2)
        return FAILURE;
    for (; file[i] && is_comment(file[i][0]); i++);
    if (!(name = str_to_array_choice(file[i], "\"")) || !(*name) || !name[1])
        return FAILURE;
    comment = str_to_array_choice(file[i + 1], "\"");
    if (!comment || !(*comment) || !comment[1])
        return FAILURE;
    if (my_strlen(name[1]) > 128 || my_strlen(comment[1]) > 2048)
        return FAILURE;
    my_strncpy(infos->header.prog_name, name[1], PROG_NAME_LENGTH + 1);
    my_strncpy(infos->header.comment, comment[1], COMMENT_LENGTH+ 1);
    free_array((void **)comment);
    free_array((void **)name);
    return SUCCESS;
}

int parser(infos_t *infos)
{
    int size = 0;
    unsigned int i = 0;

    if (!infos || !infos->file)
        return FAILURE;
    if (check_name_and_comment(infos->file) == FAILURE)
        return FAILURE;
    if ((size = array_size(infos->file)) <= 2)
        return FAILURE;
    if (init_header(infos, infos->file) == FAILURE)
        return FAILURE;
    for (; infos->file[i] && is_comment(infos->file[i][0]); i++);
    for (i += 2; infos->file[i]; i += 1) {
        if (is_comment(infos->file[i][0]))
            continue;
        if (add_opnode(infos, infos->file[i], i + 1) != SUCCESS)
            return FAILURE;
    }
    return check_if_index(infos);
}
