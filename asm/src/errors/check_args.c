/*
** EPITECH PROJECT, 2022
** check_args
** File description:
** check_args
*/

#include "redcode.h"
#include <stddef.h>

int check_args(char * const argv[])
{
    int extension_index = 0;
    char *file = NULL;

    if (!argv)
        return FAILURE;
    extension_index = my_strlen(argv[1]) - 2;
    if (my_strncmp(&argv[1][extension_index], ".s", 2) != 0)
        return FAILURE;
    file = load_file(argv[1]);
    if (!file)
        return FAILURE;
    free(file);
    return SUCCESS;
}
