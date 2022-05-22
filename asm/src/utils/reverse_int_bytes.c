/*
** EPITECH PROJECT, 2022
** reverse_int_bytes
** File description:
** reverse_int_bytes
*/

#include <stdio.h>
#include "redcode.h"

int print_reversed_bytes(int to_reverse, FILE *fd, int complete_byte)
{
    int temp = 0;
    int mask = 0b11111111;
    int shift = 8;
    unsigned char tmp = 0;

    for (int i = complete_byte; i >= 0; i -= 8) {
        tmp = (to_reverse >> i);
        fwrite(&tmp, ONEARG, 1, fd);
    }
    return temp;
}

int reverse_int_bytes(int to_reverse)
{
    int temp = 0;
    int mask = 0b11111111;
    int shift = 8;

    for (int i = 0; i < 3; i++) {
        temp |= (((to_reverse & mask) >> (8 * i)) << 8 * (2 - i));
        mask <<= shift;
    }
    return temp;
}
