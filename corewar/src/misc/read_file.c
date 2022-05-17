/*
** EPITECH PROJECT, 2022
** Corewar [WSL: Manjaro]
** File description:
** read_file
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "corewar.h"

char *read_file(char *filepath)
{
    int fd = 0;
    char *buff = malloc(1);
    int offset = 0;
    int len = 0;

    if (filepath == NULL || buff == NULL)
        return NULL;
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return NULL;
    while ((len = read(fd, buff + offset, 1)) > 0) {
        offset += 1;
        buff = realloc(buff, offset + 1);
        if (buff == NULL)
            return NULL;
    }
    buff[offset + 1] = '\0';
    if (close(fd) == -1)
        return NULL;
    return buff;
}
