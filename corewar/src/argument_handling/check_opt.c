/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** check_opt
*/

#include <stddef.h>
#include <stdbool.h>
#include "corewar.h"
#include "my.h"

static int check_dump_nb(char * const argv[], int *i, corewar_t *corewar,
bool *is_cmd)
{
    int dump_nb = 0;

    if (!argv || !argv[*i] || !argv[*i + 1] || !is_cmd)
        return FAILURE;
    if (argv[*i][0] != '-')
        return SUCCESS;
    if (my_strcmp(argv[*i], "-dump") == 0) {
        if ((dump_nb = my_getnbr(argv[*i + 1])) < 0)
            return FAILURE;
        corewar->dump_cycles = dump_nb;
        i[0]++;
        is_cmd[0] = true;
    }
    return SUCCESS;
}

static int check_warrior(char * const argv[], int *i, corewar_t *corewar,
        bool *is_cmd)
{
    if (!argv || !argv[*i] || !is_cmd)
        return FAILURE;
    if (argv[*i][0] == '-' || my_getnbr(argv[*i]) != 0) {
        *is_cmd = true;
        return SUCCESS;
    }
    if (lexer_vm(argv[*i]) == FAILURE)
        return FAILURE;
    return SUCCESS;
}

int check_opt(char * const argv[], int *i, corewar_t *corewar)
{
    bool is_cmd = false;

    if (argv == NULL || argv[*i] == NULL)
        return FAILURE;
    if (argv[*i][0] != '-' && argv[*i][0] != '.')
        return SUCCESS;
    if (check_dump_nb(argv, i, corewar, &is_cmd) == FAILURE
        && argv[*i][0] == '-')
        return FAILURE;
    if (check_warrior(argv, i, corewar, &is_cmd) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
