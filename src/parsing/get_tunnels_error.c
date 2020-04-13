/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** get_tunnels_error
*/

#include "lemin.h"
#include "my.h"

static bool check_exist_rooms(char ***array_3d, char **word_array,
int end_rooms)
{
    int foo = 0;

    for (int i = 1; i < end_rooms; i++) {
        if (word_array_len(array_3d[i]) != 3)
            continue;
        if (!my_strcmp(array_3d[i][0], word_array[0]))
            foo++;
        if (!my_strcmp(array_3d[i][0], word_array[1]))
            foo++;
    }
    if (foo == 2)
        return true;
    else
        return false;
}

bool check_error_tunnels(char ***array_3d, char **word_array,
int end_rooms)
{
    if (word_array_len(word_array) != 2)
        return true;
    if (!check_exist_rooms(array_3d, word_array, end_rooms)) {
        return true;
    }
    return false;
}

char ***return_error_tunnels(char ***array_3d, char **word_array)
{
    free_2d_array(word_array);
    return array_3d;
}