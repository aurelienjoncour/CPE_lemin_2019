/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** connect_rooms
*/

#include "lemin.h"

static int connect_next(room_t *link1, room_t *link2)
{
    size_t i = 0;

    if (link1->next == NULL) {
        link1->next = malloc(sizeof(room_t *) * 2);
        if (link1->next == NULL)
            return EXIT_FAILURE;
        link1->next[0] = link2;
        link1->next[1] = NULL;
    } else {
        for (i = 0; link1->next[i] != NULL; i++);
        link1->next = realloc_room_t_array(link1->next, i + 2);
        if (link1->next == NULL)
            return EXIT_FAILURE;
        link1->next[i] = link2;
        link1->next[i + 1] = NULL;
    }
    return EXIT_SUCCESS;
}

int connect_rooms(room_t *link1, room_t *link2)
{
    if (connect_next(link1, link2) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (connect_next(link2, link1) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
