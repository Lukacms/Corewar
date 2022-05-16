/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** lexer
*/

#include "redcode.h"
#include "my.h"

static int is_delim(char c)
{
    for (int i = 0; SEPARATOR[i]; i += 1)
        if (c == SEPARATOR[i])
            return 1;
    return 0;
}

static int check_cmd(char *line)
{
    int j = 0;

    for (int i = 0; line[i]; i += 1) {
        for (; !is_delim(line[i]); i++);
        for (j = 0; is_delim(line[i + j]); j++);
        if (j > 1)
            return FAILURE;
    }
    return SUCCESS;
}

int lexer(infos_t *infos)
{
    int index = 0;

    if (!infos)
        return FAILURE;
    if (!(infos->file = load_file_in_array(infos->input_name)))
        return FAILURE;
    if ((index = get_basics(infos, &infos->basics)) < 0)
        return FAILURE;
    for (; infos->file[index]; index += 1) {
        if (!infos->file[index][0])
            continue;
        if (check_cmd(infos->file[index]) != SUCCESS)
            return FAILURE;
    }
    return SUCCESS;
}
