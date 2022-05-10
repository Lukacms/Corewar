/*
** EPITECH PROJECT, 2022
** Corewar [WSL: Manjaro]
** File description:
** get_len_of_name
*/

#include "corewar.h"

int get_len_of_name(char *byte_file)
{
    int len = 0;

    for (u_int i = 0; byte_file[i] < '\0'; i += 1) {
        len += 1;
    }
    return len;
}
