/*
** EPITECH PROJECT, 2022
** menu init
** File description:
** menu initializing
*/

#include "my.h"

void menu_malloc(menu_t *menu)
{
    if (!(menu->menu = malloc(sizeof(char *) * 4)) ||
    !(menu->menu[0] = malloc(sizeof(char) * 7))) {
        endwin();
        exit(84);
    }
    if (!(menu->menu[1] = malloc(sizeof(char) * 10)) ||
    !(menu->menu[2] = malloc(sizeof(char) * 15))) {
        endwin();
        exit(84);
    }
    if (!(menu->menu[3] = malloc(sizeof(char) * 6))) {
        endwin();
        exit(84);
    }
}

void menu_init(menu_t *menu)
{
    menu->arrow_pos = 0;
    char *start = "start <\0";
    char *controls = "controls  \0";
    char *map_gen = "map generator  \0";
    char *exit_msg = "exit  \0";

    menu_malloc(menu);
    for (int i = 0; start[i] != '\0'; i++)
        menu->menu[0][i] = start[i];
    for (int i = 0; controls[i] != '\0'; i++)
        menu->menu[1][i] = controls[i];
    for (int i = 0; map_gen[i] != '\0'; i++)
        menu->menu[2][i] = map_gen[i];
    for (int i = 0; exit_msg[i] != '\0'; i++)
        menu->menu[3][i] = exit_msg[i];
    if (!menu->menu)
        exit(84);
}
