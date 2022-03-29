/*
** EPITECH PROJECT, 2022
** map reading
** File description:
** functions reading the map file
*/

#include "my.h"

int open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd < 0) {
        my_putsterr("FAILURE\n");
        return 84;
    }
    return fd;
}

void fs_understand_return_of_read(int fd, char *buffer, int size)
{
    read(fd, buffer, size);

    buffer[size - 1] = '\0';
}

char *fs_cat_line(char const *filepath, int size, char *buffer)
{
    int i = 0;
    int fd = open_file(filepath);
    if (fd == 84)
        return NULL;
    fs_understand_return_of_read(fd, buffer, (size));
    char *tmp = buffer;
    for (i = 0; buffer[i] != '\n'; i++)
        tmp += 1;
    tmp++;
    close(fd);
    return buffer;
}
