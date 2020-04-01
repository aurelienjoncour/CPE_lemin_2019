/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** del_char
*/

#include <stdlib.h>
#include "my.h"

void del_char(char *str, char del)
{
    size_t i = 0;

    for (; *str == del; str++);
    if (!my_strlen(str))
        return;
    for (i = my_strlen(str) - 1; str[i] == del; i--)
        str[i] = '\0';
}