/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-axel.chypre
** File description:
** read_map.c
*/

#include "../include/prototype.h"

static int convert_map_line(node_t ***node_array, char *line, int index)
{
    int i = 0;
    node_array[index] = malloc(sizeof(node_t *) * (strlen(line) + 1));
    while (line[i] != '\0') {
        node_array[index][i] = malloc(sizeof(node_t));
        node_array[index][i]->value = line[i];
        i += 1;
    }
    node_array[index][i] = NULL;
    return 0;
}

static node_t ***convert_map(char **array, int nb_line)
{
    node_t ***node_array = malloc(sizeof(node_t **) * (nb_line + 1));
    int i = 0;
    while (array[i] != NULL) {
        convert_map_line(node_array, array[i], i);
        i += 1;
    }
    node_array[i] = NULL;
    return node_array;
}

static int read_file(FILE *file, char **array)
{
    size_t len = 0;
    int read_size = 0;
    char *buffer = NULL;
    int i = 0;
    while ((read_size = getline(&buffer, &len, file)) != -1) {
        if (buffer[read_size - 1] == '\n')
            buffer[read_size - 1] = '\0';
        array[i] = strdup(buffer);
        i += 1;
    }
    array[i] = NULL;
    free(buffer);
    return 0;
}

static int existing_file(const char *pathfile)
{
    struct stat *s = malloc(sizeof(struct stat));
    if (stat(pathfile, s) == -1)
        return 84;
    free(s);
    return 0;
}

node_t ***read_map(const char *pathfile)
{
    if (existing_file(pathfile) == 84)
        return NULL;
    int line_nb = get_line_nb(pathfile) + 1;
    char **array = malloc(sizeof(char *) * line_nb);
    FILE *file = fopen(pathfile, "r");
    if (errno != 0)
        return NULL;
    read_file(file, array);
    fclose(file);
    node_t ***node_array = convert_map(array, line_nb);
    free_array(array);
    return node_array;
}
