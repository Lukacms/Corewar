/*
** EPITECH PROJECT, 2022
** Corewar [WSL : Manjaro]
** File description:
** dump_memory
*/

#include "corewar.h"
#include "my.h"

int dump_memory(corewar_t *corewar)
{
    u_int index = 0;
    u_int count = 0;
    int flag = 0;

    if (!corewar)
        return FAILURE;
    for (; count < MEM_SIZE; count += 1, index += 1) {
        if (index > 32) {
            index = 0;
            my_printf("\n");
            flag = 0;
        }
        if (flag == 0) {
            my_printf("%x", corewar->memory[count]);
            flag = 1;
        } else
            my_printf(" %x", corewar->memory[count]);
    }
    my_printf("\n");
    return SUCCESS;
}
