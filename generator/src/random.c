/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** random
*/

#include "../include/prototype.h"

int generate_random(int min, int max)
{
    if (min > max) {
        max ^= min;
        min ^= max;
        max ^= min;
    }
    int result = rand() % ((max + 1) - min) + min;
    return result;
}

int random_list(int start, int end, int modificator)
{
    if (modificator == -1) {
        return generate_random(start, end);
    } else {
        int result = generate_random(start, end);
        while (result % modificator != 0) {
            result = generate_random(start, end);
        }
        return result;
    }
}
