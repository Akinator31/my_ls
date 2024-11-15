/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-myls-pavel.de-wavrechin
** File description:
** flag_l
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "../../include/my_ls.h"
#include "../../include/my_lib.h"
#include "../../include/my_list.h"

static int get_biggest_file(char *filepath)
{
    DIR *current = opendir(".");
    struct dirent *dir_info = readdir(current);
    struct stat info;
    int size = 0;

    while (dir_info) {
        stat(dir_info->d_name, &info);
        if ((dir_info->d_name[0] != '.') && (info.st_size > size)) {
            size = info.st_size;
        }
        dir_info = readdir(current);
    }
    closedir(current);
    return size;
}

static int get_biggest_link_nb(char *filepath)
{
    DIR *current = opendir(".");
    struct dirent *dir_info = readdir(current);
    struct stat info;
    int nlink = 0;

    while (dir_info) {
        stat(dir_info->d_name, &info);
        if ((dir_info->d_name[0] != '.') && (info.st_size > nlink)) {
            nlink = info.st_nlink;
        }
        dir_info = readdir(current);
    }
    closedir(current);
    return nlink;
}

char *get_filepath(char *filepath, char *name)
{
    char *str = malloc(sizeof(char) * 513);

    str[512] = '\0';
    if (filepath[0] == '.') {
        free(str);
        return name;
    }
    for (int i = 0; i < 512; i++) {
        str[i] = '\0';
    }
    my_strcat(str, filepath);
    my_strcat(str, "/");
    my_strcat(str, name);
    return str;
}

void fill_stat(char *filepath, char *name, struct stat *info)
{
    char *str = get_filepath(filepath, name);

    stat(str, info);
    if (my_strcmp(str, name) != 0)
        free(str);
}

static int get_total(char *filepath, int ac, char **av)
{
    DIR *current = opendir(filepath);
    struct dirent *dir_info;
    struct stat info;
    int size = 0;

    handle_open_errors(current);
    dir_info = readdir(current);
    while (dir_info) {
        fill_stat(filepath, dir_info->d_name, &info);
        if (dir_info->d_name[0] != '.') {
            size += info.st_blocks;
        }
        dir_info = readdir(current);
    }
    closedir(current);
    if (fetch_dir(ac, av) > 2)
        my_printf("%s:\n", filepath);
    my_printf("total %d\n", size / 2);
    return 0;
}

int load_dir_full_info(char *filepath, char **av, int ac)
{
    int total = get_total(filepath, ac, av);
    DIR *current = opendir(filepath);
    linked_list_t *list = new_list();
    struct dirent *dir_info = readdir(current);
    struct stat info;
    int biggest_file_size = get_biggest_file(filepath);
    int nlink_max = get_biggest_link_nb(filepath);

    while (dir_info) {
        if (dir_info->d_name[0] != '.') {
            fill_stat(filepath, dir_info->d_name, &info);
            list = push_back_list_full_info(list, &info, dir_info);
        }
        dir_info = readdir(current);
    }
    list = sort_list(list);
    print_info(list, biggest_file_size, nlink_max);
    list = clear_list(list);
    closedir(current);
}
