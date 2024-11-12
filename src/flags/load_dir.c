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
#include "../../include/my_printf.h"
#include "../../include/my_lib.h"
#include "../../include/my_ls.h"
#include "../../include/my_list.h"

int load_dir(char *filepath, int *flags)
{
    DIR *current;
    struct dirent *dir_info;
    dir_t *dir_arr;
    linked_list_t *dir_list = new_list();

    current = opendir(filepath);
    if (current == NULL) {
        perror("Error when opening dir");
        return 84;
    }
    dir_info = readdir(current);
    while (dir_info) {
        dir_list = push_back_list(dir_list, dir_info);
        dir_info = readdir(current);
    }
    dir_list = sort_list(dir_list);
    print_list(dir_list, flags[0]);
    dir_list = clear_list(dir_list);
    closedir(current);
}
