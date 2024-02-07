/*
** EPITECH PROJECT, 2023
** check_null
** File description:
** check_null
*/
#include <stdlib.h>
#include <stddef.h>


void check_null(void *a)
{
    if (a == NULL) {
        exit(84);
    }
}
