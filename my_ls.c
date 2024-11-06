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
#include "include/my_utils.h"
#include "include/my_lib.h"
#include "include/my_ls.h"

void flag_finder(int *flags, char **av, int index)
{
    int is_a_flag_val = 0;

    for (int i = 1; av[index][i] != '\0'; i++) {
        is_a_flag_val = is_a_flag(av[index][i]);
        if (is_a_flag_val > 0) {
            flags[is_a_flag_val - 1] = 1;
        } else {
            flags[is_a_flag_val - 1] = 0;
        }
    }
}

int main(int ac, char **av)
{
    int i = 1;
    int flags[6] = {0, 0, 0, 0, 0, 0};

    for (i; i < ac; i++) {
        if (av[i][0] == '-') {
            flag_finder(flags, av, i);
        }
    }
    for (int k = 0; k < 6; k++)
        my_printf("%d\n", flags[k]);
}
