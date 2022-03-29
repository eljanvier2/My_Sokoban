/*
** EPITECH PROJECT, 2022
** print
** File description:
** print
*/

#include "my.h"

void print_map(map_t *map)
{
    clear();
    for (int i = 0; map->map_tab[i] != NULL; i++)
        mvprintw(i, 0, map->map_tab[i]);
}
