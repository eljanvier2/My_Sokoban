/*
** EPITECH PROJECT, 2022
** moving checks
** File description:
** checks ran when moving to manage every special case
*/

#include "my.h"

void lat_move_check1(map_t *map, int i)
{
    if (map->saved_map[map->pos_y][map->pos_x] == 'O')
        map->map_tab[map->pos_y][map->pos_x] = 'O';
    else
        map->map_tab[map->pos_y][map->pos_x] = ' ';
    map->map_tab[map->pos_y][map->pos_x + i] = 'P';
    map->map_tab[map->pos_y][map->pos_x + (2 * i)] = 'X';
    map->pos_x += i;
    map->moves++;
}

void lat_move_check2(map_t *map, int i)
{
    if (map->saved_map[map->pos_y][map->pos_x] == 'O')
        map->map_tab[map->pos_y][map->pos_x] = 'O';
    else
        map->map_tab[map->pos_y][map->pos_x] = ' ';
    map->map_tab[map->pos_y][map->pos_x + i] = 'P';
    map->pos_x += i;
    map->moves++;
}

void vert_move_check1(map_t *map, int i)
{
    if (map->saved_map[map->pos_y][map->pos_x] == 'O')
        map->map_tab[map->pos_y][map->pos_x] = 'O';
    else
        map->map_tab[map->pos_y][map->pos_x] = ' ';
    map->map_tab[map->pos_y + i][map->pos_x] = 'P';
    map->map_tab[map->pos_y + (2 * i)][map->pos_x] = 'X';
    map->pos_y += i;
    map->moves++;
}

void vert_move_check2(map_t *map, int i)
{
    if (map->saved_map[map->pos_y][map->pos_x] == 'O')
        map->map_tab[map->pos_y][map->pos_x] = 'O';
    else
        map->map_tab[map->pos_y][map->pos_x] = ' ';
    map->map_tab[map->pos_y + i][map->pos_x] = 'P';
    map->pos_y += i;
    map->moves++;
}
