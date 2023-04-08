/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** int_list.c
*/

#include "../../../include/prototype.h"

int reset_list(int *list)
{
    list[0] = 0;
    list[1] = 0;
    list[2] = 0;
    list[3] = 0;
    list[4] = 0;
}

int len_int_list(int *list)
{
    int i = 0;
    while (list[i] != 0) {
        i += 1;
    }
    return i;
}

int append_int_list(int *list, int value)
{
    int i = 0;
    while (list[i] != 0) {
        i += 1;
    }
    list[i] = value;
    return 0;
}

int generate_random_list(int *list)
{
    int start = 0;
    int end = 0;
    while (list[end] != 0) {
        end += 1;
    }
    int result = generate_random(start, end);
    return result;
}
