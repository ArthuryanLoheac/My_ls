/*
** EPITECH PROJECT, 2023
** print_long_ls
** File description:
** print_long_ls
*/
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

static int get_total_bloc(int len, char **str_files, char *path)
{
    struct stat buffer;
    int total = 0;
    char *str;

    for (int i = 0; i < len; i++) {
        str = total_path(str_files[i], path);
        stat(str, &buffer);
        total += buffer.st_blocks / 2;
    }
    return total;
}

void print_long_ls(int len, char **str_files, char *path)
{
    mini_printf("total %d\n", get_total_bloc(len, str_files, path));
    for (int i = 0; i < len; i++) {
        print_datas(str_files[i], path);
    }
}
