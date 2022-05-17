/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** lexer
*/

#include <stddef.h>
#include <stdlib.h>
#include "corewar.h"
#include "my.h"

static int check_extension(char * const filename)
{
    char *cpy = NULL;

    if (filename == NULL)
        return FAILURE;
    cpy = my_strdup(filename);
    for (int i = 0; cpy[0] != '\0'; i++) {
        cpy++;
        if (cpy[0] == '.')
            break;
    }
    if (my_strcmp(cpy, ".cor") != 0)
        return FAILURE;
    cpy = NULL;
    return SUCCESS;
}

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
    for (int a = 24; i < 4; a -= 8) {
        tmp |=  (unsigned char){str[i]} << a;
        nb |= tmp;
        tmp = 0;
        i++;
    }
    if (nb != COREWAR_EXEC_MAGIC)
        return FAILURE;
    return SUCCESS;
}

int lexer_vm(char * const filename)
{
    if (check_extension(filename) != SUCCESS)
        return FAILURE;
    if (check_magic_nb(filename) != SUCCESS)
        return FAILURE;
    return SUCCESS;
}
