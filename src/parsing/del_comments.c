/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** del_comments
*/

#include "lemin.h"

int del_comments(char *line)
{
    size_t i;

    if (line[0] == '#' && line[1] == '#') {
        return 0;
    }
    for (i = 0; line[i] != '\0'; i++)
        if (line[i] == '#' && line[i + 1] != '#') {
            line[i] = '\0';
            return 1;
        }
    return 0;
}