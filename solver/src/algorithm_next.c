/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** algorithm_next
*/

#include "../include/prototype.h"

int is_in_list(vector_t vector, app_t *app, node_t **list)
{
    for (int i = 0; list[i] != NULL; i++) {
        if (app->node_array[vector.y][vector.x] == list[i])
            return 1;
    }
    return 0;
}

int is_traversable(vector_t neighb, vector_t end, app_t *app)
{
    if (neighb.x < 0 || neighb.y < 0)
        return 0;
    if (neighb.x > end.x || neighb.y > end.y)
        return 0;
    if (app->node_array[neighb.y][neighb.x] == NULL)
        return 0;
    if (app->node_array[neighb.y][neighb.x]->value != '*')
        return 0;
    return 1;
}

int compute_neighb(node_t *current, lists_t *lists, vector_t neighb, app_t *app)
{
    if (is_in_list(neighb, app, lists->closed) == 1)
        return 1;
    return 0;
}

void add_neighb(vector_t neighb, app_t *app, lists_t *lists)
{
    if (is_in_list(neighb, app, lists->open) == 0) {
        add_node(lists->open, app->node_array[neighb.y][neighb.x]);
    }
}

void algo_next(vector_t *neighb, lists_t *lists, app_t *app, gps_t *gps)
{
    for (int i = 0; i < 4; i++) {
        if (is_traversable(neighb[i], gps->end->pos, app) == 1) {
            app->node_array[neighb[i].y][neighb[i].x]->g_cost =
                gps->current->g_cost + 1;
        } else {
            continue;
        }
        if (compute_neighb(gps->current, lists, neighb[i], app) == 1)
            continue;
        if (gps->current->g_cost < app->node_array[neighb[i].y][neighb[i].x]
                ->g_cost || is_in_list(neighb[i], app, lists->open) == 0) {
            app->node_array[neighb[i].y][neighb[i].x]->f_cost = app->
                node_array[neighb[i].y][neighb[i].x]->g_cost + app->node_array
                [neighb[i].y][neighb[i].x]->h_cost;
            app->node_array[neighb[i].y][neighb[i].x]->from = gps->current;
            add_neighb(neighb[i], app, lists);
        }
    }
}
