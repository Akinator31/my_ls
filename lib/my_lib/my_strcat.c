/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** lib
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;

    while (dest[i] != '\0')
        i++;
    for (int e = 0; src[e] != '\0'; e++) {
        dest[i] = src[e];
        i++;
    }
    return dest;
}
