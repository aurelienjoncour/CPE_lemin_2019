/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** lemin_t
*/

#ifndef LEMIN_T_H_
#define LEMIN_T_H_

typedef struct lemin_s {
    int nb_of_ants;
    int nb_rooms;
    struct room_s *room_start;
    struct room_s *room_end;
}lemin_t;

#endif /* !LEMIN_T_H_ */
