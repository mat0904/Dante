/*
** EPITECH PROJECT, 2023
** git
** File description:
** list_mod
*/

#include "../include/prototype.h"

void push_nodes(node_t **list, int i)
{
    int j = i;
    while (list[j] != NULL) {
        list[j] = list[j + 1];
        j++;
    }
}

void rm_node(node_t **list, node_t *current)
{
    for (int i = 0; list[i] != NULL; i++) {
        if (list[i] == current) {
            push_nodes(list, i);
            return;
        }
    }
}

void add_node(node_t **list, node_t *current)
{
    int i = 0;
    while (list[i] != NULL) {
        i++;
    }
    list[i] = current;
    list[i + 1] = NULL;
}
