/*
** EPITECH PROJECT, 2022
** map structure
** File description:
** map structure
*/

#ifndef MAP_H_
    #define MAP_H_

typedef struct targets_s {
    int o_cont;
    int x_cont;
} targets_t;

typedef struct menu_s {
    int arrow_pos;
    int start_lenght;
    int controls_lenght;
    int exit_lenght;
    int menu_state;
    char **menu;
} menu_t;

typedef struct map_s {
    int cols;
    int rows;
    char **saved_map;
    char const *map_path;
    char *map_buf;
    char **map_tab;
    int pos_x;
    int pos_y;
    int twin_check;
    int loser_ind;
    int moves;
    targets_t *targets;
} map_t;

#endif
