/*
** EPITECH PROJECT, 2023
** print_datas
** File description:
** print_datas
*/
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>

static void print_rights(mode_t mode)
{
    mode_t arr_mode[9] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP,
    S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH};
    char str[9] = "rwxrwxrwx";

    for (int i = 0; i < 9; i++) {
        if ((mode & arr_mode[i]) == arr_mode[i]) {
            mini_printf("%c", str[i]);
        } else {
            mini_printf("-");
        }
    }
    mini_printf(".");
}

static void print_name(uid_t id, gid_t gid)
{
    struct passwd *pws;
    struct group *pwg;

    pws = getpwuid(id);
    mini_printf(" %s", pws->pw_name);
    pwg = getgrgid(gid);
    mini_printf(" %s", pwg->gr_name);
}

void remove_backslash_n(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i - 8] = '\0';
            return;
        }
        i++;
    }
}

void print_datas(char *path, char *path_start)
{
    struct stat buf;
    char *date;
    char *long_path;
    char buffer[30001];

    long_path = total_path(path, path_start);
    stat(long_path, &buf);
    print_type_normal(buf.st_mode);
    print_rights(buf.st_mode);
    mini_printf(" %d", buf.st_nlink);
    print_name(buf.st_uid, buf.st_gid);
    mini_printf(" %d", buf.st_size);
    date = ctime(&buf.st_mtime) + 4;
    remove_backslash_n(date);
    mini_printf(" %s", (date));
    mini_printf(" %s", path);
    if (readlink(long_path, buffer, 30000) != -1) {
        mini_printf(" -> %s", buffer);
    }
    mini_printf("\n");
}
