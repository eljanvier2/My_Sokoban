/*
** EPITECH PROJECT, 2022
** locked checking
** File description:
** checks if one box is locked
*/

#include "my.h"

void locked_check(map_t *map, int i, int j)
{
    if (map->map_tab[i + 1][j] == '#' || map->map_tab[i - 1][j] == '#') {
        if (map->map_tab[i][j + 1] == '#' || map->map_tab[i][j - 1] == '#') {
            map->loser_ind = 1;
        }
    }
}

void x_check(map_t *map, int i, int j)
{
    if (map->map_tab[i][j] == 'X' && map->saved_map[i][j] != 'O') {
        locked_check(map, i, j);
    }
}

void x_locked_loop(map_t *map)
{
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->cols; j++)
            x_check(map, i, j);
    }
}
