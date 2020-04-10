/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main
*/

#include "lemin.h"
#include "my.h"

int main(void)
{
    char ***array_3d = get_script(stdin);
    room_t **rooms_array = create_rooms(array_3d);
    lemin_t *lemin = get_lemin_info(array_3d, rooms_array);
    int ret = 0;

    if (array_3d == NULL || rooms_array == NULL || lemin == NULL)
        return 84;
    ret = display_info(array_3d);
    free_3d_array(array_3d);
    return ret;
}
