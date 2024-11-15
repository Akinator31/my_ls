/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-myls-pavel.de-wavrechin
** File description:
** print_dir_files_l_flag
*/

#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "../../include/my_list.h"
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

int print_dir_name(char *name)
{
    my_printf("%s:\n", name);
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

void print_last_element(linked_list_t *lt, int size_max, int nlink)
{
    print_file_type(lt->data->mode);
    print_permissions(lt->data->mode);
    print_space(nlink, lt->data->nlink);
    my_printf(" %d ", lt->data->nlink);
    my_printf("%s %s ", getpwuid(lt->data->uid)->pw_name,
        getgrgid(lt->data->gid)->gr_name);
    print_space(size_max, lt->data->size);
    my_printf("%d ", lt->data->size);
    print_timestamp(lt->data->time);
    my_printf(" %s", lt->data->d_name);
    my_printf("\n");
}

void print_info(linked_list_t *lt, int size_max, int nlink)
{
    while (lt->next != NULL) {
        print_file_type(lt->data->mode);
        print_permissions(lt->data->mode);
        print_space(nlink, lt->data->nlink);
        my_printf(" %d ", lt->data->nlink);
        my_printf("%s %s ", getpwuid(lt->data->uid)->pw_name,
            getgrgid(lt->data->gid)->gr_name);
        print_space(size_max, lt->data->size);
        my_printf("%d ", lt->data->size);
        print_timestamp(lt->data->time);
        my_printf(" %s", lt->data->d_name);
        my_printf("\n");
        lt = lt->next;
    }
    print_last_element(lt, size_max, nlink);
}
