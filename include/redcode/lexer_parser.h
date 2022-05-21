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
    #define PARSER_ERR_ARGTYPE "parser error, argument is of wrong type\n"
    #define PARSER_ERR_DUP "parser error on line: %d; program failure\n"
    #define PARSER_ERR_MALLOC "parser error; malloc failure\n"
    #define PARSER_ERR_POINTER "parser error; invalid pointer\n"
    #define PARSER_ERR_LEN "parser error; param is not complete\n"
    #define PARSER_ERR_DIR "parser error; param is not a direct param\n"
    #define PARSER_ERR_IND "parser error; param is not an indirect param\n"
    #define PARSER_ERR_REG "parser error; param is not a register\n"
    #define PARSER_ERR_LAB "parser error; param is not a label\n"

    #define SEPARATOR "\t"
    #define NAME ".name"
    #define COMMENT ".comment"

int display_help(int status, char *filepath);

// lexer
int lexer(infos_t *infos);

// parser
int parser(infos_t *infos);
int add_opnode(infos_t *infos, char *line, int y);
int infos_in_opnode(char *line, opnode_t *node, int y);
int add_param_node(opnode_t *opnode, op_t op, char *args, u_int i);
int get_params(opnode_t *opnode, op_t op, char **args);
int param_infos(args_t *node, op_t op, char *arg, u_int i);
// function pointers to determine a command parameter's type
int dir_handler(char *param, args_t *node);
int reg_handler(char *param, args_t *node);
int ind_handler(char *param, args_t *node);
int reg_dir_handler(char *param, args_t *node);
int ind_dir_handler(char *param, args_t *node);
int reg_ind_handler(char *param, args_t *node);
int reg_dir_ind_handler(char *param, args_t *node);

// more generic functions
int array_size(char **array);
int check_param_pos(char **param, op_t op, u_int i);
int is_label(char *str);

#endif /* !LEXER_PARSER_H_ */
