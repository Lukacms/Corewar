/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** lexer
*/

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include "corewar.h"
#include "my.h"

static int check_magic_nb(char * const filename)
{
    u_int nb = 0;
    u_int tmp = 0;
    char *str = NULL;
    int i = 0;

    if (filename == NULL)
        return FAILURE;
    str = read_file(filename);
    if (str == NULL)
        return FAILURE;
    for (int a = 24; i < 4; a -= 8, i += 1) {
        tmp = tmp | ((unsigned char){str[i]} << a);
        nb = nb | tmp;
        tmp = 0;
    }
    if (nb != COREWAR_EXEC_MAGIC)
        return FAILURE;
    return SUCCESS;
}

int lexer_warrior(char * const filename)
{
    if (check_magic_nb(filename) != SUCCESS) {
        write(STDERR_FILENO, "Corewar: Cannot identify the warrior.\n", 39);
        return FAILURE;
    }
    return SUCCESS;
}
