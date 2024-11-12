/*
** EPITECH PROJECT, 2024
** my_strcmp.c
** File description:
** task06
*/

#include "my.h"

char is_alpha(char act_char)
{
    if ((act_char >= 'A') && (act_char <= 'Z'))
        return act_char + 32;
    return act_char;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (int i = 0; (s1[i] != '\0') || (s2[i] != '\0'); i++) {
        if (is_alpha(s1[i]) != is_alpha(s2[i])) {
            return s1[i] - s2[i];
        }
    }
    return s1[i] != s2[i];
}
