/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** generator
*/

#include "../include/prototype.h"

static int launch_algo(maze_t *maze)
{
    if (maze->size->x <= 2 || maze->size->y <= 2)
        return 0;
    switch (maze->perfect) {
        case 0:
            recursive_division(maze, (vector_t){0, 0},
                    (vector_t){maze->size->x - 1, maze->size->y - 1}, 0);
            complete_maze(maze);
            break;
        case 1:
            kruskal(maze);
        default:
            break;
    }
    return 0;
}

static int detect_is_perfect(const int ac, const char **av, maze_t *maze)
{
    if (ac == 4 && strcmp(av[3], "perfect") == 0)
        maze->perfect = 1;
    else
        maze->perfect = 0;
    return 0;
}

int generator(const int ac, const char **av)
{
    maze_t *maze;
    if ((maze = init_resources(ac, av)) == NULL)
        return 84;
    detect_is_perfect(ac, av, maze);
    launch_algo(maze);
    display_maze(maze);
    free_resources(maze);
    return 0;
}
