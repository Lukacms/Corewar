/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** lexer
*/

#include "redcode.h"
#include "my.h"

int lexer(infos_t *infos)
{
    int index = 0;

    if (!infos)
        return FAILURE;
    if (!(infos->file = load_file_in_array(infos->input_name)))
        return FAILURE;
    if ((index = get_basics(infos, &infos->basics)) < 0)
        return FAILURE;
    return SUCCESS;
}
