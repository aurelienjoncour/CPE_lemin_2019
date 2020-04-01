/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** 3d_array
*/

#include <stdlib.h>
#include "lemin.h"

size_t len_3d_array(char ***array)
{
    size_t len;

    for (len = 0; array[len] != NULL; len++);
    return len;
}

void free_3d_array(char ***array)
{
    if (array == NULL)
        return;
    for (size_t i = 0; array[i] != NULL; i++)
        free_2d_array(array[i]);
    free(array);
}

char ***realloc_3d_array(char ***array_3d)
{
    char ***dup = NULL;
    size_t size = len_3d_array(array_3d);

    dup = malloc(sizeof(char **) * (size + 2));
    if (dup == NULL)
        return NULL;
    for (size_t i = 0; array_3d[i]; i++) {
        dup[i] = word_array_dup(array_3d[i]);
        if (dup[i] == NULL)
            return NULL;
    }
    dup[size] = NULL;
    dup[size + 1] = NULL;
    free_3d_array(array_3d);
    return dup;
}