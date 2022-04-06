/*
** EPITECH PROJECT, 2022
** map init
** File description:
** functions initializing the displayed map using a map file
*/

#include "my.h"

int map_final_loops(map_t *map, int j, int k, int buf_ind)
{
    int error = 0;

    for (k = 0; k <= map->rows; k++) {
        for (j = 0;
            map->map_buf[buf_ind] != '\n' && map->map_buf[buf_ind] != '\0';
            j++) {
            map->map_tab[k][j] = map->map_buf[buf_ind];
            map->saved_map[k][j] = map->map_buf[buf_ind];
            error += map_check(map->map_buf[buf_ind]);
            buf_ind++;
        }
        map->map_tab[k][j] = '\0';
        map->saved_map[k][j] = '\0';
        j = 0;
        buf_ind++;
    }
    map->map_tab[k] = NULL;
    map->saved_map[k] = NULL;
    return error;
}

int map_final(map_t *map)
{
    int j = 0;
    int k = 0;
    int buf_ind = 0;
    int error = 0;

    error = map_final_loops(map, j, k, buf_ind) + check_map_valid(map);
    return error;
}

void basic_map_init(map_t *map)
{
    if (!(map->targets = malloc(sizeof(targets_t))))
        exit(84);
    map->targets->o_cont = 0;
    map->targets->x_cont = 0;
    map->cols = 0;
    map->rows = 0;
    map->pos_x = 0;
    map->pos_y = 0;
    map->twin_check = 0;
    map->loser_ind = 0;
    map->moves = 0;
}

void looped_malloc(map_t *map, int i)
{
    if (!(map->map_tab[i] = malloc(sizeof(char) * (map->cols + 1))))
        exit(84);
    if (!(map->saved_map[i] = malloc(sizeof(char) * (map->cols + 1))))
        exit(84);
}

map_t *map_init(char *path, int size)
{
    map_t *map;

    map = malloc(sizeof(map_t));
    basic_map_init(map);
    map->map_path = path;
    if (!(map->map_buf = malloc(sizeof(char) * size)))
        exit(84);
    if (!(map->map_buf = fs_cat_line(map->map_path, size, map->map_buf)))
        exit(84);
    get_mapsize(map);
    if (!(map->map_tab = malloc(sizeof(char *) * (map->rows))))
        exit(84);
    if (!(map->saved_map = malloc(sizeof(char *) * (map->rows + 1))))
        exit(84);
    for (int i = 0; i < map->cols; i++)
        looped_malloc(map, i);
    if (map_final(map) != 0 || char_finder(map) != 0)
        return NULL;
    return map;
}
