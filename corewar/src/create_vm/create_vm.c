/*
** EPITECH PROJECT, 2022
** Corewar [WSL: Manjaro]
** File description:
** create_corewar_struct
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"

corewar_t *create_vm(void)
{
    corewar_t *corewar = malloc(sizeof(corewar_t));

    if (!corewar)
        return NULL;
    corewar->warrior_list.head = NULL;
    corewar->warrior_list.nbr_of_warriors = 0;
    corewar->nbr_cycles = 0;
    corewar->dump_cycles = -1;
    my_memset(corewar->memory, MEM_SIZE, '1');
    my_memset(corewar->old_memory, MEM_SIZE, '1');
    corewar->warrior_list.id_of_warriors = 0;
    return corewar;
}
