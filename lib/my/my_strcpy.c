/*
** EPITECH PROJECT, 2021
** my_strcpy.c
** File description:
** task01d06
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i += 1)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
