/*
** EPITECH PROJECT, 2023
** my_ls_d
** File description:
** my_ls_d
*/
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

static void print_not_parameters(int argc, char **argv, int i, int rev)
{
    struct stat buf;
    int pos_last_arg;

    pos_last_arg = find_last_arg(argc, argv, 0);
    if (rev == 1) {
        pos_last_arg = find_last_arg(argc, argv, 1);
    }
    if (argv[i][0] != '-' && stat(argv[i], &buf) != -1) {
        mini_printf("%s", argv[i]);
        if (i != pos_last_arg) {
            mini_printf("  ");
        }
    }
    buf = buf;
}

static int check_parameters(int argc, char **argv)
{
    struct stat buf;

    for (int i = 0; i < argc; i++) {
        if (argv[i][0] != '-' && stat(argv[i], &buf) == -1) {
            write(2, "my_ls: cannot access '", 23);
            write(2, argv[i], my_strlen(argv[i]));
            write(2, "': No such file or directory\n", 30);
            return -1;
        }
    }
    return 0;
}

static void print_if_no_modifier(char *str)
{
    if (str[0] != '-') {
        print_datas(str, "\0");
    }
}

static void ld_good_order(char *modifiers, char **argv, int argc)
{
    if (is_in_str('r', modifiers) == 1) {
        for (int i = argc -1; i >= 1; i--) {
            print_if_no_modifier(argv[i]);
        }
    } else {
        for (int i = 1; i < argc; i++) {
            print_if_no_modifier(argv[i]);
        }
    }
}

int my_ls_dl(char *modifiers, char **argv, int argc, int nb_paths)
{
    if (is_in_str('d', modifiers) == 1 && is_in_str('l', modifiers) == 1 ) {
        if (nb_paths == 0) {
            print_datas(".", "\0");
        }
        ld_good_order(modifiers, argv, argc);
        return 1;
    }
    return 0;
}

static void print_good_order(int argc, char **argv, char *modifiers)
{
    if (is_in_str('r', modifiers) == 1) {
        for (int i = argc - 1; i >= 1; i--) {
            print_not_parameters(argc, argv, i, 1);
        }
    } else {
        for (int i = 1; i < argc; i++) {
            print_not_parameters(argc, argv, i, 0);
        }
    }
}

int my_ls_d(char *modifiers, char **argv, int argc, int nb_paths)
{
    if (check_parameters(argc, argv) == -1) {
        return 84;
    }
    if (is_in_str('d', modifiers) == 1 && is_in_str('l', modifiers) != 1 ) {
        if (nb_paths == 0) {
            mini_printf(".");
        }
        print_good_order(argc, argv, modifiers);
        mini_printf("\n");
        return 1;
    }
    return my_ls_dl(modifiers, argv, argc, nb_paths);
}
