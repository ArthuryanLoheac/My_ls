/*
** EPITECH PROJECT, 2023
** total_path
** File description:
** total_path
*/
#include <stdlib.h>
#include "my.h"

static void modif_str(int i, char *str, char *path, char *path_start)
{
    if (i == 0) {
        my_strcpy(str, path_start);
        my_strcat(str, path);
    } else {
        my_strcpy(str, path_start);
        my_strcat(str, "/");
        my_strcat(str, path);
    }
}

char *total_path(char *path, char *path_start)
{
    char *str;
    int i = 0;

    if (path_start[my_strlen(path_start) - 1] != '/') {
        i = 1;
    }
    if (path_start[0] == '\0') {
        return path;
    }
    str = malloc(sizeof(char) * (my_strlen(path)
        + my_strlen(path_start) + i) + 1);
    if (str == NULL) {
        exit(84);
    }
    modif_str(i, str, path, path_start);
    return str;
}
