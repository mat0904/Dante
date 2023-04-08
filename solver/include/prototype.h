/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** prototype
*/

#ifndef BASE_REPO_PROTOTYPE_H
    #define BASE_REPO_PROTOTYPE_H

    #include "include.h"

    int solver(const int ac, const char **av);

    int display_node_array(app_t *app);

    int get_filesize(const char *pathfile);
    int get_line_nb(const char *pathfile);

    vector_t find_end(app_t *app);

    app_t *init_resources(void);
    gps_t *init_gps(app_t *app);
    lists_t *init_list(app_t *app);

    int free_resources(app_t *app);
    int free_array(char **array);
    int free_astar(gps_t *gps, lists_t *lists);

    node_t ***read_map(const char *pathfile);

    void astar_solve(app_t *app);
    int manhattan_dist(vector_t a_node, vector_t b_node);
    void rm_node(node_t **list, node_t *current);
    void add_node(node_t **list, node_t *current);
    void algorithm(app_t *app, lists_t *lists, gps_t *gps);
    void node_init(app_t *app, gps_t *gps);
    void algo_next(vector_t *neighb, lists_t *lists, app_t *app, gps_t *gps);
    void fill_maze(app_t *app, node_t *end);

#endif //BASE_REPO_PROTOTYPE_H
