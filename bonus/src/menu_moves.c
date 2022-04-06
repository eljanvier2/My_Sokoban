/*
** EPITECH PROJECT, 2022
** menu moves
** File description:
** moving inside main menu
*/

#include "my.h"

void menu_up(char **tab, menu_t *menu)
{
    menu->menu[menu->arrow_pos][mystrlen(tab[menu->arrow_pos]) - 1] = ' ';
    menu->menu[menu->arrow_pos - 1][mystrlen(tab[menu->arrow_pos - 1])] = '<';
    menu->arrow_pos--;
}

void menu_down(char **tab, menu_t *menu)
{
    menu->menu[menu->arrow_pos][mystrlen(tab[menu->arrow_pos]) - 1] = ' ';
    menu->menu[menu->arrow_pos + 1][mystrlen(tab[menu->arrow_pos + 1])] = '<';
    menu->arrow_pos++;
}
