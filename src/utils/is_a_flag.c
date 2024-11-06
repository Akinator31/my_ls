/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-myls-pavel.de-wavrechin
** File description:
** is_a_flag
*/

#include "../../include/my_ls.h"
#include "../../include/my_printf.h"

static const flag_t flag_arr[] = {
    {'a', 1},
    {'l', 2},
    {'R', 3},
    {'d', 4},
    {'r', 5},
    {'t', 6},
    {'?', 84}
};

int is_a_flag(char actual_char)
{
    for (int i = 0; flag_arr[i].flag != '?'; i++) {
        if (actual_char == flag_arr[i].flag) {
            return flag_arr[i].id;
        }
    }
    return FALSE;
}
