/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** dup_array
*/

#include <stdlib.h>
#include "my.h"

static int array_len(char **array)
{
    int i = 0;

    for (; array[i]; i++);
    return i;
}

char **dup_array(char **origin)
{
    char **new_array = NULL;
    int i = 0;
    int len = array_len(origin);

    if (!origin)
        return NULL;
    new_array = malloc(sizeof(char *) * (len + 1));
    if (!new_array)
        return NULL;
    for (; i < len; i++) {
        if (origin[i])
            new_array[i] = origin[i];
        else
            new_array[i] = NULL;
    }
    new_array[i] = NULL;
    return new_array;
}
