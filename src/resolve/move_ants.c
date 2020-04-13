/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** Move the ants
*/

#include "lemin.h"
#include "my.h"

static int move_ant_in_room(lemin_t *lemin, ant_t *ant, int next_room_nb)
{
    if (ant->current_room->next[next_room_nb] != lemin->room_end)
        ant->current_room->next[next_room_nb]->ants = 1;
    ant->current_room->ants = 0;
    ant->current_room = ant->current_room->next[next_room_nb];
    return EXIT_SUCCESS;
}

static int move_ant(lemin_t *lemin, ant_t *ant)
{
    int distance = 1000000;
    int next_room_nb = -1;
    room_t *room = NULL;

    for (int i = 0; ant->current_room->next[i]; i++) {
        room = ant->current_room->next[i];
        if (ant->current_room->next[i] == lemin->room_end) {
            next_room_nb = i;
            break;
        }
        if (room->distance + room->ants < distance ||
        (room->distance + room->ants == distance && room->ants == 0)) {
            next_room_nb = i;
            distance = room->distance + room->ants;
        }
    }
    if (ant->current_room->next[next_room_nb]->ants == 0)
        return move_ant_in_room(lemin, ant, next_room_nb);
    return EXIT_FAILURE;
}



void move_ants(lemin_t *lemin, ant_t *ants)
{
    size_t ants_moved = 0;
    int return_value = 0;
    bool first = true;

    for (int i = 0; i < lemin->nb_of_ants; i++) {
        if (ants[i].current_room == lemin->room_end)
            continue;
        ants_moved++;
        return_value = move_ant(lemin, &ants[i]);
        if (return_value == EXIT_FAILURE) {
            print_movement(&ants[i - 1], ants[i - 1].current_room->label);
            break;
        }
        display_result(first, i, ants, lemin);
        first = false;
    }
    if (ants_moved != 0) {
        my_putchar('\n');
        move_ants(lemin, ants);
    }
}
