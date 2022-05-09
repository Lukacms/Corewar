/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** compile
*/

#include "redcode.h"

char *fill_header(int size, int magic)
{
    char *name_header = malloc(size);
    unsigned char temp = 0;

    if (!name_header)
        return NULL;
    for (int i = 0; i < (size / 8); i++)
        name_header[i] = '\0';
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

static char *format_name_header(char *output_filename)
{
    char *name_header = NULL;
    char *filename_no_ext = NULL;

    if (!output_filename)
        return NULL;
    filename_no_ext = get_output_filename_no_ext(output_filename);
    if (!filename_no_ext)
        return NULL;
    name_header = fill_header(PROG_NAME_LENGTH, COREWAR_EXEC_MAGIC);
    if (!name_header)
        return NULL;
    my_strcpy(name_header + 4, filename_no_ext);
    return name_header;
}

int create_header(FILE *fp, char *output_filename)
{
    char *name_header = NULL;

    if (!fp || !output_filename)
        return FAILURE;
    name_header = format_name_header(output_filename);
    if (!name_header)
        return FAILURE;
    fwrite(name_header, 1, PROG_NAME_LENGTH, fp);
    free(name_header);
    free(output_filename);
    return SUCCESS;
}

