/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-myls-pavel.de-wavrechin
** File description:
** my_arrlen
*/

#include "../../include/my_ls.h"
#include <stdlib.h>

int my_arrlen(const flag_t *arr)
{
    int result = 0;

    for (int i = 0; arr[i].flag_char != '?'; i++) {
        result++;
    }
    return result;
}
