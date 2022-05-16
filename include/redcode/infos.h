/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** infos
*/

#ifndef INFOS_H_
    #define INFOS_H_

    #include <stdio.h>

    #define IDX_MOD 512 // modulo of the index <
    #define MAX_ARGS_NUMBER 4 // this may not be changed 2^*IND_SIZE

    #define COMMENT_CHAR '#'
    #define LABEL_CHAR ':'
    #define DIRECT_CHAR '%'
    #define SEPARATOR_CHAR ','

    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

    #define NAME_CMD_STRING ".name"
    #define COMMENT_CMD_STRING ".comment"

    #define REG_NUMBER 16 // r1 <--> rx

    #define T_REG 1 // register
    #define T_DIR 2 // direct (ld #1,r1 put 1 into r1)
    #define T_IND 4 // see op.h
    #define T_LAB 8 // LABEL

    #define IND_SIZE 2
    #define DIR_SIZE 4
    #define REG_SIZE DIR_SIZE

    #define PROG_EXTENSION_LENGTH 5
    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048

    #define COREWAR_EXEC_MAGIC 0xea83f3 //magic ^^

typedef char code_t;
typedef char name_t;
typedef char comment_t;

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
    char nbr_args;
    code_t type[MAX_ARGS_NUMBER];
    opcode_t cmd;
    int nbr_cycles;
    char *comment;
} op_t;

typedef struct opnode_s {
    opcode_t type;
    char **args;
    struct opnode_s *prev;
    struct opnode_s *next;
} opnode_t;

typedef struct basics_s {
    name_t *name;
    comment_t *comment;
} basics_t;

typedef struct infos_s {
    char **file;
    char *output_filename;
    char *input_name;
    FILE *fd;
    basics_t basics;
    opnode_t *head;
    unsigned int size;
} infos_t;

#endif /* !INFOS_H_ */
