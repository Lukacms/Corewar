/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** free_collected_infos
*/

#include <stdlib.h>
#include "redcode.h"
#include "my.h"

void free_collected_infos(infos_t *infos)
{
    if (!infos)
        return;
    fclose(infos->fd);
    free_array((void **)infos->file);
    if (infos->input_name)
        free(infos->input_name);
    if (infos->output_filename)
        free(infos->output_filename);
    free_instructions(infos);
}
