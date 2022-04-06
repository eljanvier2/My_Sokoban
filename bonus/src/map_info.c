/*
** EPITECH PROJECT, 2022
** map info
** File description:
** functions getting infos on used map
*/

#include "my.h"

void get_cols(map_t *map)
{
    int cols = 0;

    while (map->map_buf[cols] != '\n')
        cols++;
    map->cols = cols;
}

void get_rows(map_t *map)
{
    int rows = 0;

    for (int i = 0; map->map_buf[i] != '\0'; i++) {
        if (map->map_buf[i] == '\n')
            rows++;
    }
    rows++;
    map->rows = rows;
}

void get_mapsize(map_t *map)
{
    get_cols(map);
    get_rows(map);
}

int check_map_valid(map_t *map)
{
    for (int cols = 0; cols < map->cols; cols++) {
        if (map->map_tab[0][cols] != '#'
            || map->map_tab[map->rows - 1][cols] != '#')
            return 1;
    }
    for (int rows = 0; rows < map->rows; rows++) {
        if (map->map_tab[rows][0] != '#'
            || map->map_tab[rows][map->cols - 1] != '#')
            return 1;
    }
    return 0;
}
