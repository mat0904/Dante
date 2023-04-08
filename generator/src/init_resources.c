/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** init_resources
*/

#include "../include/prototype.h"

static int parse_args(const int ac, const char **av, maze_t *maze)
{
    if ((maze->size = malloc(sizeof(vector_t))) == NULL)
        return 84;
    maze->size->x = atoi(av[1]);
    maze->size->y = atoi(av[2]);
    if ((maze->size->x <= 0) || (maze->size->y <= 0))
        return 84;
    return 0;
}

static int create_line(node_t **line, int y, int len)
{
    int x = 0;
    while (x < len) {
        line[x] = malloc(sizeof(node_t));
        line[x]->value = 0;
        line[x]->status = CELL;
        line[x]->position = (vector_t){x, y};
        x += 1;
    }
    line[x] = NULL;
    return 0;
}

static int alloc_maze(maze_t *maze)
{
    if ((maze->maze = malloc(sizeof(node_t **) * (maze->size->y + 1))) == NULL)
        return 84;
    int y = 0;
    while (y < maze->size->y) {
        maze->maze[y] = malloc(sizeof(node_t *) * (maze->size->x + 1));
        create_line(maze->maze[y], y, maze->size->x);
        y += 1;
    }
    maze->maze[y] = NULL;
    return 0;
}

maze_t *init_resources(const int ac, const char **av)
{
    if (args_error_handling(ac, av) == 84)
        return NULL;
    maze_t *maze;
    if ((maze = malloc(sizeof(maze_t))) == NULL)
        return NULL;
    if (parse_args(ac, av, maze) == 84)
        return NULL;
    if (alloc_maze(maze) == 84)
        return NULL;
    return maze;
}
