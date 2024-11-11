/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-myls-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** remove_data
*/

#include <stdlib.h>
#include "../../include/my_lib.h"
#include "../../include/my_list.h"
#include "../../include/my_printf.h"

linked_list_t *pop_back_list(linked_list_t *lt)
{
    linked_list_t *temp = lt;
    linked_list_t *prev;

    if (is_empty_list(lt)) {
        return lt;
    }
    if (lt->next == NULL) {
        free(lt);
        lt = NULL;
        return lt;
    }
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    free(temp);
    prev->next = NULL;
    return lt;
}

linked_list_t *pop_front_list(linked_list_t *lt)
{
    linked_list_t *temp = lt->next;

    if (is_empty_list(lt)) {
        return lt;
    }
    free(lt);
    lt = NULL;
    return temp;
}
