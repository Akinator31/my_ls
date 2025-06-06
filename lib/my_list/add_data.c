/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-myls-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** add_data
*/

#include <stdlib.h>
#include <sys/stat.h>
#include "../../include/my_lib.h"
#include "../../include/my_list.h"
#include "../../include/my_printf.h"

linked_list_t *push_back_list(linked_list_t *lt, struct dirent *data,
    char *filepath)
{
    linked_list_t *new_element;
    linked_list_t *temp = lt;
    my_info_t *info = malloc(sizeof(*info));

    info->d_name = my_strdup(data->d_name);
    info->pathname = filepath;
    new_element = malloc(sizeof(*new_element));
    new_element->data = info;
    new_element->next = NULL;
    if (is_empty_list(lt))
        return new_element;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_element;
    return lt;
}

linked_list_t *push_back_list_full_info(linked_list_t *lt,
    struct stat *data, struct dirent *data_dir)
{
    linked_list_t *new_element;
    linked_list_t *temp = lt;
    my_info_t *info = malloc(sizeof(*info));

    info->d_name = my_strdup(data_dir->d_name);
    info->gid = data->st_gid;
    info->mode = data->st_mode;
    info->nlink = data->st_nlink;
    info->size = data->st_size;
    info->time = data->st_mtime;
    info->uid = data->st_uid;
    new_element = malloc(sizeof(*new_element));
    new_element->data = info;
    new_element->next = NULL;
    if (is_empty_list(lt))
        return new_element;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_element;
    return lt;
}

linked_list_t *push_front_list(linked_list_t *lt, struct dirent *data)
{
    linked_list_t *new_element;
    my_info_t *info = malloc(sizeof(*info));

    info->d_name = my_strdup(data->d_name);
    new_element = malloc(sizeof(*new_element));
    new_element->data = info;
    new_element->next = NULL;
    if (is_empty_list(lt))
        return new_element;
    new_element->next = lt;
    return lt;
}
