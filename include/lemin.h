/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** lemin
*/

#ifndef LEMIN_H_
#define LEMIN_H_

#include <stdio.h>
#include <stdbool.h>
#include "vector2i_t.h"
#include "room_t.h"
#include "lemin_t.h"

//chained_list
room_t *create_room(char **script);
int connect_links(room_t *link1, room_t *link2);
int realloc_room_t_array(room_t **array_src, size_t size);

#endif /* !LEMIN_H_ */
