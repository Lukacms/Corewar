/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** dup_array
*/

#include <stdlib.h>
#include "my.h"

char **dup_array(char **origin)
{
    char **dest = NULL;
    int i = 0;

    if (!origin)
        return NULL;
    for (; origin[i]; i++);
    dest = malloc(sizeof(char *) * (i + 1));
    if (!dest)
        return NULL;
    for (int y = 0; y < i; y++) {
        dest[i] = my_strdup(origin[i]);
        if (!dest[i])
            return NULL;
    }
    dest[i] = NULL;
    return dest;
}
