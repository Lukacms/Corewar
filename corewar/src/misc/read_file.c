/*
** EPITECH PROJECT, 2022
** Corewar [WSL: Manjaro]
** File description:
** read_file
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *read_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buff = malloc(1);
    int offset = 0;
    int len;

    while ((len = read(fd, buff + offset, 1)) > 0) {
        offset += 1;
        buff = realloc(buff, offset + 1);
    }
    buff[offset + 1] = '\0';
    close(fd);
    return buff;
}