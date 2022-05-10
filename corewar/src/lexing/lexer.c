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
    for (int i = 0; cpy[i] != '\0'; i++) {
        cpy++;
        if (cpy[i] == '.')
            break;
    }
    if (my_strcmp(cpy, ".cor") != 0)
        return FAILURE;
    free(cpy);
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
    for (int a = 0; a <= 24; a += 8) {
        nb |= (tmp | (unsigned char){str[i]}) << a;
        tmp = 0;
        i++;
    }
    if (nb != 15369203)
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
