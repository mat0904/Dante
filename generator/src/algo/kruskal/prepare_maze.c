/*
** EPITECH PROJECT, 2023
** dante
** File description:
** complete_maze.c
*/

#include "../../../include/prototype.h"

static int create_cell(maze_t *maze, int x, int y, int *i)
{
    if (y % 2 != 0) {
        if (x % 2 == 0)
            maze->maze[y][x]->status = V_EDGE;
        else
            maze->maze[y][x]->status = WALL;
        maze->maze[y][x]->value = -1;
        return 0;
    }
    if (x % 2 == 0) {
        maze->maze[y][x]->status = CELL;
        maze->maze[y][x]->value = *i;
        *i += 1;
    } else {
        maze->maze[y][x]->status = H_EDGE;
        maze->maze[y][x]->value = -1;
    }
}

static int prepare_column_maze(maze_t *maze, int x, int *i)
{
    int y = 0;
    while (maze->maze[y] != NULL) {
        create_cell(maze, x, y, i);
        y += 1;
    }
    return 0;
}

int prepare_maze(maze_t *maze)
{
    int x = 0;
    int i = 0;
    while (maze->maze[0][x] != NULL) {
        prepare_column_maze(maze, x, &i);
        x += 1;
    }
    return 0;
}
