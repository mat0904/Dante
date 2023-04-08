/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** create_connection.c
*/

#include "../../../include/prototype.h"

int propagate_value(maze_t *maze, vector_t position, vector_t origin,
    int value);

int create_hori(maze_t *maze, node_t *tmp_node)
{
    int x = tmp_node->position.x;
    int y = tmp_node->position.y;
    if (maze->maze[y][x - 1]->value != maze->maze[y][x + 1]->value) {
        tmp_node->status = CELL;
        propagate_value(maze, (vector_t){x, y}, (vector_t){x + 1, y},
            maze->maze[y][x + 1]->value);
    }
    return 1;
}

int create_vert(maze_t *maze, node_t *tmp_node)
{
    int x = tmp_node->position.x;
    int y = tmp_node->position.y;
    if (maze->maze[y - 1][x]->value != maze->maze[y + 1][x]->value) {
        tmp_node->status = CELL;
        propagate_value(maze, (vector_t){x, y}, (vector_t){x, y + 1},
            maze->maze[y + 1][x]->value);
    }
    return 1;
}
