/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** arg_handling
*/

#include <stddef.h>
#include <stdbool.h>
#include "corewar.h"
#include "my.h"

int arg_handling(int argc, char * const argv[], corewar_t *corewar)
{
    if (argv == NULL || argc < 2)
        return FAILURE;
    for (int i = 1; i < argc; i++) {
        if (argv[i] == NULL)
            return FAILURE;
        if (check_opt(argv, &i, corewar) != SUCCESS)
            return FAILURE;
    }
    return SUCCESS;
}
