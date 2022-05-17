/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** is_label
*/

#include "redcode.h"

static int correct_lab_char(char c)
{
    for (unsigned int i = 0; LABEL_CHARS[i]; i += 1)
        if (c == LABEL_CHARS[i])
            return SUCCESS;
    return FAILURE;
}

int is_label(char *str)
{
    if (!str)
        return FAILURE;
    for (unsigned int i = 0; str[i]; i += 1) {
        if (correct_lab_char(str[i]) != SUCCESS)
            return FAILURE;
    }
    return SUCCESS;
}
