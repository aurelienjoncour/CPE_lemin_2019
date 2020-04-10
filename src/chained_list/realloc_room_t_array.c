/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** realloc_room_t_array
*/

#include <stdlib.h>
#include "lemin.h"

int realloc_room_t_array(room_t **array_src, size_t size)
{
    room_t **array = malloc(sizeof(room_t *) * size);
    size_t i = 0;

    if (array == NULL)
        return EXIT_FAILURE;
    for (i = 0; array_src[i] != NULL; i++)
        array[i] = array_src[i];
    for (; i < size; i++)
        array[i] = NULL;
    free(array_src);
    array_src = array;
    return EXIT_SUCCESS;
}
