/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** check_error_rooms
*/

#include "lemin.h"
#include "my.h"

bool check_error_line(ssize_t nread, char **line)
{
    if (nread == -1)
        return true;
    if ((*line)[nread - 1] == '\n')
        (*line)[nread - 1] = '\0';
    if (!my_strlen(*line))
        return true;
    del_comments(*line);
    return false;
}

bool check_error_rooms(char **word_array, char ***array_3d)
{
    char *nb = "0123456789";

    if (!allow_char(word_array[1], nb) || !allow_char(word_array[2], nb))
        return true;
    for (size_t i = 1; array_3d[i] != NULL; i++) {
        if (word_array_len(array_3d[i]) != 3)
            continue;
        if (!my_strcmp(word_array[0], array_3d[i][0]))
            return true;
        if (!my_strcmp(word_array[1], array_3d[i][1]) &&
            !my_strcmp(word_array[2], array_3d[i][2]))
            return true;
    }
    return false;
}