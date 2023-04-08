/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** error_handling
*/

#include "../include/prototype.h"

static int parse_number(const char *arg)
{
    int i = 0;
    while (arg[i] != '\0') {
        if (arg[i] < 48 || arg[i] > 57) {
            return 84;
        }
        i += 1;
    }
    return 0;
}

int args_error_handling(const int ac, const char **av)
{
    if (ac < 3 || ac > 4)
        return 84;
    if ((parse_number(av[1]) == 84) || (parse_number(av[2]) == 84))
        return 84;
    return 0;
}
