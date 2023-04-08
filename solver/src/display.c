/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** display.c
*/

#include "../include/prototype.h"

static int get_len_array(node_t ***node)
{
    int i = 0;
    while (node[i] != NULL) {
        i += 1;
    }
    return i;
}

static int display_node_array_line(app_t *app, int index)
{
    int i = 0;
    while (app->node_array[index][i] != NULL) {
        char value = app->node_array[index][i]->value;
        printf("%c", value);
        i += 1;
    }
    return 0;
}

int display_node_array(app_t *app)
{
    if (app->display_maze == 0)
        return 0;
    int i = 0;
    int len = get_len_array(app->node_array);
    while (i < len - 1) {
        display_node_array_line(app, i);
        printf("\n");
        i += 1;
    }
    display_node_array_line(app, i);
    return 0;
}
