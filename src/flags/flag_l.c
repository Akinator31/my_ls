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

static void print_file_type(mode_t mode)
{
    if ((mode & 0100000) == (0100000))
        my_printf("-");
    if ((mode & 0040000) == (0040000))
        my_printf("d");
    if ((mode & 0120000) == (0120000))
        my_printf("l");
    if ((mode & 0060000) == (0060000))
        my_printf("b");
    if ((mode & 0020000) == (0020000))
        my_printf("b");
}

static void print_permissions(mode_t mode)
{
    my_printf("%c", (mode & 00400) == (00400) ? 'r' : '-');
    my_printf("%c", (mode & 00200) == (00200) ? 'w' : '-');
    my_printf("%c", (mode & 00100) == (00100) ? 'x' : '-');
    my_printf("%c", (mode & 00040) == (00040) ? 'r' : '-');
    my_printf("%c", (mode & 00020) == (00020) ? 'w' : '-');
    my_printf("%c", (mode & 00010) == (00010) ? 'x' : '-');
    my_printf("%c", (mode & 00004) == (00004) ? 'r' : '-');
    my_printf("%c", (mode & 00002) == (00002) ? 'w' : '-');
    my_printf("%c", (mode & 00001) == (00001) ? 'x' : '-');
}

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

static void get_total(char *filepath)
{
    DIR *current = opendir(filepath);
    struct dirent *dir_info = readdir(current);
    struct stat info;
    int size = 0;

    while (dir_info) {
        stat(dir_info->d_name, &info);
        if (dir_info->d_name[0] != '.') {
            size += info.st_blocks;
        }
        dir_info = readdir(current);
    }
    closedir(current);
    my_printf("total %d\n", size / 2);
}

void print_space(int size_max, int size)
{
    int nb_len = my_get_nb_length(size_max) - my_get_nb_length(size);

    for (int i = 0; i < nb_len; i++) {
        my_printf(" ");
    }
}

void print_timestamp(time_t date)
{
    char *timestamp = ctime(&date);
    char **separate_date = my_str_to_word_array(timestamp);

    my_printf("%s %s %s:%s", separate_date[1],
        separate_date[2], separate_date[3], separate_date[4]);
    for (int i = 0; separate_date[i] != NULL; i++) {
        free(separate_date[i]);
    }
    free(separate_date);
}

void print_info(struct stat *info, int size_max)
{
    print_file_type(info->st_mode);
    print_permissions(info->st_mode);
    my_printf(" %d ", info->st_nlink);
    my_printf("%s %s ", getpwuid(info->st_uid)->pw_name,
        getgrgid(info->st_gid)->gr_name);
    print_space(size_max, info->st_size);
    my_printf("%d ", info->st_size);
    print_timestamp(info->st_atime);
}

int load_dir_full_info(char *filepath, char **av, int *flags)
{
    DIR *current = opendir(filepath);
    struct dirent *dir_info;
    struct stat info;
    dir_t *dir_arr;
    int biggest_file_size = 0;

    get_total(filepath);
    biggest_file_size = get_biggest_file(filepath);
    dir_info = readdir(current);
    while (dir_info) {
        if (dir_info->d_name[0] != '.') {
            stat(dir_info->d_name, &info);
            print_info(&info, biggest_file_size);
            my_printf(" %s", dir_info->d_name);
            my_printf("\n");
        }
        dir_info = readdir(current);
    }
    closedir(current);
}
