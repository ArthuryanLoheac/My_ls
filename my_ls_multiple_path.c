/*
** EPITECH PROJECT, 2023
** my_ls_multiple_path
** File description:
** my_ls_multiple_path
*/
#include "my.h"
#include <stdlib.h>

static void cpy_argv_str(char **argv, char **cpy_argv, int argc)
{
    for (int i = 0; i < argc; i++) {
        cpy_argv[i] = malloc(sizeof(char) * 256);
    }
    for (int i = 0; i < argc; i++) {
        my_strcpy(cpy_argv[i], argv[i]);
    }
}

void my_str_swap(char **str, int len)
{
    char temp[256];

    for (int i = 0; i < len / 2; i++) {
        my_strcpy(temp, str[i]);
        my_strcpy(str[i], str[len - i - 1]);
        my_strcpy(str[len - i - 1], temp);
    }
}

void my_ls_multiple_path(int argc, char **argv, char *modifiers)
{
    int pos_last_arg = 0;
    int j = 0;
    char *cpy_argv[argc];

    cpy_argv_str(argv, cpy_argv, argc);
    if (is_in_str('r', modifiers) == 1) {
        my_str_swap(cpy_argv, argc);
        j = 1;
    }
    pos_last_arg = find_last_arg(argc, cpy_argv, j);
    for (int i = 1 - j; i < argc - j; i++) {
        if (cpy_argv[i][0] != '-') {
            mini_printf("%s:\n", cpy_argv[i]);
            my_ls_with_path(cpy_argv[i], modifiers);
        }
        if (i != pos_last_arg && cpy_argv[i][0] != '-') {
            mini_printf("\n");
        }
    }
}
