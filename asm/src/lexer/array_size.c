/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** array_size
*/

#include <stdlib.h>

int array_size(char **array)
{
    int i = 0;

    if (!array)
        return -1;
    for (; array[i]; i += 1);
    return i;
}
