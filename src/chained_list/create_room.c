/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** create_room
*/

#include "my.h"
#include "lemin.h"

room_t *create_room(char **script)
{
    room_t *room = malloc(sizeof(room_t));

    if (room == NULL)
        return NULL;
    room->label = my_strdup(script[0]);
    room->pos.x = my_getnbr(script[1]);
    room->pos.y = my_getnbr(script[2]);
    room->next = NULL;
    room->previous = NULL;
    return room;
}