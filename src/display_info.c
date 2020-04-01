/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** display_info
*/

#include <stdlib.h>
#include "my.h"
#include "lemin.h"

static void display_nb_ants(char *nb)
{
    my_putstr("#number_of_ants\n");
    my_putstr(nb);
    my_putstr("\n");
}

static int display_rooms(char ***array)
{
    my_putstr("#rooms\n");
    for (size_t i = 1; array[i] != NULL; i++) {
        if (word_array_len(array[i]) == 2)
            return i;
        my_putstr(array[i][0]);
        for (size_t j = 1; array[i][j] != NULL; j++) {
            my_putstr(" ");
            my_putstr(array[i][j]);
        }
        my_putstr("\n");
    }
    return 0;
}

static void display_tunnels(char ***array, size_t index)
{
    my_putstr("#tunnels\n");
    for (size_t i = index; array[i] != NULL; i++) {
        my_putstr(array[i][0]);
        my_putstr("-");
        my_putstr(array[i][1]);
        my_putstr("\n");
    }
}

int display_info(char ***array)
{
    size_t index = 0;

    display_nb_ants(array[0][0]);
    if (array[1] == NULL)
        return EXIT_FAILURE;
    index = display_rooms(array);
    display_tunnels(array, index);
    return EXIT_SUCCESS;
}