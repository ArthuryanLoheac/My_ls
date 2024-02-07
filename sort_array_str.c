/*
** EPITECH PROJECT, 2023
** sort_array_str
** File description:
** sort_array_str
*/
#include "my.h"

static void swap_two_str(char *a, char *b)
{
    char temp[256];

    my_strcpy(temp, a);
    my_strcpy(a, b);
    my_strcpy(b, temp);
}

static int my_strcmp(char *a, char *b)
{
    int min_len = my_strlen(a);

    if (my_strlen(b) < min_len) {
        min_len = my_strlen(b);
    }
    for (int i = 0; i <= min_len; i++) {
        if (a[i] < b[i]) {
            return -1;
        }
        if (a[i] > b[i]) {
            return 1;
        }
    }
    return 0;
}

static int comparaison(char *a, char *b)
{
    if (a[0] != '.' && b[0] != '.') {
        return my_strcmp(a, b);
    }
    if (a[0] == '.' && b[0] == '.') {
        return my_strcmp(a + 1, b + 1);
    }
    if (a[0] != '.' && b[0] == '.') {
        return my_strcmp(a, b + 1);
    }
    if (a[0] == '.' && b[0] != '.') {
        return my_strcmp(a + 1, b);
    }
    return 0;
}

static void compare_and_swap(int a, int b, char **str_files)
{
    char b_lower[256];
    char a_lower[256];

    my_strcpy(a_lower, str_files[a]);
    my_strcpy(b_lower, str_files[b]);
    my_strlowcase(a_lower);
    my_strlowcase(b_lower);
    if (comparaison(a_lower, b_lower) == 1) {
        swap_two_str(str_files[a], str_files[b]);
    }
}

void sort_array_str(char **str_files, int len)
{
    for (int i = len - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            compare_and_swap(j, j + 1, str_files);
        }
    }
}
