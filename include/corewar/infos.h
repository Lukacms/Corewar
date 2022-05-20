/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** infos
*/

#ifndef INFOS_H_
    #define INFOS_H_

    #define MEM_SIZE (6 * 1024)
    #define CYCLE_TO_DIE 1536 // number of cycle before being declared dead
    #define CYCLE_DELTA 5
    #define IDX_MOD 512 // modulo of the index <
    #define NBR_LIVE 40
    #define COREWAR_EXEC_MAGIC 0xea83f3 //magic ^^
    #define REG_NUMBER 16 // r1 <--> rx
    #define IND_SIZE 2
    #define DIR_SIZE 4
    #define T_REG 1 // register
    #define T_DIR 2 // direct (ld %1,r1 put 1 into r1)
    #define T_IND 4 // see op.h
    #define T_LAB 8 // LABEL
    #define REG_SIZE DIR_SIZE
    #define START_CODE 2192

#endif /* !INFOS_H_ */
