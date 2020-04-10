/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** Create rooms array
*/

#include "lemin.h"
#include "my.h"

static int create_all_the_room(char ***array3d, room_t **rooms_array)
{
    size_t pos = 0;

    for (size_t i = 0; array3d[i]; i++) {
        if (word_array_len(array3d[i]) == 3) {
            rooms_array[pos] = create_room(array3d[i]);
            if (rooms_array[pos] == NULL)
                return 84;
            pos++;
        }
    }
    return EXIT_SUCCESS;
}

static room_t *get_room(char *room_name,
room_t **rooms_array, size_t nb_rooms)
{
    for (size_t j = 0; j < nb_rooms; j++) {
        if (my_strcmp(room_name, rooms_array[j]->label) == 0) {
            return rooms_array[j];
        }
    }
    return NULL;
}

static int is_already_connected(room_t *room1, room_t *room2)
{
    if (room1->next == NULL)
        return -1;
    for (int i = 0; room1->next[i]; i++) {
        if (my_strcmp(room1->next[i]->label, room2->label) == 0)
            return 1;
    }
    if (room1->previous == NULL)
        return -1;
    for (int i = 0; room1->previous[i]; i++) {
        if (my_strcmp(room1->previous[i]->label, room2->label) == 0)
            return 1;
    }
    return -1;
}

static room_t  **connect_all_the_room(char ***array3d,
room_t **rooms_array, size_t nb_rooms)
{
    room_t *room1 = NULL;
    room_t *room2 = NULL;
    int return_value = 0;

    for (size_t i = 0; array3d[i]; i++) {
        if (word_array_len(array3d[i]) == 2) {
            room1 = get_room(array3d[i][0], rooms_array, nb_rooms);
            room2 = get_room(array3d[i][1], rooms_array, nb_rooms);
            if (is_already_connected(room1, room2) == -1)
                return_value = connect_rooms(room1, room2);
            if (return_value == EXIT_FAILURE)
                return NULL;
        }
    }
    return rooms_array;
}

room_t **create_rooms(char ***array3d)
{
    size_t nb_rooms = get_nb_rooms(array3d);
    room_t **rooms_array = malloc(sizeof(room_t) * nb_rooms);

    if (create_all_the_room(array3d, rooms_array) == 84)
        return NULL;
    rooms_array = connect_all_the_room(array3d, rooms_array, nb_rooms);
    return rooms_array;
}
