/*
** EPITECH PROJECT, 2022
** win utils
** File description:
** win utils
*/

#include "my.h"

void win_screen(map_t *map)
{
    clear();
    mvprintw(0, 0, "YOU WIN !\nYou made %d moves", map->moves);
    refresh();
    usleep(1000000);
}

void loser_screen(void)
{
    clear();
    mvprintw(0, 0, "YOU LOOSE...\nTry again !");
    refresh();
    usleep(1000000);
}

int win_check(map_t *map, int rows, int cols, int i)
{
    if (map->map_tab[rows][cols] == 'X' && map->saved_map[rows][cols] == 'O') {
        i++;
    }
    return i;
}

int win_test(map_t *map)
{
    int rows = 0;
    int i = 0;

    for (rows = 0; rows < map->rows; rows++) {
        for (int cols = 0; cols < map->cols; cols++) {
            i = win_check(map, rows, cols, i);
        }
    }
    if (i == map->targets->o_cont)
        return 1;
    return 0;
}

void endgame(int win)
{
    refresh();
    usleep(100000);
    endwin();
    if (win == 1)
        exit(0);
    exit(1);
}
