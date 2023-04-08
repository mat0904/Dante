/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** free_resources.c
*/

#include "../../include/prototype.h"

int free_astar(gps_t *gps, lists_t *lists)
{
    free(lists->open);
    free(lists->closed);
    free(lists);
    free(gps);
    return 0;
}

int free_array(char **array)
{
    int i = 0;
    while (array[i] != NULL) {
        free(array[i]);
        i += 1;
    }
    free(array);
    return 0;
}

static int free_node(node_t ***node)
{
    int i = 0;
    while (node[i] != NULL) {
        int j = 0;
        while (node[i][j] != NULL) {
            free(node[i][j]);
            j += 1;
        }
        free(node[i]);
        i += 1;
    }
    free(node);
    return 0;
}

int free_resources(app_t *app)
{
    free_node(app->node_array);
    free(app);
    return 0;
}
