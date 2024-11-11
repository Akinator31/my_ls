/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-myls-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** info_list
*/

#include <stdlib.h>
#include "../../include/my_lib.h"
#include "../../include/my_list.h"
#include "../../include/my_printf.h"

linked_list_t *new_list(void)
{
    return NULL;
}

int is_empty_list(linked_list_t *lt)
{
    if (lt == NULL)
        return 1;
    return 0;
}

int list_length(linked_list_t *lt)
{
    int result = 0;

    while (lt != NULL) {
        result += 1;
        lt = lt->next;
    }
    return result;
}

linked_list_t *clear_list(linked_list_t *lt)
{
    if (is_empty_list(lt))
        return lt;
    while (lt != NULL)
        lt = pop_front_list(lt);
    return lt;
}
