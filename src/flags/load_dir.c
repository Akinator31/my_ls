/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-myls-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** display_dir
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include "../../include/my_printf.h"
#include "../../include/my_lib.h"
#include "../../include/my_ls.h"
#include "../../include/my_list.h"

void handle_open_errors(DIR *current)
{
    if (current == NULL) {
        my_printf("Error when opening dir: %s\n", strerror(errno));
        exit(84);
    }
}

int load_dir(char *filepath, int *flags, char **av)
{
    DIR *current;
    struct dirent *dir_info;
    dir_t *dir_arr;
    linked_list_t *dir_list = new_list();

    current = opendir(filepath);
    handle_open_errors(current);
    dir_info = readdir(current);
    while (dir_info) {
        dir_list = push_back_list(dir_list, dir_info);
        dir_info = readdir(current);
    }
    dir_list = sort_list(dir_list);
    print_list_for_one_dir(dir_list, flags[0]);
    dir_list = clear_list(dir_list);
    closedir(current);
}

int load_multiple_dir(char *filepath, int *flags, char **av)
{
    DIR *current;
    struct dirent *dir_info;
    dir_t *dir_arr;
    linked_list_t *dir_list = new_list();

    current = opendir(filepath);
    handle_open_errors(current);
    dir_info = readdir(current);
    while (dir_info) {
        dir_list = push_back_list(dir_list, dir_info);
        dir_info = readdir(current);
    }
    dir_list = sort_list(dir_list);
    print_list_for_multiple_dir(dir_list, flags[0]);
    dir_list = clear_list(dir_list);
    closedir(current);
}
