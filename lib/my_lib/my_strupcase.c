/*
** EPITECH PROJECT, 2024
** my_strupcase.c
** File description:
** task08
*/

char *my_strupcase(char *str)
{
    int i;

    for (i = 0; str[i] >= '\0'; i++) {
        if ((str[i] >= 97) && (str[i] <= 122))
            str[i] -= 32;
    }
    return str;
}
