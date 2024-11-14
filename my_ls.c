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
#include <unistd.h>
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
    {'-', 7},
    {'?', 84}
};
static const char *error = "ls : option invalide\n";

int fetch_dir(int ac, char **av)
{
    int result = 0;

    for (int i = 0; i < ac; i++) {
        if (av[i][0] != '-')
            result++;
    }
    return result;
}

int flag_finder(int *flags, char **av, int index)
{
    int is_a_flag_val = 0;

    for (int i = 1; av[index][i] != '\0'; i++) {
        is_a_flag_val = is_a_flag(av[index][i], flag_arr);
        if (is_a_flag_val > 0) {
            flags[is_a_flag_val - 1] = 1;
        } else {
            return 0;
        }
    }
    return 1;
}

void print_return_line(int ac, char **av, int i)
{
    if ((av[i][0] != '-') && (fetch_dir(ac, av) > 2) && (i < (ac - 1)))
                my_printf("\n");
}

int compute_args(int ac, char **av, int *flags)
{
    for (int i = 1; i < ac; i++) {
        if ((av[i][0] != '-') && flags[1]) {
            load_dir_full_info(av[i], av, flags);
            print_return_line(ac, av, i);
            continue;
        }
        if ((av[i][0] != '-') && !(fetch_dir(ac, av) > 2)) {
            load_dir(av[i], flags, av);
            print_return_line(ac, av, i);
            continue;
        }
        if ((av[i][0] != '-') && (fetch_dir(ac, av) > 2)) {
            load_multiple_dir(av[i], flags, av, i);
            print_return_line(ac, av, i);
            continue;
        }
    }
}

int main(int ac, char **av)
{
    int i = 1;
    int is_undefined_flag = 1;
    int flags[sizeof(flag_arr) / sizeof(flag_t)] = {0};

    for (i; i < ac; i++) {
        if (av[i][0] == '-') {
            is_undefined_flag = flag_finder(flags, av, i);
        }
    }
    if (is_undefined_flag == 0) {
        write(2, error, my_strlen(error));
        return 84;
    }
    if (ac < 2)
        return load_dir(".", flags, av);
    if ((ac < 3) && (flags[1]))
        return load_dir_full_info(".", av, flags);
    compute_args(ac, av, flags);
}
