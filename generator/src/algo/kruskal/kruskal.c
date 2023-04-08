/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** recursive_backtracking
*/

#include "../../../include/prototype.h"

/*
** 0 - UP
** 1 - DOWN
** 2 - LEFT
** 3 - RIGHT
*/

int propagate_value(maze_t *maze, vector_t position, vector_t origin,
    int value)
{
    int x = position.x;
    int y = position.y;
    if (x < 0 || x >= maze->size->x)
        return 0;
    if (y < 0 || y >= maze->size->y)
        return 0;
    if (maze->maze[y][x]->status != CELL)
        return 0;
    maze->maze[y][x]->value = value;
    if (x + 1 != origin.x)
        propagate_value(maze, (vector_t){x + 1, y}, position, value);
    if (x - 1 != origin.x)
        propagate_value(maze, (vector_t){x - 1, y}, position, value);
    if (y + 1 != origin.y)
        propagate_value(maze, (vector_t){x, y + 1}, position, value);
    if (y - 1 != origin.y)
        propagate_value(maze, (vector_t){x, y - 1}, position, value);
    return 0;
}

static int is_in_corner(maze_t *maze, vector_t position)
{
    if (position.x == 0 && position.y == 0)
        return 1;
    if (position.x == 0 && position.y == maze->size->y - 1)
        return 1;
    if (position.x == maze->size->x - 1 && position.y == 0)
        return 1;
    if (position.x == maze->size->x - 1 && position.y == maze->size->y - 1)
        return 1;
    return 0;
}

static int create_connection(maze_t *maze, node_t **node, node_t *tmp_node)
{
    int x = tmp_node->position.x;
    int y = tmp_node->position.y;

    if (tmp_node->status == V_EDGE)
        return create_vert(maze, tmp_node);
    if (tmp_node->status == H_EDGE)
        return create_hori(maze, tmp_node);
}

static int iteral_kruskal(maze_t *maze, node_t **node)
{
    int i = 0;
    while (len_list(node) > 1) {
        int index = generate_random(0, len_list(node) - 1);
        node_t *tmp_node = node[index];
        if (create_connection(maze, node, tmp_node) == 1)
            shift_list(node, index);
        i += 1;
    }
    return 0;
}

int kruskal(maze_t *maze)
{
    prepare_maze(maze);
    node_t **node = get_node(maze);
    iteral_kruskal(maze, node);
    free(node);
    finish_maze(maze);
    return 0;
}
