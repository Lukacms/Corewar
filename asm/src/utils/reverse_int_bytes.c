/*
** EPITECH PROJECT, 2022
** reverse_int_bytes
** File description:
** reverse_int_bytes
*/

#include "redcode.h"

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
