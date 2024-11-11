/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-myls-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** linked_list
*/

#include <stdlib.h>
#include "../../include/my_lib.h"
#include "../../include/my_list.h"
#include "../../include/my_printf.h"

void print_list(linked_list_t *lt)
{
    if (is_empty_list(lt))
        return;
    while (!is_empty_list(lt->next)) {
        if (lt->data->d_name[0] != '.')
            my_printf("%s  ", lt->data->d_name);
        lt = lt->next;
    }
    my_printf("%s\n", lt->data->d_name);
}

int sorting_loop(int *swapped, linked_list_t *current)
{
    struct dirent *temp_data = current->data;

    if (my_strcmp(current->data->d_name, current->next->data->d_name) > 0) {
        temp_data = current->data;
        current->data = current->next->data;
        current->next->data = temp_data;
        *swapped = 1;
    }
    return *swapped;
}

linked_list_t *sort_list(linked_list_t *lt)
{
    int swapped = 1;
    linked_list_t *current;

    while (swapped) {
        swapped = 0;
        current = lt;
        while (current != NULL && current->next != NULL) {
            sorting_loop(&swapped, current);
            current = current->next;
        }
    }
    return lt;
}
