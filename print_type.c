/*
** EPITECH PROJECT, 2023
** print_type
** File description:
** print_type
*/
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

static void print_type_exotic(mode_t mode)
{
    switch (mode & __S_IFMT) {
    case __S_IFCHR:
    mini_printf("c");
    break;
    case __S_IFSOCK:
    mini_printf("s");
    break;
    case __S_IFIFO:
    mini_printf("p");
    break;
    default:
    mini_printf("?");
    break;
    }
}

void print_type_normal(mode_t mode)
{
    switch (mode & __S_IFMT) {
    case __S_IFBLK:
    mini_printf("b");
    break;
    case __S_IFDIR:
    mini_printf("d");
    break;
    case __S_IFLNK:
    mini_printf("l");
    break;
    case __S_IFREG:
    mini_printf("-");
    break;
    default:
    print_type_exotic(mode);
    break;
    }
}
