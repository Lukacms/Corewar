/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** corewar
*/

#ifndef COREWAR_H_
    #define COREWAR_H_

    #define SUCCESS 0
    #define FAILURE 84

    #include "corewar/infos.h"
    #include "corewar/struct.h"

int launch(int argc, char * const argv[]);

// Create the VM
corewar_t *create_vm(void);

// Open a file and set it in a string
char *read_file(char *filepath);

// Get the length of the name of the warrior
int get_len_of_name(char *byte_file);

int check_opt(char * const argv[], int *i, corewar_t *corewar);

int arg_handling(int argc, char * const argv[], corewar_t *corewar);

int lexer_vm(char * const filename);

int create_warrior(corewar_t *corewar, char *byte_file);

int generate_warriors(corewar_t *corewar, int argc, char * const argv[]);

int set_warriors_in_mem_loop(corewar_t *corewar);

int get_size_of_file(char * const filename);

#endif /* !COREWAR_H_ */
