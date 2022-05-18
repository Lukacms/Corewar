/*
** EPITECH PROJECT, 2022
** Corewar [WSL: Manjaro]
** File description:
** check_parameters
*/

#include <unistd.h>
#include "corewar.h"
#include "my.h"

static int check_options(int *count, char * const argv[])
{
    *count += 1;
    if (my_str_isnum(argv[*count]) == 0) {
        write(STDERR_FILENO, "Corewar: Option is not a number.\n", 34);
        return FAILURE;
    }
    return SUCCESS;
}

static int check_file(int *count, char * const argv[])
{
    int len = 0;
    char *tmp = NULL;
    int i = 0;

    if (!count || !argv[*count])
        return FAILURE;
    if (argv[*count][0] < '9' && argv[*count][0] > '0')
        return SUCCESS;
    len = my_strlen(argv[*count]);
    for (i = len - 1; argv[*count][i] != '.' && argv[*count][i] != '/'; i -= 1);
    tmp = argv[*count] + i;
    if (tmp[0] == '/' || my_strncmp(tmp, ".cor", 4) != 0) {
        write(STDERR_FILENO, "Corewar: This is not a .cor file.\n", 35);
        return FAILURE;
    }
    if (lexer_warrior(argv[*count]) == FAILURE)
        return FAILURE;
    return SUCCESS;
}

int check_parameters(int argc, char * const argv[])
{
    int count = 1;

    if (!argv)
        return FAILURE;
    while (count < argc) {
        if (!argv[count])
            return FAILURE;
        if (argv[count][0] == '-' && check_options(&count, argv) != SUCCESS)
            return FAILURE;
        else if (check_file(&count, argv) != SUCCESS) {
            return FAILURE;
        }
        count += 1;
    }
    return SUCCESS;
}