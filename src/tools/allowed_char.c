/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** allowed_char
*/

#include <stdbool.h>
#include "my.h"

bool allow_char(const char *script, const char *allow_char)
{
    int len_script = my_strlen(script);
    int len_allow = my_strlen(allow_char);
    int cnt = 0;

    for (int i = 0; i  < len_script; i++) {
        cnt = 0;
        for (int j = 0; j < len_allow; j++) {
            if (script[i] == allow_char[j])
                cnt++;
        }
        if (cnt != 1)
            return false;
    }
    return true;
}