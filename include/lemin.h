/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** lemin
*/

#ifndef LEMIN_H_
#define LEMIN_H_

#include <stdio.h>
#include <stdbool.h>
#include "vector2i_t.h"
#include "room_t.h"
#include "lemin_t.h"

//chained_list
room_t *create_room(char **script);
int connect_links(room_t *link1, room_t *link2);
int realloc_room_t_array(room_t **array_src, size_t size);

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
void del_char(char *str, char del);

#endif /* !LEMIN_H_ */
