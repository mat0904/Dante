/*
** EPITECH PROJECT, 2023
** git
** File description:
** manhattan
*/

#include "../include/prototype.h"

int manhattan_dist(vector_t a_node, vector_t b_node)
{
    int dist = (b_node.x - a_node.x) + (b_node.y - a_node.y);
    return dist;
}
