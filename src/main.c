/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"


int main(void)
{
    char ***array_3d = get_script(stdin);

    if (array_3d == NULL)
        return 84;
    display_info(array_3d);
    free_3d_array(array_3d);
    return EXIT_SUCCESS;
}
