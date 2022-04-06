/*
** EPITECH PROJECT, 2022
** headers
** File description:
** headers
*/

#ifndef MY_H_
    #define MY_H_

#include <curses.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "map_struct.h"

int my_putstr(char const *str);
int my_putsterr(char const *str);
map_t *map_init(char *path, int size);
char *fs_cat_line(char const *filepath, int size, char *buffer);
void get_rows(map_t *map);
void get_cols(map_t *map);
void get_mapsize(map_t *map);
int map_check(char c);
void move_up(map_t *map);
void move_down(map_t *map);
void move_left(map_t *map);
void move_right(map_t *map);
int char_finder(map_t *map);
int p_check(map_t *map, int i, int j);
void target_count(map_t *map, int i, int j);
void lat_move_check1(map_t *map, int i);
void lat_move_check2(map_t *map, int i);
void vert_move_check1(map_t *map, int i);
void vert_move_check2(map_t *map, int i);
int win_test(map_t *map);
void win_screen(map_t *map);
void start(map_t *map);
void x_locked_loop(map_t *map);
void endgame(map_t *map, int test);
int check_map_valid(map_t *map);
void menu(int key);
int mystrlen(char const *str);
void menu_up(char **tab, menu_t *menu);
void menu_down(char **tab, menu_t *menu);
void menu_init(menu_t* menu);

#endif
