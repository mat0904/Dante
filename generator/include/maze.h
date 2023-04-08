/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** application
*/

#ifndef B_CPE_200_LYN_2_1_DANTE_AXEL_CHYPRE_APPLICATION_H
    #define B_CPE_200_LYN_2_1_DANTE_AXEL_CHYPRE_APPLICATION_H

    typedef enum status {
        WALL = 0,
        V_EDGE,
        H_EDGE,
        DOOR,
        CELL
    } status_t;

    typedef enum neighbour {
        UP = 1,
        DOWN = 2,
        LEFT = 3,
        RIGHT = 4
    } neightbour_t;

    typedef struct {
        int x;
        int y;
    } vector_t;

    typedef struct node {
        int value;
        status_t status;
        vector_t position;
    } node_t;

    typedef struct {
        node_t ***maze;
        node_t **edge_list;
        vector_t *size;
        int perfect;
    } maze_t;

#endif //B_CPE_200_LYN_2_1_DANTE_AXEL_CHYPRE_APPLICATION_H
