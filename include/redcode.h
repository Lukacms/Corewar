/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** asm
*/

#ifndef ASM_H_
    #define ASM_H_

    #include "redcode/compil.h"
    #include "redcode/infos.h"
    #include "redcode/lexer_parser.h"
    #include "my.h"

    #include <stdlib.h>

    #define HELP_ASM "assets/asm_help.txt"
    #define SUCCESS 0
    #define FAILURE 84

int check_args(char * const argv[]);

int launch(int argc, char * const argv[]);

#endif /* !ASM_H_ */
