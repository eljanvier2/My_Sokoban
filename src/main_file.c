/*
** EPITECH PROJECT, 2022
** main file
** File description:
** main sokoban file
*/

#include "my.h"

int main(int argc, char const *argv[])
{
    struct stat my_stat;
    map_t *map;

    if (argc < 2) {
        my_putsterr("Not enough arguments\n");
        return 84;
    }
    usage(argc, argv);
    stat(argv[1], &my_stat);
    if ((map = map_init(argv[1], my_stat.st_mode)) == NULL) {
        my_putsterr("Invalid map given\n");
        return 84;
    }
    start(map);
    return 0;
}
