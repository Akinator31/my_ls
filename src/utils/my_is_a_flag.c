/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-myls-pavel.de-wavrechin
** File description:
** is_a_flag
*/

#include "../../include/my_ls.h"
#include "../../include/my_printf.h"

int is_a_flag(char actual_char, const flag_t *arr)
{
    for (int i = 0; arr[i].flag_char != '?'; i++) {
        if (actual_char == arr[i].flag_char) {
            return arr[i].id;
        }
    }
    return FALSE;
}
