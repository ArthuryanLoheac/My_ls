/*
** EPITECH PROJECT, 2023
** my_ls_normal
** File description:
** my_ls_normal
*/
#include <sys/types.h>
#include <dirent.h>
#include "my.h"
#include <stdlib.h>

static int number_files(char *path, char *modifiers)
{
    DIR *dir;
    struct dirent *dire;
    int len = 0;

    dir = opendir(path);
    check_null(dir);
    dire = readdir(dir);
    while (dire != 0) {
        if (dire->d_name[0] != '.' && is_in_str('a', modifiers) != 1) {
            len++;
        }
        if (is_in_str('a', modifiers) == 1) {
            len++;
        }
        dire = readdir(dir);
    }
    closedir(dir);
    return len;
}

static void malloc_for_files(char **str_files, char *path, char *modifiers)
{
    DIR *dir;
    struct dirent *dire;
    int j = 0;

    dir = opendir(path);
    check_null(dir);
    dire = readdir(dir);
    while (dire != 0) {
        if ((dire->d_name[0] != '.' && is_in_str('a', modifiers) != 1 )
        || (is_in_str('a', modifiers) == 1)) {
            str_files[j] = malloc(sizeof(char) * 256);
            check_null(str_files[j]);
            j++;
        }
        dire = readdir(dir);
    }
    closedir(dir);
}

static void copy_name_in_str(char **str_files, char *path, char *modifiers)
{
    DIR *dir;
    struct dirent *dire;
    int j = 0;

    dir = opendir(path);
    check_null(str_files[j]);
    dire = readdir(dir);
    while (dire != 0) {
        if (dire->d_name[0] != '.' && is_in_str('a', modifiers) != 1) {
            my_strcpy(str_files[j], dire->d_name);
            j++;
        }
        if (is_in_str('a', modifiers) == 1) {
            my_strcpy(str_files[j], dire->d_name);
            j++;
        }
        dire = readdir(dir);
    }
    closedir(dir);
}

static void print_array_str(int len, char **str_files)
{
    for (int i = 0; i < len; i++) {
        mini_printf("%s", str_files[i]);
        if (i != len - 1) {
            mini_printf("  ");
        }
    }
    mini_printf("\n");
}

void my_ls_with_path(char *path, char *modifiers)
{
    char **str_files;
    int len = number_files(path, modifiers);

    str_files = malloc(sizeof(char *) * len);
    check_null(str_files);
    malloc_for_files(str_files, path, modifiers);
    copy_name_in_str(str_files, path, modifiers);
    if (is_in_str('t', modifiers) == 1) {
        sort_time(str_files, len, path);
    }
    if (is_in_str('r', modifiers) == 1) {
        my_str_swap(str_files, len);
    }
    if (is_in_str('l', modifiers) != 1) {
        print_array_str(len, str_files);
    } else {
        print_long_ls(len, str_files, path);
    }
}
