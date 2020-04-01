/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** get_script
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "lemin.h"

void del_comments_commands(char *line)
{
    for (size_t i = 0; line[i] != '\0'; i++) {
        if (line[i] == '#') {
            line[i] = '\0';
            return;
        }
    }
}

char ***get_script(FILE *stream)
{
    char ***array_3d = malloc(sizeof(char **) * 2);
    char *line = NULL;

    if (array_3d == NULL)
        return NULL;
    array_3d[0] = get_nb_ants(stream, line);
    array_3d[1] = NULL;
    if (array_3d[0] == NULL) {
        free(line);
        return array_3d;
    }
    array_3d = get_rooms(stream, array_3d, &line);
    if (line == NULL) {
        free(line);
        return array_3d;
    } else {
        array_3d = get_tunnels(stream, array_3d, line);
    }
    return array_3d;
}