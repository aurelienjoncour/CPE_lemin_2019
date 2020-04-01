/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** get_tunnels
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "my.h"
#include "lemin.h"

static bool check_exist_rooms(char ***array_3d, char **word_array, int end_rooms)
{
    int foo = 0;

    for (int i = 1; i < end_rooms; i++) {
        if (word_array_len(array_3d[i]) != 3)
            continue;
        if (!my_strcmp(array_3d[i][0], word_array[0]))
            foo++;
        if (!my_strcmp(array_3d[i][0], word_array[1]))
            foo++;
    }
    if (foo == 2)
        return true;
    else
        return false;
}

static bool check_error_tunnels(char ***array_3d, char **word_array, int end_rooms)
{
    if (word_array_len(word_array) != 2)
        return true;
    if (!check_exist_rooms(array_3d, word_array, end_rooms)) {
        return true;
    }
    return false;
}

static char ***return_error_tunnels(char ***array_3d, char **word_array)
{
    free_2d_array(word_array);
    return array_3d;
}

static int init_parse(char ***array_3d, char *line, size_t *index)
{
    *index = len_3d_array(array_3d);
    if (!my_strlen(line))
        return EXIT_FAILURE;
    del_comments_commands(line);
    return EXIT_SUCCESS;
}

char ***get_tunnels(FILE *stream, char ***array_3d, char *line)
{
    char **word_array = NULL;
    size_t len = 0;
    ssize_t nread = 0;
    size_t index = 0;
    int end_rooms = len_3d_array(array_3d);

    while (nread != -1) {
        if (init_parse(array_3d, line, &index))
            return array_3d;
        if (!my_strlen(line))
            continue;
        word_array = my_str_to_word_array(line, "-\n");
        if (check_error_tunnels(array_3d, word_array, end_rooms))
            return return_error_tunnels(array_3d, word_array);
        array_3d[index] = word_array;
        array_3d = realloc_3d_array(array_3d);
        nread = getline(&line, &len, stream);
    }
    free(line);
    return array_3d;
}