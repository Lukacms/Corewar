/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** asm
*/

#include "redcode.h"

int launch(int argc, char * const argv[])
{
    if (!argv)
        return FAILURE;
    if (!my_strcmp(argv[1], "-h") && !argv[2])
        return display_help(SUCCESS, HELP_ASM);
    return SUCCESS;
}
