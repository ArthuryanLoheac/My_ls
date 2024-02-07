/*
** EPITECH PROJECT, 2023
** is in str
** File description:
** return 1 if the char c is in str
*/
#include "my.h"

int is_in_str(char c, char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == c) {
            return 1;
        }
    }
    return 0;
}
