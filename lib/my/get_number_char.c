/*
** EPITECH PROJECT, 2023
** get_number_char
** File description:
** get_number_char
*/

int get_number_char(unsigned int nb)
{
    int len = 0;
    int len_temp = 0;

    for (int i = 1000000000; i > 0; i /= 10) {
        if (nb / i != 0) {
            len_temp = i;
            break;
        }
    }
    while (len_temp > 0) {
        len_temp = len_temp / 10;
        len++;
    }
    return len;
}
