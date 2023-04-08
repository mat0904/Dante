/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** file_info.c
*/

#include "../include/prototype.h"

int get_line_nb(const char *pathfile)
{
    size_t len;
    char *buffer = NULL;
    FILE *file = fopen(pathfile, "r");
    int size = 0;
    while (getline(&buffer, &len, file) != -1) {
        size += 1;
    }
    free(buffer);
    fclose(file);
    return size;
}

int get_filesize(const char *pathfile)
{
    int size = 0;
    int fd = open(pathfile, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 257);
    int read_size = 0;
    while ((read_size = read(fd, buffer, 256)) != 0) {
        size += read_size;
    }
    free(buffer);
    close(fd);
    return size;
}
