/*
** EPITECH PROJECT, 2023
** git
** File description:
** algorithm
*/

#include "../include/prototype.h"

node_t *find_lowest_cost(node_t **open, gps_t *gps)
{
    int lowest = open[0]->f_cost;
    for (int i = 1; open[i] != NULL; i++) {
        if (open[i]->f_cost < lowest) {
            lowest = open[i]->f_cost;
        }
    }
    for (int i = 0; open[i] != NULL; i++) {
        if (open[i]->f_cost == lowest) {
            return open[i];
        }
    }
}

vector_t *neighbours(node_t *current)
{
    vector_t *neighb = malloc(sizeof(vector_t) * 4);
    neighb[0].x = current->pos.x - 1;
    neighb[0].y = current->pos.y;
    neighb[1].x = current->pos.x + 1;
    neighb[1].y = current->pos.y;
    neighb[2].x = current->pos.x;
    neighb[2].y = current->pos.y - 1;
    neighb[3].x = current->pos.x;
    neighb[3].y = current->pos.y + 1;
    return neighb;
}

int is_empty(node_t **list)
{
    if (list[0] == NULL)
        return 1;
    return 0;
}

void algorithm(app_t *app, lists_t *lists, gps_t *gps)
{
    vector_t *neighb;
    node_init(app, gps);
    while (is_empty(lists->open) == 0) {
        if (gps->current == app->node_array[gps->end->pos.y][gps->end->pos.x]) {
            break;
        }
        gps->current = find_lowest_cost(lists->open, gps);
        rm_node(lists->open, gps->current);
        add_node(lists->closed, gps->current);
        neighb = neighbours(gps->current);
        algo_next(neighb, lists, app, gps);
        free(neighb);
    }
    fill_maze(app, app->node_array[gps->end->pos.y][gps->end->pos.x]);
}
