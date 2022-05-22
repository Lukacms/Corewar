/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** create_header
*/

#include "redcode.h"

static char **get_info_header(char *file)
{
    char **file_lines = NULL;

    if (!file)
        return NULL;
    file_lines = str_sep_to_array(file, '\n');
    if (!file_lines)
        return NULL;
    if (check_name_and_comment(file_lines) == FAILURE)
        return NULL;
    for (int i = 0; file_lines[i]; i++)
        free(file_lines[i]);
    free(file_lines);
    file_lines = str_sep_to_array(file, '"');
    return file_lines;
}

static void free_header_elements(char **file_lines, char *file)
{
    if (file_lines)
        free_array((void **)file_lines);
    if (file)
        free(file);
}

int create_header(infos_t *infos)
{
    char **file_lines = NULL;
    char *temp_file = NULL;

    infos->header.prog_size = reverse_int_bytes(infos->header.prog_size) << 8;
    infos->header.magic = reverse_int_bytes(COREWAR_EXEC_MAGIC) << 8;
    if (!infos || !infos->fd || !infos->input_name)
        return FAILURE;
    temp_file = load_file(infos->input_name);
    file_lines = get_info_header(temp_file);
    if (!file_lines) {
        free_header_elements(file_lines, temp_file);
        return FAILURE;
    }
    my_strncpy(infos->header.prog_name, file_lines[1], PROG_NAME_LENGTH + 2);
    my_strncpy(infos->header.comment, file_lines[3], COMMENT_LENGTH + 2);
    fwrite(&infos->header, sizeof(header_t), 1, infos->fd);
    free_header_elements(file_lines, temp_file);
    return SUCCESS;
}
