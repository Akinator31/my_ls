/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-myls-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** add_data
*/

#include <stdlib.h>
#include "../../include/my_lib.h"
#include "../../include/my_list.h"
#include "../../include/my_printf.h"

linked_list_t *push_back_list(linked_list_t *lt, struct dirent *data)
{
    linked_list_t *new_element;
    linked_list_t *temp = lt;

    new_element = malloc(sizeof(*new_element));
    new_element->data = data;
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

    new_element = malloc(sizeof(*new_element));
    new_element->data = data;
    new_element->next = NULL;
    if (is_empty_list(lt))
        return new_element;
    new_element->next = lt;
    return lt;
}
