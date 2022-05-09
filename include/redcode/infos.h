/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** infos
*/

#ifndef INFOS_H_
    #define INFOS_H_

    # define MEM_SIZE (6 * 1024)
    # define IDX_MOD 512 // modulo of the index <
    # define MAX_ARGS_NUMBER 4 // this may not be changed 2^*IND_SIZE

    # define COMMENT_CHAR '#'
    # define LABEL_CHAR ':'
    # define DIRECT_CHAR '%'
    # define SEPARATOR_CHAR ','

    # define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

    # define NAME_CMD_STRING ".name"
    # define COMMENT_CMD_STRING ".comment"

    # define REG_NUMBER 16 // r1 <--> rx

    # define T_REG 1 // register
    # define T_DIR 2 // direct  (ld  #1,r1  put 1 into r1)
    # define T_IND 4 // see op.h
    # define T_LAB 8 // LABEL

    # define IND_SIZE 2
    # define DIR_SIZE 4
    # define REG_SIZE DIR_SIZE

    # define PROG_EXTENSION_LENGTH 5
    # define PROG_NAME_LENGTH 128
    # define COMMENT_LENGTH 2048

    # define COREWAR_EXEC_MAGIC 0xea83f3 //magic ^^

    # define CYCLE_TO_DIE 1536 // number of cycle before beig declared dead
    # define CYCLE_DELTA 5
    # define NBR_LIVE 40

typedef char code_t;

#endif /* !INFOS_H_ */
