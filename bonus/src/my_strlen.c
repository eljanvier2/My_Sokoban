/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** task 03
*/

#include <limits.h>
#include <unistd.h>
#include "my.h"

int mystrlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_strlen2(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\n') {
        i++;
    }
    return (i);
}
