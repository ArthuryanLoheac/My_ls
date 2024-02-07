/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** Write a function that concatenates two strings
*/
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int len_dest = my_strlen(dest);
    int len_src = my_strlen(src);

    for (int i = 0; i <= len_src; i++) {
        dest[len_dest + i] = src[i];
    }
    return dest;
}
