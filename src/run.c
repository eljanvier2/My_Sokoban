/*
** EPITECH PROJECT, 2022
** run
** File description:
** run
*/

#include <curses.h>
#include "my.h"

void game_reset(map_t *map)
{
    map->twin_check = 0;
    map->map_tab = map->saved_map;
    p_finder(map);
    refresh();
}

void space_key(int key, map_t *map)
{
    if (key == ' ') {
        game_reset(map);
        start(map);
    }
}

void key_check(int key, map_t *map)
{
    if (key == 27) {
        endwin();
        exit(1);
    }
    if (key == KEY_UP && map->map_tab[map->pos_y - 1][map->pos_x] != '#')
        move_up(map);
    if (key == KEY_DOWN && map->map_tab[map->pos_y + 1][map->pos_x] != '#')
        move_down(map);
    if (key == KEY_LEFT && map->map_tab[map->pos_y][map->pos_x - 1] != '#')
        move_left(map);
    if (key == KEY_RIGHT && map->map_tab[map->pos_y][map->pos_x + 1] != '#')
        move_right(map);
    space_key(key, map);
}

void loop(map_t *map, int key)
{
    int win = 0;

    while (key != 'q' && win != 1 && map->loser_ind != 1) {
        print_map(map);
        if ((key = getch()) == -1)
            exit(84);
        key_check(key, map);
        win = win_test(map);
        refresh();
        x_locked_loop(map);
    }
    print_map(map);
    refresh();
    endgame(win);
}

void start(map_t *map)
{
    int key = 0;

    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    intrflush(stdscr, FALSE);
    loop(map, key);
    endwin();
    exit(0);
}
