/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** lemin
*/

#ifndef LEMIN_H_
#define LEMIN_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "vector2i_t.h"
#include "room_t.h"
#include "lemin_t.h"
#include "ant_t.h"

//chained_list
room_t *create_room(char **script);
int connect_rooms(room_t *link1, room_t *link2);
room_t **realloc_room_t_array(room_t **array_src, size_t size);

//parsing
char **get_nb_ants(FILE *stream, char *line);
char ***get_rooms(FILE *stream, char ***array_3d, char **line);
char ***get_tunnels(FILE *stream, char ***array_3d, char *line);
int del_comments(char *line);
char ***get_script(FILE *stream);
bool check_error_line(ssize_t nread, char **line);
bool check_error_rooms(char **word_array, char ***array_3d);
char ***return_error_tunnels(char ***array_3d, char **word_array);
bool check_error_tunnels(char ***array_3d, char **word_array,
int end_rooms);
bool check_end(lemin_t *lemin, room_t **room_array);

//commands
int interprate_commands(const char *line);
bool command_already_exist(char ***array, int index);
void del_comments_commands(char *line);

//lemin
lemin_t *get_lemin_info(char ***array_3d, room_t **rooms_array);
int display_info(char ***array);

//word_array
void free_2d_array(char **array);
int word_array_len(char **array);
char **word_array_dup(char **env);
char **word_array_realloc(char **env);

//3d_word_array
char ***realloc_3d_array(char ***array_3d);
void free_3d_array(char ***array);
size_t len_3d_array(char ***array);

//tools
bool allow_char(const char *script, const char *allow_char);

//rooms
room_t **create_rooms(char ***array3d);
size_t get_nb_rooms(char ***array3d);

//resolve
void compute_end_distance(room_t **rooms_array, lemin_t *lemin);
void move_ants(lemin_t *lemin, ant_t *ants);

#endif /* !LEMIN_H_ */
