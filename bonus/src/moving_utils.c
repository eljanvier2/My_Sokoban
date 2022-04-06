/*
** EPITECH PROJECT, 2022
** moving utils
** File description:
** functions moving the player
*/

#include "my.h"

void move_up(map_t *map)
{
    if (map->map_tab[map->pos_y - 1][map->pos_x] == 'X'
        && map->map_tab[map->pos_y - 2][map->pos_x] != '#'
        && map->map_tab[map->pos_y - 2][map->pos_x] != 'X') {
        vert_move_check1(map, (-1));
    } else if (map->map_tab[map->pos_y - 1][map->pos_x] != 'X') {
        vert_move_check2(map, (-1));
    }
}

void move_down(map_t *map)
{
    if (map->map_tab[map->pos_y + 1][map->pos_x] == 'X'
        && map->map_tab[map->pos_y + 2][map->pos_x] != '#'
        && map->map_tab[map->pos_y + 2][map->pos_x] != 'X') {
        vert_move_check1(map, 1);
    } else if (map->map_tab[map->pos_y + 1][map->pos_x] != 'X') {
        vert_move_check2(map, 1);
    }
}

void move_left(map_t *map)
{
    if (map->map_tab[map->pos_y][map->pos_x - 1] == 'X'
        && map->map_tab[map->pos_y][map->pos_x - 2] != '#'
        && map->map_tab[map->pos_y][map->pos_x - 2] != 'X') {
        lat_move_check1(map, (-1));
    } else if (map->map_tab[map->pos_y][map->pos_x - 1] != 'X') {
        lat_move_check2(map, (-1));
    }
}

void move_right(map_t *map)
{
    if (map->map_tab[map->pos_y][map->pos_x + 1] == 'X'
        && map->map_tab[map->pos_y][map->pos_x + 2] != '#'
        && map->map_tab[map->pos_y][map->pos_x + 2] != 'X') {
        lat_move_check1(map, 1);
    } else if (map->map_tab[map->pos_y][map->pos_x + 1] != 'X') {
        lat_move_check2(map, 1);
    }
}
