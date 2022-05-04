/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** display_help
*/

#include <stdlib.h>
#include "redcode.h"
#include "my.h"

int display_help(int status, char *filepath)
{
    char **file = NULL;

    if (!filepath || !(file = load_file_in_array(filepath)))
        return status;
    my_show_word_array(file);
    free_array((void **)file);
    return status;
}
