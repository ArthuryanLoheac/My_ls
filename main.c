/*
** EPITECH PROJECT, 2023
** Main setting up
** File description:
** main setting up
*/
#include "my.h"
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

static int get_nb_path(int argc, char **argv)
{
    int nb = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            nb++;
        }
    }
    return nb;
}

static void call_my_ls_for_each(char **argv, int argc, char *modifiers)
{
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            my_ls_with_path(argv[i], modifiers);
            break;
        }
    }
}

static void switch_nb_paths(int nb_paths, char *modifiers,
    int argc, char **argv)
{
    switch (nb_paths) {
    case 0:
        my_ls_with_path(".", modifiers);
        break;
    case 1:
        call_my_ls_for_each(argv, argc, modifiers);
        break;
    default:
        my_ls_multiple_path(argc, argv, modifiers);
        break;
    }
}

static void check_every_files(int argc, char **argv)
{
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-' && opendir(argv[i]) == 0) {
            exit(84);
        }
    }
}

int main(int argc, char **argv)
{
    char *modifiers = stock_modifiers(argc, argv);
    int nb_paths = get_nb_path(argc, argv);

    if (my_ls_d(modifiers, argv, argc, nb_paths) == 1) {
        return 0;
    }
    check_every_files(argc, argv);
    switch_nb_paths(nb_paths, modifiers, argc, argv);
    return 0;
}
