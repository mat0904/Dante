/*
** EPITECH PROJECT, 2023
** CPE
** File description:
** finish_maze.c
*/

#include "../../../include/prototype.h"

int finish_maze(maze_t *maze)
{
    int x = maze->size->x - 1;
    int y = maze->size->y - 1;
    if (maze->size->x % 2 == 0 && maze->size->y % 2 == 0) {
        maze->maze[y][x - 1]->status = CELL;
        maze->maze[y][x]->status = CELL;
        return 0;
    }
    if (maze->size->x % 2 == 0) {
        maze->maze[y][x]->status = CELL;
    }
    if (maze->size->y % 2 == 0) {
        maze->maze[y][x]->status = CELL;
    }
    return 0;
}
