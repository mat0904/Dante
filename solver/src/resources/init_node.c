/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** cost_init
*/

#include "../../include/prototype.h"

void node_init(app_t *app, gps_t *gps)
{
    vector_t pos;
    for (int i = 0; app->node_array[i] != NULL; i++) {
        for (int j = 0; app->node_array[i][j] != NULL; j++) {
            pos.y = i;
            pos.x = j;
            app->node_array[i][j]->pos.y = i;
            app->node_array[i][j]->pos.x = j;
            app->node_array[i][j]->g_cost = 0;
            app->node_array[i][j]->h_cost = manhattan_dist(pos, gps->end->pos);
            app->node_array[i][j]->f_cost = app->node_array[i][j]->g_cost +
                app->node_array[i][j]->h_cost;
            app->node_array[i][j]->from = NULL;
        }

    }
}
