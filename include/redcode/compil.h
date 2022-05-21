/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** compil
*/

#ifndef COMPIL_H_
    #define COMPIL_H_

    #include "redcode/infos.h"

    #define COMPIL_ERR "error while compiling.\n"

typedef int (*param_handler_t)(args_t *param, FILE *fd);

typedef struct param_type_handler_s {
    code_t type;
    param_handler_t handler;
} param_type_handler_s;

int compile(infos_t *infos);
int compile_line(opnode_t *line, FILE *fd);
int compile_direct(args_t *param, FILE *fd);
int compile_indirect(args_t *param, FILE *fd);
int compile_register(args_t *param, FILE *fd);

#endif /* !COMPIL_H_ */
