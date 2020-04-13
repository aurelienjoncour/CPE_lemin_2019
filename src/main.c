/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main
*/

#include "lemin.h"
#include "my.h"

/*
Function de test de parcours du graph
void print_link(room_t *link)
{
    if (link != NULL) {
        printf("%s\n", link->label);
    }
}

void display_room(room_t *room)
{
    print_link(room);
    room->visited = true;
    for (size_t i = 0; room->next[i] != NULL; i++) {
        if (room->next[i] != NULL && !room->next[i]->visited) {
            display_room(room->next[i]);
        }
    }
}*/

static void pathfinding(room_t **rooms_array, lemin_t *lemin)
{
    ant_t *ants = malloc(sizeof(ant_t) * lemin->nb_of_ants);

    for (int i = 0; i < lemin->nb_of_ants; i++) {
        ants[i].nb = i + 1;
        ants[i].current_room = lemin->room_start;
    }
    compute_end_distance(rooms_array, lemin);
    my_putstr("#moves\n");
    move_ants(lemin, ants);
}

int main(void)
{
    char ***array_3d = get_script(stdin);
    room_t **rooms_array = NULL;
    lemin_t *lemin = NULL;

    if (array_3d == NULL)
        return 84;
    if (display_info(array_3d) == 84) {
        free_3d_array(array_3d);
        return 84;
    }
    rooms_array = create_rooms(array_3d);
    lemin = get_lemin_info(array_3d, rooms_array);
    free_3d_array(array_3d);
    if (rooms_array == NULL || lemin == NULL)
        return 84;
//    if (!check_end(lemin, rooms_array))
//        return 84;
    pathfinding(rooms_array, lemin);
    return EXIT_SUCCESS;
}
