/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** prototype
*/

#ifndef BASE_REPO_PROTOTYPE_H
    #define BASE_REPO_PROTOTYPE_H

    #include "include.h"

    #define ALGO    0
    #define COLOR   0

    int generator(const int ac, const char **av);

    //resources
    maze_t *init_resources(const int ac, const char **av);
    int free_resources(maze_t *maze);

    //display
    int display_maze(maze_t *maze);

    //error handling
    int args_error_handling(const int ac, const char **av);

    //random
    int generate_random(int min, int max);

    //algo
    node_t **get_node(maze_t *maze);
    int len_list(node_t **node);
    int shift_list(node_t **node, int index);

    int append_int_list(int *list, int value);
    int reset_list(int *list);
    int generate_random_list(int *list);
    int len_int_list(int *list);

    int kruskal(maze_t *maze);
    int recursive_division(maze_t *maze, vector_t start, vector_t end, int i);
    int complete_maze(maze_t *maze);
    int prepare_maze(maze_t *maze);
    int finish_maze(maze_t *maze);

    int create_vert(maze_t *maze, node_t *tmp_node);
    int create_hori(maze_t *maze, node_t *tmp_node);

#endif //BASE_REPO_PROTOTYPE_H
