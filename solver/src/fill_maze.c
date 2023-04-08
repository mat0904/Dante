/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** fill_maze
*/

#include "../include/prototype.h"

void fill_maze(app_t *app, node_t *end)
{
    if (!end->from) {
        printf("no solution found");
        app->display_maze = 0;
        return;
    }
    app->display_maze = 1;
    while (end->from != NULL) {
        end->value = 'o';
        end->from->value = 'o';
        end = end->from;
    }
}
