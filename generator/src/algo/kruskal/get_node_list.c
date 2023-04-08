/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** get_node_list.c
*/

#include "../../../include/prototype.h"

int len_list(node_t **node)
{
    int i = 0;
    while (node[i] != NULL) {
        i += 1;
    }
    return i;
}

int shift_list(node_t **node, int index)
{
    int i = index;
    while (node[i] != NULL) {
        node[i] = node[i + 1];
        i += 1;
    }
    return 0;
}

static int get_line_node(maze_t *maze, node_t **node, int *i, int y)
{
    int x = 0;
    int len_x = (maze->size->x % 2 == 0) ? maze->size->x - 1 : maze->size->x;
    while (x < len_x) {
        if (maze->maze[y][x]->status == V_EDGE ||
            maze->maze[y][x]->status == H_EDGE) {
            node[*i] = maze->maze[y][x];
            *i += 1;
        }
        x += 1;
    }
    return 0;
}

node_t **get_node(maze_t *maze)
{
    int i = 0;
    int y = 0;
    int size = maze->size->x * maze->size->y;
    node_t **node = malloc(sizeof(node_t *) * (size));
    int len_y = (maze->size->y % 2 == 0) ? maze->size->y - 1 : maze->size->y;
    while (y < len_y) {
        get_line_node(maze, node, &i, y);
        y += 1;
    }
    node[i] = NULL;
    return node;
}
