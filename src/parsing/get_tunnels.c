/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** get_tunnels
*/

#include "my.h"
#include "lemin.h"

static int init_parse(char ***array_3d, char *line, size_t *index)
{
    *index = len_3d_array(array_3d);
    if (!my_strlen(line))
        return EXIT_FAILURE;
    del_comments_commands(line);
    return EXIT_SUCCESS;
}

static char ***fill_array_3d(size_t index, char **word_array, char ***array_3d)
{
    array_3d[index] = word_array;
    array_3d = realloc_3d_array(array_3d);
    return array_3d;
}

char ***get_tunnels(FILE *stream, char ***array_3d, char *line)
{
    char **word_array = NULL;
    size_t len = 0;
    size_t index = 0;
    int end_rooms = len_3d_array(array_3d);

    for (ssize_t nread = 0; nread != -1;) {
        if (init_parse(array_3d, line, &index))
            return array_3d;
        if (!my_strlen(line)) {
            nread = getline(&line, &len, stream);
            continue;
        }
        word_array = my_str_to_word_array(line, "-\n");
        if (check_error_tunnels(array_3d, word_array, end_rooms))
            return return_error_tunnels(array_3d, word_array);
        array_3d = fill_array_3d(index, word_array, array_3d);
        nread = getline(&line, &len, stream);
    }
    free(line);
    return array_3d;
}