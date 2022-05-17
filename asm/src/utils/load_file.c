/*
** EPITECH PROJECT, 2022
** load_file
** File description:
** load_file
*/

#include "redcode.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char *load_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buff = malloc(1);
    int offset = 0;
    int len;

    while ((len = read(fd, buff + offset, 1)) > 0) {
        offset += 1;
        buff = realloc(buff, offset + 1);
    }
    buff[offset] = '\0';
    return buff;
}
