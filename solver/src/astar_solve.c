/*
** EPITECH PROJECT, 2023
** git
** File description:
** astar_solve
*/

#include "../include/prototype.h"

vector_t find_end(app_t *app)
{
    vector_t end = {0, 0};
    while (app->node_array[end.y] != NULL) {
        end.y++;
    }
    while (app->node_array[0][end.x] != NULL) {
        end.x++;
    }
    return end;
}

void init_origin(node_t *current, vector_t end)
{
    current->g_cost = 0;
    current->h_cost = manhattan_dist(current->pos, end);
    current->f_cost = current->g_cost + current->h_cost;
}

void astar_solve(app_t *app)
{
    gps_t *gps = init_gps(app);
    init_origin(gps->current, gps->end->pos);
    lists_t *lists = init_list(app);
    algorithm(app, lists, gps);
    free_astar(gps, lists);
}
