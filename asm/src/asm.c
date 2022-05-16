/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** asm
*/

#include "redcode.h"
#include "my.h"

char *get_output_filename(char *input_filename)
{
    char *temp = NULL;
    char *filename = NULL;

    if (!input_filename)
        return NULL;
    filename =
        malloc(sizeof(char) * (PROG_NAME_LENGTH + PROG_EXTENSION_LENGTH));
    if (!filename)
        return NULL;
    temp = my_strndup(input_filename,
        my_strlen(input_filename) - my_strlen(input_filename - 3));
    my_strcpy(filename, temp);
    my_strcpy(filename + my_strlen(temp), ".cor");
    for (int i = my_strlen(filename); i < PROG_NAME_LENGTH; i++)
        filename[i] = '\0';
    free(temp);
    return filename;
}

char *get_output_filename_no_ext(char *output_filename)
{
    char *filename_no_ext = NULL;

    filename_no_ext = my_strndup(output_filename,
        my_strlen(output_filename) - PROG_EXTENSION_LENGTH + 1);
    if (!filename_no_ext)
        return NULL;
    return filename_no_ext;
}

static int analyse_file(infos_t *infos)
{
    if (lexer(infos) != SUCCESS)
        return FAILURE;
    if (parser(infos) != SUCCESS)
        return FAILURE;
    return compile(infos);
}

int launch(int argc, char * const argv[])
{
    infos_t infos = {0};

    if (!argv || argc != 2 || check_args(argv))
        return FAILURE;
    if (my_strcmp(argv[1], "-h") == SUCCESS && !argv[2])
        return display_help(SUCCESS, HELP_ASM);
    infos.input_name = my_strdup(argv[1]);
    if (!(infos.output_filename = get_output_filename(infos.input_name)))
        return FAILURE;
    if (!(infos.fd = fopen(infos.output_filename, "w")))
        return FAILURE;
    create_header(infos.fd, infos.output_filename);
    return analyse_file(&infos);
}
