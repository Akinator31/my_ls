/*
** EPITECH PROJECT, 2024
** mylist.h
** File description:
** header file for linked list structure
*/

#ifndef MYLIST_H
    #define MYLIST_H
    #include <dirent.h>

typedef struct linked_list {
    struct dirent *data;
    struct linked_list *next;
} linked_list_t;

linked_list_t *new_list(void);
int is_empty_list(linked_list_t *lt);
int list_length(linked_list_t *lt);
linked_list_t *push_back_list(linked_list_t *lt, struct dirent *data);
linked_list_t *push_front_list(linked_list_t *lt, struct dirent *data);
linked_list_t *pop_back_list(linked_list_t *lt);
linked_list_t *pop_front_list(linked_list_t *lt);
linked_list_t *clear_list(linked_list_t *lt);
linked_list_t *sort_list(linked_list_t *lt);
void print_list(linked_list_t *lt);

#endif
