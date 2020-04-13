/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** Compute end distance
*/

#include "lemin.h"
#include "my.h"

static void set_distance(room_t **rooms_array, lemin_t *lemin,
size_t nb_rooms)
{
    for (size_t i = 0; i < nb_rooms; i++) {
        if (rooms_array[i] != lemin->room_end)
            rooms_array[i]->distance = 1000000;
        else
            rooms_array[i]->distance = 0;
    }
}

static void get_distance_for_next(room_t *room)
{
    if (room->next == NULL) {
        room->visited = true;
        return;
    }
    for (size_t i = 0; room->next[i]; i++) {
        if (room->next[i]->visited == true)
            continue;
        if (room->distance + 1 < room->next[i]->distance)
            room->next[i]->distance = room->distance + 1;
    }
    room->visited = true;

}

static void get_all_distance(room_t **rooms_array, size_t nb_rooms,
size_t room_check)
{
    int smaller_distance = -1;
    int room_nb = -1;

    for (size_t i = 0; i < nb_rooms; i++) {
        if (rooms_array[i]->visited == true)
            continue;
        if (rooms_array[i]->distance < smaller_distance ||
        smaller_distance == -1) {
            room_nb = i;
            smaller_distance = rooms_array[i]->distance;
        }
    }
    if (room_nb != -1) {
        get_distance_for_next(rooms_array[room_nb]);
        get_all_distance(rooms_array, nb_rooms, room_check + 1);
    }
}

void compute_end_distance(room_t **rooms_array, lemin_t *lemin)
{
    for (size_t i = 0; i < lemin->nb_rooms; i++)
        rooms_array[i]->visited = false;
    set_distance(rooms_array, lemin, lemin->nb_rooms);
    get_all_distance(rooms_array, lemin->nb_rooms, 0);
}
