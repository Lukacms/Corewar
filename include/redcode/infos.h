/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** infos
*/

#ifndef INFOS_H_
    #define INFOS_H_

    #include <stdbool.h>
    #include <stdio.h>

    #define IDX_MOD 512 // modulo of the index <
    #define MAX_ARGS_NUMBER 4 // this may not be changed 2^*IND_SIZE

    #define COMMENT_CHAR '#'
    #define LABEL_CHAR ':'
    #define DIRECT_CHAR '%'
    #define SEPARATOR_CHAR ','
    #define REG_CHAR 'r' // after, getnbr from 1 to 16

    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

    #define NAME_CMD_STRING ".name"
    #define COMMENT_CMD_STRING ".comment"

    #define REG_NUMBER 16 // r1 <--> rx

    #define T_REG 1 // register
    #define T_DIR 2 // direct (ld %1,r1 put 1 into r1)
    #define T_IND 4 // see op.h
    #define T_LAB 8 // LABEL

    #define ONEARG 1
    #define REG_TRUE_SIZE 1
    #define IND_SIZE 2
    #define DIR_SIZE 4
    #define REG_SIZE DIR_SIZE

    #define PROG_EXTENSION_LENGTH 5
    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048

    #define COREWAR_EXEC_MAGIC 0xea83f3 //magic ^^

typedef struct header_s {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

typedef char code_t;
typedef char name_t;
typedef char comment_t;
typedef char label_t;
typedef unsigned char nb_t;

typedef enum opcode_s {
    LIVE = 1,
    LD,
    ST,
    ADD,
    SUB,
    AND,
    OR,
    XOR,
    ZJUMP,
    LDI,
    STI,
    FORK,
    LLD,
    LLDI,
    LFORK,
    AFF,
    NOTHING
} opcode_t;

typedef struct op_s {
    char *mnemonique;
    nb_t nbr_args;
    code_t type[MAX_ARGS_NUMBER];
    opcode_t cmd;
    int nbr_cycles;
    char *comment;
    bool print_params;
    bool index[MAX_ARGS_NUMBER];
} op_t;

typedef struct args_s {
    char *arg;
    label_t type;
    bool is_lab;
    int offset;
    struct args_s *prev;
    struct args_s *next;
} args_t;

typedef struct opnode_s {
    opcode_t type;
    bool params_type;
    args_t *head;
    unsigned char size;
    char *fun_name;
    char cycle;
    struct opnode_s *prev;
    struct opnode_s *next;
} opnode_t;

typedef struct infos_s {
    header_t header;
    char **file;
    char *output_filename;
    char *input_name;
    FILE *fd;
    opnode_t *head;
    unsigned int size;
} infos_t;

typedef int (*type_handler_t)(char *param, args_t *node);

typedef struct param_type_s {
    code_t type;
    type_handler_t param_handler;
} param_type_t;

#endif /* !INFOS_H_ */
