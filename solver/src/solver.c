/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** solver.c
*/

#include "../include/prototype.h"

int solver(const int ac, const char **av)
{
    if (ac != 2)
        return 84;
    app_t *app = init_resources();
    if (app == NULL)
        return 84;
    app->node_array = read_map(av[1]);
    if (app->node_array == NULL)
        return 84;
    astar_solve(app);
    display_node_array(app);
    free_resources(app);
    return 0;
}
