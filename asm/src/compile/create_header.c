/*
** EPITECH PROJECT, 2022
** create_header
** File description:
** create_header
*/

#include "redcode.h"

static char *fill_header(int size, int magic)
{
    char *name_header = malloc(size);
    unsigned char temp = 0;

    if (!name_header)
        return NULL;
    if (magic == COREWAR_EXEC_MAGIC) {
        name_header[0] = '\0';
        temp = magic >> 16;
        name_header[1] = temp;
        temp = magic >> 8;
        name_header[2] = temp;
        temp = magic;
        name_header[3] = temp;
    }
    return name_header;
}

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

int create_header(FILE *fp, char *input_filename, int prog_size)
{
    char **file_lines = NULL;
    char *temp_file = NULL;
    header_t header;
    header.prog_size = reverse_int_bytes(prog_size) << 8;
    header.magic = reverse_int_bytes(COREWAR_EXEC_MAGIC) << 8;

    if (!fp || !input_filename)
        return FAILURE;
    temp_file = load_file(input_filename);
    file_lines = get_info_header(temp_file);
    if (!file_lines) {
        free_header_elements(file_lines, temp_file);
        return FAILURE;
    }
    my_strncpy(header.prog_name, file_lines[1], PROG_NAME_LENGTH + 2);
    my_strncpy(header.comment, file_lines[3], COMMENT_LENGTH + 2);
    fwrite(&header, sizeof(header_t), 1, fp);
    free_header_elements(file_lines, temp_file);
    return SUCCESS;
}
