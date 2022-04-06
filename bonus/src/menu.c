/*
** EPITECH PROJECT, 2022
** menu
** File description:
** start menu for sokoban
*/

#include "my.h"

void menu_exit_states(menu_t *menu)
{
    if (menu->arrow_pos == 0)
        menu->menu_state = 1;
    if (menu->arrow_pos == 3)
        menu->menu_state = -1;
}

int menu_key_check(int key, menu_t *menu, char **menu_tab)
{
    if (key == 27) {
        endwin();
        exit(1);
    }
    if (key == KEY_DOWN && menu->arrow_pos < 2)
        menu_down(menu->menu, menu);
    if (key == KEY_UP && menu->arrow_pos > 0)
        menu_up(menu_tab, menu);
    if (key == '\n')
        menu_exit_states(menu);
    if (key == 'q') {
        endwin();
        exit(1);
    }
    return 0;
}

void menu(int key)
{
    menu_t *menu;

    if (!(menu = malloc(sizeof(menu_t)))) {
        endwin();
        exit(84);
    }
    menu_init(menu);
    while (key != 'q' && menu->menu_state != 1) {
        clear();
        for (int i = 0; i < 4; i++)
            mvprintw(i, 0, menu->menu[i]);
        if ((key = getch()) == -1)
            exit(84);
        menu_key_check(key, menu, menu->menu);
        refresh();
        if (menu->menu_state == -1) {
            endwin();
            exit(1);
        }
    }
}
