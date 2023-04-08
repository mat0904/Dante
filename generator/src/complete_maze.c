/*
** EPITECH PROJECT, 2023
** dante
** File description:
** complete_maze.c
*/

#include "../include/prototype.h"

static int complete_line(node_t **line)
{
    int i = 0;
    while (line[i] != NULL) {
        if (line[i]->status == DOOR) {
            line[i]->status = CELL;
        }
        i += 1;
    }
    return 0;
}

int complete_maze(maze_t *maze)
{
    int i = 0;
    while (maze->maze[i] != NULL) {
        complete_line(maze->maze[i]);
        i += 1;
    }
    return 0;
}
