/*
** EPITECH PROJECT, 2024
** mylist.h
** File description:
** header file for linked list structure
*/

#ifndef MYLIST_H
    #define MYLIST_H
    #include <dirent.h>
    #include <sys/types.h>
    #include <fcntl.h>

typedef struct my_info {
    char *d_name;
    char *pathname;
    mode_t mode;
    nlink_t nlink;
    uid_t uid;
    gid_t gid;
    off_t size;
    time_t time;
} my_info_t;

typedef struct linked_list {
    my_info_t *data;
    struct linked_list *next;
} linked_list_t;

linked_list_t *new_list(void);
int is_empty_list(linked_list_t *lt);
int list_length(linked_list_t *lt);
linked_list_t *push_back_list(linked_list_t *lt, struct dirent *data,
    char *filepath);
linked_list_t *push_back_list_full(linked_list_t *lt, struct dirent *data);
linked_list_t *push_front_list(linked_list_t *lt, struct dirent *data);
linked_list_t *pop_back_list(linked_list_t *lt);
linked_list_t *pop_front_list(linked_list_t *lt);
linked_list_t *clear_list(linked_list_t *lt);
linked_list_t *sort_list(linked_list_t *lt);
void print_list_for_one_dir(linked_list_t *lt, int is_flag_a, char **av);
void print_list_for_multiple_dir(linked_list_t *lt,
    int is_flag_a, char **av, int i);
linked_list_t *push_back_list_full_info(linked_list_t *lt,
    struct stat *data, struct dirent *data_dir);

#endif
