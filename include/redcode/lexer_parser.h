/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** lexer_parser
*/

#ifndef LEXER_PARSER_H_
    #define LEXER_PARSER_H_

    #include <sys/types.h>
    #include "redcode/infos.h"

    #define HELP "-h"
    #define FILE_HELP "./assets/asm_help.txt"

// errors lexer
    #define LEXER_ERR_TYPE "lexer error on line: %d; wrong type.\n"
    #define LEXER_ERR_SPACE "lexer error on line: %d; \
instructions not separated correctly.\n"
    #define LEXER_ERR_HEADER "lexer error on line: %d; wrong header\n"
    #define LEXER_LOAD_ERR "lexer error on line: %d; file couldn't be load\n"
    #define LEXER_FILE_ERR "lexer error on line: %d; file doesn't have \
enough instructions\n"

// error parser
    #define PARSER_ERR_INST "parser error on line: %d; invalid instruction\n"
    #define PARSER_ERR_NBARG "parser error on line: %d, wrong nb of arguments\n"
    #define PARSER_ERR_DUP "parser error on line: %d; program failure\n"
    #define PARSER_ERR_MALLOC "parser error; malloc failure\n"
    #define PARSER_ERR_POINTER "parser error; invalid pointer\n"

    #define SEPARATOR "\t"
    #define NAME ".name"
    #define COMMENT ".comment"

int display_help(int status, char *filepath);

// lexer
int lexer(infos_t *infos);
int get_basics(infos_t *infos, basics_t *bases);

// parser
int parser(infos_t *infos);
int add_opnode(infos_t *infos, char *line, int y);
int infos_in_opnode(char *line, opnode_t *node, int y);
int add_param_node(opnode_t *opnode, op_t op, char *args, u_int i);
int get_params(opnode_t *opnode, op_t op, char **args);
int param_infos(args_t *node, op_t op, char *arg, u_int i);

// more generic functions
int array_size(char **array);

#endif /* !LEXER_PARSER_H_ */
