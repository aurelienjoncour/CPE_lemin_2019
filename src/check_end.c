/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** check_end
*/

#include "lemin.h"

static int explore_graph(room_t *room, room_t *room_end)
{
    room->visited = true;
    for (size_t i = 0; room->next[i] != NULL; i++) {
        if (room->next[i] != NULL && !room->next[i]->visited) {
            if (room->next[i] == room_end) {
                return EXIT_SUCCESS;
            }
            return explore_graph(room->next[i], room_end);
        }
    }
    return EXIT_FAILURE;
}

bool check_end(lemin_t *lemin, room_t **room_array)
{
    if (explore_graph(lemin->room_start, lemin->room_end) == EXIT_FAILURE)
        return false;
    for (int i = 0; i < lemin->nb_rooms; i++)
        room_array[i]->visited = false;
    return true;
}