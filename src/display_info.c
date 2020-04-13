/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** display_info
*/

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

static int check_end_start(char ***array, size_t index)
{
    int start = 0;
    int end = 0;

    for (size_t i = 0; i < index; i++) {
        if (!my_strcmp(array[i][0], "##start"))
            start++;
        if (!my_strcmp(array[i][0], "##end"))
            end++;
    }
    if (start != 1 || end != 1)
        return 84;
    else
        return 0;
}

static int display_tunnels(char ***array, size_t index)
{
    if (check_end_start(array, index) == 84)
        return 84;
    for (size_t i = index; array[i] != NULL; i++) {
        if (array[i][0] == NULL || array[i][1] == NULL)
            return 84;
        if (i == index)
            my_putstr("#tunnels\n");
        my_putstr(array[i][0]);
        my_putstr("-");
        my_putstr(array[i][1]);
        my_putstr("\n");
    }
    return EXIT_SUCCESS;
}

int display_info(char ***array)
{
    size_t index = 0;

    if (array[0] == NULL || array[0][0] == NULL)
        return 84;
    display_nb_ants(array[0][0]);
    if (array[1] == NULL)
        return 84;
    index = display_rooms(array);
    if (array[index] == NULL)
        return 84;
    return display_tunnels(array, index);
}
