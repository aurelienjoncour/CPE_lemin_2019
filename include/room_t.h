/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** room_t
*/

#ifndef ROOM_T_H_
#define ROOM_T_H_

typedef struct room_s {
    char *label;
    vector2i_t pos;
    int ants;
    int distance;
    bool visited;
    struct room_s **next;
}room_t;

#endif /* !ROOM_T_H_ */
