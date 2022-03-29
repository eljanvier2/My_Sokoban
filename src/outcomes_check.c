/*
** EPITECH PROJECT, 2022
** outcomes check
** File description:
** outcomes check
*/

#include "my.h"

int vertical_outcomes_left(map_t *map, int j)
{
    for (int i = map->pos_y; map->map_tab[i][j - 1] != '#'; i++) {
        if (map->map_tab[i][j - 1] == 'O')
            return 0;
    }
    for (int i = map->pos_y; map->map_tab[i][j - 1] != '#'; i--) {
        if (map->map_tab[i][j - 1] == 'O')
            return 0;
    }
    if (map->saved_map[map->pos_y][map->pos_x - 1] != 'O')
        map->loser_ind = 1;
    return 1;
}

int vertical_outcomes_right(map_t *map, int j)
{
    for (int i = map->pos_y; map->map_tab[i][j + 1] != '#'; i++) {
        if (map->map_tab[i][j + 1] == 'O')
            return 0;
    }
    for (int i = map->pos_y; map->map_tab[i][j + 1] != '#'; i--) {
        if (map->map_tab[i][j + 1] == 'O')
            return 0;
    }
    if (map->saved_map[map->pos_y][map->pos_x + 1] != 'O')
        map->loser_ind = 1;
    return 1;
}

int horizontal_outcomes_up(map_t *map, int i)
{
    for (int j = map->pos_x; map->map_tab[i - 1][j] != '#'; j++) {
        if (map->map_tab[i - 1][j] == 'O')
            return 0;
    }
    for (int j = map->pos_x; map->map_tab[i - 1][j] != '#'; j--) {
        if (map->map_tab[i - 1][j] == 'O')
            return 0;
    }
    if (map->saved_map[map->pos_y - 1][map->pos_x] != 'O')
        map->loser_ind = 1;
    return 1;
}

int horizontal_outcomes_down(map_t *map, int i)
{
    for (int j = map->pos_x; map->map_tab[i + 1][j] != '#'; j++) {
        if (map->map_tab[i + 1][j] == 'O')
            return 0;
    }
    for (int j = map->pos_x; map->map_tab[i + 1][j] != '#'; j--) {
        if (map->map_tab[i + 1][j] == 'O')
            return 0;
    }
    if (map->saved_map[map->pos_y + 1][map->pos_x] != 'O')
        map->loser_ind = 1;
    return 1;
}
