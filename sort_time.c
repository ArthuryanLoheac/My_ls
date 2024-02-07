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

static int comparaison(char *a, char *b, char *path)
{
    struct stat buf_a;
    struct stat buf_b;
    char cp_a[256];
    char cp_b[256];

    my_strcpy(cp_a, total_path(a, path));
    my_strcpy(cp_b, total_path(b, path));
    stat(cp_a, &buf_a);
    stat(cp_b, &buf_b);
    if (buf_a.st_mtime < buf_b.st_mtime) {
        return 1;
    }
    return 0;
}

static void compare_and_swap(int a, int b, char **str_files, char *path)
{
    if (comparaison(str_files[a], str_files[b], path) == 1) {
        swap_two_str(str_files[a], str_files[b]);
    }
}

void sort_time(char **str_files, int len, char *path)
{
    for (int i = len - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            compare_and_swap(j, j + 1, str_files, path);
        }
    }
}
