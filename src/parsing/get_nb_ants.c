/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** get_nb_ants
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "my.h"
#include "lemin.h"

static bool error_first_line(char **word_array)
{
    if (word_array_len(word_array) != 1)
        return true;
    if (!my_strlen(word_array[0]))
        return true;
    if (!allow_char(word_array[0], "0123456789"))
        return true;
    return false;
}

static char **return_null(char **word_array)
{
    free_2d_array(word_array);
    return NULL;
}

char **get_nb_ants(FILE *stream, char *line)
{
    char **word_array = NULL;
    size_t len = 0;
    ssize_t nread = 0;

    while (nread != -1) {
        nread = getline(&line, &len, stream);
        if (nread < 2)
            return NULL;
        del_comments_commands(line);
        if (my_strlen(line))
            break;
    }
    word_array = my_str_to_word_array(line, " \n");
    free(line);
    if (word_array == NULL)
        return NULL;
    if (error_first_line(word_array))
        return return_null(word_array);
    return word_array;
}