/*
** EPITECH PROJECT, 2023
** find_last_arg
** File description:
** find_last_arg
*/
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int find_last_arg(int argc, char **argv, int j)
{
    struct stat buf;

    for (int i = argc - 1 - j; i > 0; i--) {
        if (argv[i][0] != '-' && stat(argv[i], &buf) != -1) {
            return i;
        }
    }
    return -1;
}
