/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** recursive_backtracking
*/

#include "../../include/prototype.h"

/*
 * help: https://weblog.jamisbuck.org/2015/10/31/mazes-blockwise-geometry.html
 * u for up : 0
 * d for down : 1
 * l for left : 2
 * r for right : 3
*/

static int generate_vertical(maze_t *maze, vector_t start, \
    vector_t end)
{
    int y = start.y;
    int x = generate_random(start.x + 1, end.x - 1);
    while (maze->maze[start.y][x]->status == DOOR ||
        maze->maze[end.y][x]->status == DOOR) {
        x = generate_random(start.x + 1, end.x - 1);
    }
    while (y <= end.y) {
        maze->maze[y][x]->status = WALL;
        y += 1;
    }
    y = generate_random(start.y, end.y);
    maze->maze[y][x]->status = DOOR;
    maze->maze[y][x + 1]->status = DOOR;
    maze->maze[y][x - 1]->status = DOOR;
    return x;
}

static int generate_horizontal(maze_t *maze, vector_t start, \
    vector_t end)
{
    int x = start.x;
    int y = generate_random(start.y + 1, end.y - 1);
    while (maze->maze[y][start.x]->status == DOOR ||
        maze->maze[y][end.x]->status == DOOR) {
        y = generate_random(start.y + 1, end.y - 1);
    }
    while (x <= end.x) {
        maze->maze[y][x]->status = WALL;
        x += 1;
    }
    x = generate_random(start.x, end.x);
    maze->maze[y][x]->status = DOOR;
    maze->maze[y + 1][x]->status = DOOR;
    maze->maze[y - 1][x]->status = DOOR;
    return y;
}

static int generate_wall(maze_t *maze, vector_t start,
    vector_t end, int horizontal)
{
    switch (horizontal) {
        case 1:
            return generate_vertical(maze, start, end);
        case 0:
            return generate_horizontal(maze, start, end);
    }
    return 0;
}

int recursive_division(maze_t *maze, vector_t start, vector_t end, int i)
{
    if ((end.x - start.x) <= 3 || (end.y - start.y) <= 3)
        return 0;
    int horizontal = 0;
    if ((end.x - start.x) == (end.y - start.y))
        horizontal = generate_random(0, 1);
    else
        horizontal = (end.x - start.x) > (end.y - start.y);
    int z = generate_wall(maze, start, end, horizontal);
    if (horizontal) {
        recursive_division(maze, (vector_t) \
            {start.x, start.y}, (vector_t){z - 1, end.y}, i + 1);
        recursive_division(maze, (vector_t) \
            {z + 1, start.y}, (vector_t){end.x, end.y}, i + 1);
    } else {
        recursive_division(maze, (vector_t) \
            {start.x, start.y}, (vector_t){end.x, z - 1}, i + 1);
        recursive_division(maze, (vector_t) \
            {start.x, z + 1}, (vector_t){end.x, end.y}, i + 1);
    }
    return 0;
}
