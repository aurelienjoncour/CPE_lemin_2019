/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** interprate_commands
*/

#include "lemin.h"
#include "my.h"

static const char *commands[] = {
    "##start",
    "##end",
    NULL,
};

bool command_already_exist(char ***array, int index)
{
    for (size_t i = 0; array[i] != NULL; i++) {
        if (!my_strcmp(commands[index], array[i][0]))
            return true;
    }
    return false;
}

int interprate_commands(const char *line)
{
    if (line[0] != '#' && line[1] != '#')
        return -2;
    for (size_t i = 0; commands[i] != NULL; i++) {
        if (!my_strcmp(line, commands[i])) {
            return i;
        }
    }
    return -1;
}