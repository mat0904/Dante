/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** free_resources
*/

#include "../include/prototype.h"

int free_resources(maze_t *maze)
{
    int i = 0;
    while (maze->maze[i] != NULL) {
        int j = 0;
        while (maze->maze[i][j] != NULL) {
            free(maze->maze[i][j]);
            j += 1;
        }
        free(maze->maze[i]);
        i += 1;
    }
    free(maze->maze);
    free(maze->size);
    free(maze);
    return 0;
}
