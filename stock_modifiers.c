/*
** EPITECH PROJECT, 2023
** stock modifiers
** File description:
** stock the modifiers from parameters into a str
*/
#include "my.h"
#include <stdlib.h>

void set_zeros(char *str, int len)
{
    for (int i = 0; i < len; i++) {
        str[i] = '\0';
    }
}

char *stock_modifiers(int argc, char **argv)
{
    char *modifiers;
    int len = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            len += my_strlen(argv[i]) - 1;
        }
    }
    modifiers = malloc(len);
    set_zeros(modifiers, len + 1);
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            my_strcat(modifiers, argv[i] + 1);
        }
    }
    return modifiers;
}
