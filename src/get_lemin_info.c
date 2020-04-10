/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** Get lemin info
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

static room_t *find_room(char *room_name, room_t **rooms_array, size_t nb_rooms)
{
    for (size_t i = 0; i < nb_rooms; i++) {
        if (my_strcmp(room_name, rooms_array[i]->label) == 0)
            return rooms_array[i];
    }
    return NULL;
}

lemin_t *get_lemin_info(char ***array_3d, room_t **rooms_array)
{
    lemin_t *lemin = malloc(sizeof(lemin_t));
    size_t nb_rooms = get_nb_rooms(array_3d);

    lemin->nb_of_ants = my_getnbr(array_3d[0][0]);
    lemin->room_start = NULL;
    lemin->room_end = NULL;
    for (int i = 0; array_3d[i + 1]; i++) {
        if (my_strcmp(array_3d[i][0], "##start") == 0)
            lemin->room_start = find_room(array_3d[i + 1][0],
            rooms_array, nb_rooms);
        if (my_strcmp(array_3d[i][0], "##end") == 0)
            lemin->room_end = find_room(array_3d[i + 1][0],
            rooms_array, nb_rooms);
    }
    if (lemin->room_start == NULL || lemin->room_end == NULL)
        return NULL;
    return lemin;
}
