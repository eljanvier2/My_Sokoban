/*
** EPITECH PROJECT, 2022
** error handling
** File description:
** error handling
*/

int map_check(char c)
{
    switch (c) {
        case '#': return 0;
        break;
        case 'O': return 0;
        break;
        case 'P': return 0;
        break;
        case 'X': return 0;
        break;
        case '\n': return 0;
        break;
        case ' ': return 0;
        break;
        default: return 84;
        break;
    }
}
