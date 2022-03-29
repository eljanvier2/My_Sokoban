/*
** EPITECH PROJECT, 2022
** usage
** File description:
** usage
*/

#include "my.h"

void usage_print(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tMap file representing the warehouse map,");
    my_putstr(" containing '#' for walls,\n\t\t'P' for the player,");
    my_putstr(" 'X' for the boxes and 'O' for storage locations.\n");
}

void usage(int argc, char const *argv[])
{
    if (!argv)
        exit(84);
    for (int i = 0; i < argc; i++) {
        if (my_strcmp(argv[i], "-h") == 0) {
            usage_print();
            exit(0);
        }
    }
}
