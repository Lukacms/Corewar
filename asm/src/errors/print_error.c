/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** print_error
*/

#include "redcode.h"
#include "my.h"

int print_error(char *str, int i, int status)
{
    if (!str)
        return FAILURE;
    my_printf(str, i);
    return status;
}
