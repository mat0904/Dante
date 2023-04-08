/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** app.h
*/

#ifndef APP_H_
    #define APP_H_

    typedef struct vector {
        int x;
        int y;
    } vector_t;

    typedef struct node {
        char value;
        struct node *from;
        vector_t pos;
        int g_cost;
        int h_cost;
        int f_cost;
    } node_t;

    typedef struct lists {
        node_t **open;
        node_t **closed;
    } lists_t;

    typedef struct gps {
        node_t *origin;
        node_t *current;
        node_t *end;
    } gps_t;

    typedef struct app {
        node_t ***node_array;
        int display_maze;
    } app_t;

#endif
