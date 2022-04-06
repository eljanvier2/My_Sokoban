/*
** EPITECH PROJECT, 2022
** initialization tests
** File description:
** initialization tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_std(void);

Test(map_init, map_init, .init = redirect_all_std)
{
    map_t *map;

    map = malloc(sizeof(map_t));
    basic_map_init(map);
    my_put_nbr(map->pos_x);
    cr_assert_stdout_eq_str("0");
}