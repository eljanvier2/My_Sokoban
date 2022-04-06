/*
** EPITECH PROJECT, 2022
** char finders
** File description:
** function finding specific characters in a map
*/

#include "my.h"

int char_finder(map_t *map)
{
    int i = 0;
    int p_status = 0;

    while (map->map_tab[i] != NULL) {
        for (int j = 0; map->map_tab[i][j] != '\0'; j++) {
            p_status = p_check(map, i, j);
            target_count(map, i, j);
        }
        i++;
    }
    if (map->targets->o_cont > map->targets->x_cont)
        p_status = -1;
    return p_status;
}

void target_count(map_t *map, int i, int j)
{
    if (map->map_tab[i][j] == 'O')
        map->targets->o_cont++;
    if (map->map_tab[i][j] == 'X')
        map->targets->x_cont++;
}

int p_check(map_t *map, int i, int j)
{
    if (map->map_tab[i][j] == 'P') {
        if (map->twin_check == 1)
            return 84;
        map->pos_x = j;
        map->pos_y = i;
        map->twin_check = 1;
    }
    return 0;
}
