/*
** EPITECH PROJECT, 2022
** Corewar [WSL: Manjaro]
** File description:
** create_warrior
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"

static const u_int magic_nbr_len = 4;

static int give_id_and_adress(warrior_t *warrior, corewar_t *corewar)
{
    if (corewar->params->a_parameter)
        warrior->instruction_address =
        (u_int){my_getnbr(corewar->params->a_parameter)};
    if (corewar->params->n_parameter)
        warrior->id = (u_int){my_getnbr(corewar->params->n_parameter)};
    if (!corewar->params->n_parameter) {
        warrior->id = corewar->warrior_list.id_of_warriors;
        corewar->warrior_list.id_of_warriors += 1;
    }
    if (!corewar->params->a_parameter)
        warrior->instruction_address = (u_int){MEM_SIZE /
        (corewar->warrior_list.nbr_of_warriors + 1) % MEM_SIZE};
    corewar->params->a_parameter = NULL;
    corewar->params->n_parameter = NULL;
    return SUCCESS;
}

static int give_warrior_dna(warrior_t *warrior, corewar_t *corewar,
char *byte_file)
{
    char *warrior_code = {0};
    int len_name = {0};

    if (!warrior || !byte_file)
        return FAILURE;
    warrior_code = read_file(byte_file);
    warrior->reg = malloc(sizeof(int) * REG_NUMBER);
    warrior->filename = my_strdup(byte_file);
    warrior->size = get_size_of_file(warrior->filename);
    if (!warrior_code || !warrior->reg)
        return FAILURE;
    warrior->save = warrior_code;
    warrior->warrior_code = warrior->save + START_CODE;
    len_name = get_len_of_name(warrior->save + magic_nbr_len);
    warrior->name = my_strndup(warrior->save + magic_nbr_len, len_name);
    warrior->name[len_name] = '\0';
    warrior->cycle_rest = 0;
    give_id_and_adress(warrior, corewar);
    return SUCCESS;
}

int create_warrior(corewar_t *corewar, char *byte_file)
{
    warrior_t *warrior = malloc(sizeof(warrior_t));

    warrior->reg = malloc(sizeof(int) * (REG_NUMBER));
    warrior->carry = 0;
    if (!warrior || warrior->reg || give_warrior_dna(warrior, corewar,
        byte_file) != SUCCESS)
        return FAILURE;
    corewar->warrior_list.nbr_of_warriors += 1;
    warrior->pc = warrior->instruction_address;
    if (!corewar->warrior_list.head) {
        warrior->next = warrior;
        warrior->prev = warrior;
        corewar->warrior_list.head = warrior;
        return SUCCESS;
    }
    corewar->warrior_list.head->prev->next = warrior;
    warrior->prev = corewar->warrior_list.head->prev;
    corewar->warrior_list.head->prev = warrior;
    warrior->next = corewar->warrior_list.head;
    return SUCCESS;
}
