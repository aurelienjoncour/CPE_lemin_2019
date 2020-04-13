/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** display_result
*/

#include "lemin.h"
#include "my.h"

void print_movement(ant_t *ant, char *next_room_label)
{
    my_putchar('P');
    my_put_nbr(ant->nb);
    my_putchar('-');
    my_putstr(next_room_label);
}

void display_result(bool first, int i, ant_t *ants, lemin_t *lemin)
{
    if (first == false) {
        print_movement(&ants[i - 1], ants[i - 1].current_room->label);
        my_putchar(' ');
    }
    if (i == lemin->nb_of_ants - 1)
        print_movement(&ants[i], ants[i].current_room->label);
}