/*
** EPITECH PROJECT, 2023
** my_header
** File description:
** Write your my.h header
*/

#ifndef MY_H_
    #define MY_H_

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>

int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
void my_putchar(char c);
int mini_printf(const char *format, ...);
char *stock_modifiers(int argc, char **argv);
char *my_strcat(char *dest, char const *src);
int is_in_str(char c, char *str);
void my_ls_with_path(char *path, char *modifiers);
char *my_strcpy(char *dest, char const *src);
char *my_strlowcase(char *str);
void my_ls_multiple_path(int argc, char **argv, char *modifiers);
void sort_array_str(char **str_files, int len);
int my_ls_d(char *modifiers, char **argv, int argc, int nb_paths);
int find_last_arg(int argc, char **argv, int j);
void print_long_ls(int len, char **str_files, char *path);
int get_number_char(unsigned int nb);
void print_type_normal(mode_t mode);
void print_datas(char *path, char *path_start);
char *total_path(char *path, char *path_start);
void check_null(void *a);
void sort_time(char **str_files, int len, char *path);
void my_str_swap(char **str, int len);

#endif /* MY_H_ */
