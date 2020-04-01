/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** get_rooms
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "lemin.h"

static char ***end_error(char ***array_3d, char **line)
{
    free(*line);
    *line = NULL;
    return array_3d;
}

static int parse_rooms(char **line, char ***array_3d, size_t index)
{
    char **word_array = my_str_to_word_array(*line, " ");

    if (word_array == NULL)
        return EXIT_FAILURE;
    if (word_array_len(word_array) != 3) {
        free_2d_array(word_array);
        return EXIT_FAILURE;
    }
    if (check_error_rooms(word_array, array_3d)) {
        free_2d_array(word_array);
        free(*line);
        *line = NULL;
        return EXIT_FAILURE;
    }
    array_3d[index] = word_array;
    return EXIT_SUCCESS;
}

static char ***init_array(char ***array_3d, size_t *index, ssize_t *nread, char **line)
{
    size_t len = 0;

    array_3d = realloc_3d_array(array_3d);
    *index = len_3d_array(array_3d);
    if (*line != NULL)
        free(*line);
    *nread = getline(line, &len, stdin);
    return array_3d;
}

char ***get_rooms(FILE *stream, char ***array_3d, char **line)
{
    ssize_t nread = 0;
    int commands = 0;

    for (size_t index = len_3d_array(array_3d); nread != -1;) {
        array_3d = init_array(array_3d, &index, &nread, line);
        if (check_error_line(nread, line))
            return end_error(array_3d, line);
        commands = interprate_commands(*line);
        if (!my_strlen(*line) || commands == -1) {
            continue;
        } else if (commands > -1) {
            if (command_already_exist(array_3d, commands))
                return end_error(array_3d, line);
            array_3d[index] = my_str_to_word_array(*line, "");
            continue;
        }
        if (parse_rooms(line, array_3d, index))
            return array_3d;
    }
    return array_3d;
}