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

int lexer_warrior(char * const filename);

int create_warrior(corewar_t *corewar, char *byte_file);

int generate_warriors(corewar_t *corewar, int argc, char * const argv[]);

int set_warriors_in_mem_loop(corewar_t *corewar);

int get_size_of_file(char * const filename);

int fill_registers(corewar_t *corewar, warrior_t *warrior, int *registers);

int launch_which_instruction(corewar_t *corewar);

int battlefield(corewar_t *corewar);

int instruction_add(warrior_t *warrior, corewar_t *corewar);

int instruction_sub(warrior_t *warrior, corewar_t *corewar);

int instruction_sti(warrior_t *warrior, corewar_t *corewar);

int instruction_ld(warrior_t *warrior, corewar_t *corewar);

int instruction_aff(warrior_t *warrior, corewar_t *corewar);

int instruction_zjump(warrior_t *warrior, corewar_t *corewar);

int from_byte_to_nbr(warrior_t *warrior, corewar_t *corewar, int opt);

int check_parameters(int argc, char * const argv[]);

int instruction_live(warrior_t *warrior, corewar_t *corewar);

int dump_memory(corewar_t *corewar);

#endif /* !COREWAR_H_ */
