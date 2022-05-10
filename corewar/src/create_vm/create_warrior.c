/*
** EPITECH PROJECT, 2022
** Corewar [WSL: Manjaro]
** File description:
** create_warrior
*/

#include "corewar.h"
#include "my.h"

static const u_int magic_nbr_len = 4;

static int give_warrior_dna(warrior_t *warrior, warriors_list_t *warriors_list,
                            char *byte_file)
{
    char *warrior_code = {0};
    int len_name = {0};

    if (!warrior || !byte_file)
        return FAILURE;
    warrior_code = read_file(byte_file);
    if (!warrior_code)
        return FAILURE;
    warrior_code += magic_nbr_len;
    len_name = get_len_of_name(warrior_code);
    warrior->name = malloc(sizeof(char) * (len_name + 1));
    my_strncpy(warrior->name, byte_file, len_name);
    warrior->name[len_name] = '\0';
    warrior->id = warriors_list->id_of_warriors;
    warriors_list->id_of_warriors += 1;
    return SUCCESS;
}

int create_warrior(corewar_t *corewar, char *byte_file)
{
    warrior_t *warrior = malloc(sizeof(warrior_t));

    if (!warrior || give_warrior_dna(warrior,
        &corewar->warrior_list, byte_file) != SUCCESS)
        return FAILURE;
    corewar->warrior_list.nbr_of_warriors += 1;
    if (!corewar->warrior_list.head) {
        warrior->next = warrior;
        warrior->prev = warrior;
        return SUCCESS;
    }
    corewar->warrior_list.head->prev->next = warrior;
    warrior->prev = corewar->warrior_list.head->prev;
    corewar->warrior_list.head->prev = warrior;
    warrior->next = corewar->warrior_list.head;
    return SUCCESS;
}