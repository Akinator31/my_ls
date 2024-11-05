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

static const flag_t flag_arr[] = {
    {'a'},
    {'l'},
    {'R'},
    {'d'},
    {'r'},
    {'t'},
    {'?'}
};

void flag_finder(int **flags, char **av, int index)
{
    for (int i = 0; flag_arr[i].flag != '?'; i++) {
        my_printf("av[index] : %c\n", *av[index]);
        if (av[index][] == flag_arr[i].flag) {
            *flags[i] += 1;
        }
    }
}

int main(int ac, char **av)
{
    int i = 1;
    int flags[6] = {0};

    for (i; i < ac; i++) {
        if (av[i][0] == '-') {
            flag_finder(&flags, av, i);
        }
    }
    for (int k = 0; k < 6; k++)
        my_printf("%d\n", flags[k]);
}
