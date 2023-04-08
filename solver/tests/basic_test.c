/*
** EPITECH PROJECT, 2023
** CPE
** File description:
** basic_test.c
*/

#include "../include/prototype.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(read_map, empty_file, .init = redirect_all_std) {
    node_t ***node_array = read_map(".nofile");
    cr_assert_eq(node_array, NULL);
}

Test(read_map, folder, .init = redirect_all_std) {
    node_t ***node_array = read_map(".");
    cr_assert_eq(node_array, NULL);
}

