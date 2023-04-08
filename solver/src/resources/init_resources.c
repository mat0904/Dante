/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** init_resources.c
*/

#include "../../include/prototype.h"

lists_t *init_list(app_t *app)
{
    vector_t end = find_end(app);
    lists_t *lists = malloc(sizeof(lists_t));
    lists->open = malloc(sizeof(node_t *) * (end.y * end.x + 1));
    lists->closed = malloc(sizeof(node_t *) * (end.y * end.x + 1));
    lists->open[0] = app->node_array[0][0];
    lists->open[1] = NULL;
    lists->open[0]->pos.y = 0;
    lists->open[0]->pos.x = 0;
    lists->closed[0] = NULL;
    lists->open[0]->from = NULL;
    return lists;
}

gps_t *init_gps(app_t *app)
{
    gps_t *gps = malloc(sizeof(gps_t));
    gps->origin = app->node_array[0][0];
    gps->origin->pos.x = 0;
    gps->origin->pos.y = 0;
    gps->origin->from = NULL;
    gps->current = app->node_array[0][0];
    vector_t end = find_end(app);
    gps->end = app->node_array[end.y - 1][end.x - 1];
    gps->end->pos = end;
    return gps;
}

app_t *init_resources(void)
{
    app_t *app = malloc(sizeof(app_t));
    if (app == NULL)
        return NULL;
    return app;
}
