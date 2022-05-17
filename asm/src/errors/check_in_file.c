/*
** EPITECH PROJECT, 2022
** check_in_file
** File description:
** check_in_file
*/

#include "redcode.h"

int check_name_and_comment(char **file_lines)
{
    int name_string_count = 0;
    int comment_string_count = 0;

    if (!file_lines)
        return FAILURE;
    for (int i = 0; file_lines[i]; i++) {
        if (my_strstr(file_lines[i], NAME_CMD_STRING))
            name_string_count++;
        else if (my_strstr(file_lines[i], COMMENT_CMD_STRING))
            comment_string_count++;
    }
    if (name_string_count == 1 && comment_string_count == 1)
        return SUCCESS;
    return FAILURE;
}
