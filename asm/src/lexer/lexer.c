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
        for (; line[i] && !is_delim(line[i]); i++);
        for (j = 0; line[i] && is_delim(line[i + j]); j++);
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
        return print_error(LEXER_LOAD_ERR, 0, FAILURE);
    if ((index = get_basics(infos, &infos->basics)) < 0)
        return FAILURE;
    for (index = 2; infos->file[index]; index += 1) {
        if (!infos->file[index][0])
            continue;
        if (check_cmd(infos->file[index]) != SUCCESS)
            return print_error(LEXER_ERR_SPACE, index + 1, FAILURE);
    }
    return SUCCESS;
}
