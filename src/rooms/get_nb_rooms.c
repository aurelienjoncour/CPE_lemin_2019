/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** GEt nb of rooms
*/

#include "lemin.h"

size_t get_nb_rooms(char ***array3d)
{
    size_t nb_rooms = 0;

    for (size_t i = 0; array3d[i]; i++) {
        if (word_array_len(array3d[i]) == 3)
            nb_rooms++;
    }
    return nb_rooms;
}
