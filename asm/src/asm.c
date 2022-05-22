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
    char **parse_path = NULL;
    int size = 0;
    char *temp = NULL;

    if (!input_filename)
        return NULL;
    parse_path = str_sep_to_array(input_filename, '/');
    if (!parse_path)
        return NULL;
    size = array_size(parse_path);
    temp = my_strndup(parse_path[size - 1],
    my_strlen(parse_path[size - 1]) - 2);
    my_strcpy(temp + my_strlen(temp), ".cor");
    free_array((void **)parse_path);
    return temp;
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
    if (compile(infos) != SUCCESS)
        return FAILURE;
    return SUCCESS;
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
    if (!(infos.fd = fopen(infos.output_filename, "w+")))
        return FAILURE;
    return analyse_file(&infos);
}
