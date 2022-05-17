/*
** EPITECH PROJECT, 2022
** my_strcmp_insensitive
** File description:
** my_strcmp_insensitive
*/

#include "redcode.h"

int my_strcmp_insensitive(const char *s1, const char *s2)
{
    char *temp = my_strdup(s1);

    if (!s1 || !s2 || !my_str_isalpha(s1) || !my_str_isalpha(s2))
        return -1;
    temp = my_strlowcase(temp);
    for (int i = 0; temp[i] != '\0' && s2[i] != '\0'; i++) {
        if (temp[i] != s2[i] && temp[i] - 32 != s2[i]) {
            free(temp);
            return -1;
        }
    }
    free(temp);
    return 0;
}
