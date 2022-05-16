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
    #include <stdio.h>

    #define HELP_ASM "assets/asm_help.txt"
    #define SUCCESS 0
    #define FAILURE 84
    #define FAILURE_LEX -1
    #define SUCCESS_LEX 2

int launch(int argc, char * const argv[]);

/* Headers functions */

int create_header(FILE *fp, char *output_filename);
char *fill_header(int size, int magic);

/* Filename management */

char *get_output_filename(char *input_filename);
char *get_output_filename_no_ext(char *output_filename);

int check_args(char * const argv[]);

#endif /* !ASM_H_ */
