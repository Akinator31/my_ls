/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-myls-pavel.de-wavrechin
** File description:
** my_ls
*/

#ifndef MY_LS_H
    #define MY_LS_H

typedef struct flag {
    char flag_char;
    int id;
} flag_t;

int is_a_flag(char actual_char, const flag_t *arr);
int my_arrlen(const flag_t *arr);

#endif
