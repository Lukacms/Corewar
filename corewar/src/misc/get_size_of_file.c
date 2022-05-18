/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** get_size_of_file
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "corewar.h"

int get_size_of_file(char * const filename)
{
    int fd = 0;
    int size = 0;
    char *temp = NULL;

    if (!filename)
        return -1;
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return -1;
    temp = malloc(sizeof(char) * 2);
    if (temp == NULL)
        return -1;
    for (; read(fd, temp, 1); size += 1);
    if (close(fd) == -1)
        return -1;
    return size;
}
