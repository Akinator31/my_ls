/*
** EPITECH PROJECT, 2024
** mini_printf.c
** File description:
** A simple version of printf
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include "include/my_printf.h"
#include "include/my_lib.h"
#include "include/my_ls.h"

static const flag_t flag_arr[] = {
    {'a', 1},
    {'l', 2},
    {'R', 3},
    {'d', 4},
    {'r', 5},
    {'t', 6},
    {'?', 84}
};

void flag_finder(int *flags, char **av, int index)
{
    int is_a_flag_val = 0;

    for (int i = 1; av[index][i] != '\0'; i++) {
        is_a_flag_val = is_a_flag(av[index][i], flag_arr);
        if (is_a_flag_val > 0) {
            flags[is_a_flag_val - 1] = 1;
        }
    }
}

int main(int ac, char **av)
{
    int i = 1;
    int flags[sizeof(flag_arr) / sizeof(flag_t)] = {0};

    for (i; i < ac; i++) {
        if (av[i][0] == '-') {
            flag_finder(flags, av, i);
        }
    }
    for (int k = 0; k < my_arrlen(flag_arr); k++)
        my_printf("%d\n", flags[k]);
}
