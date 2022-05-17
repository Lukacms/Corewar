/*
** EPITECH PROJECT, 2022
** str_sep_to_array
** File description:
** str_sep_to_array
*/

#include "redcode.h"

static int remove_space(char *str, char sep)
{
    int i = 0;

    for (; str[i] == sep || str[i] == ' ' || str[i] == '\t'; i++);
    return i;
}

static int count_between_space(char *str, char sep)
{
    int i = 0;

    for (; str[i] != sep && str[i] != '\0'; i++);
    return i + 1;
}

static int count_words(char *str, char sep)
{
    int count = 0;

    for (int i = remove_space(str, sep); i < my_strlen(str);
        i += count_between_space(str + i, sep))
        ++count;
    return count;
}

static int rm_space_in_str(char *str)
{
    for (int i = my_strlen(str) - 1; (str[i] == ' ' || str[i] == '\t')
        && i >= 0; i--)
        str[i] = '\0';
    return 0;
}

char **str_sep_to_array(char *str, char sep)
{
    int k = 0;
    char **array = NULL;
    int words = 0;

    if (str == NULL || !my_strcmp(str, "")
        || remove_space(str, sep) == my_strlen(str))
        return NULL;
    words = count_words(str, sep);
    array = (char **)malloc(sizeof(char *) * (words + 1));
    for (int i = remove_space(str, sep); i < my_strlen(str);
        i += count_between_space(str + i, sep)) {
        array[k] = (char *)my_strndup(str + i + remove_space(str + i, sep),
        count_between_space(str + i + remove_space(str + i, sep), sep) - 1);
        rm_space_in_str(array[k]);
        ++k;
    }
    array[words] = NULL;
    return array;
}
