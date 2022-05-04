/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** main
*/

#include "redcode.h"

int main(int argc, char * const argv[])
{
    if (argc != 2)
        return display_help(FAILURE, FILE_HELP);
    return launch(argc, argv);
}
