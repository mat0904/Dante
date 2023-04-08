##
## EPITECH PROJECT, 2023
## project
## File description:
## Makefile
##

SRC	=	src/main.c \
		src/random.c \
		src/display.c \
		src/generator.c	\
		src/free_resources.c \
		src/init_resources.c \
		src/error_handling.c \
		src/complete_maze.c \
		src/algo/recursive_division.c \
		src/algo/kruskal/int_list.c \
		src/algo/kruskal/prepare_maze.c \
		src/algo/kruskal/kruskal.c \
		src/algo/kruskal/get_node_list.c \
		src/algo/kruskal/create_connection.c \
		src/algo/kruskal/finish_maze.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc
CFLAGS	=
EXE	=	generator

all:	$(EXE)

%.o:	%.c
		$(CC) -o $@ -c $< $(CFLAGS)

$(EXE):	$(OBJ)
		$(CC) -o $@ $^

clean:
		@make -C ./tests clean
		@rm -rf $(OBJ)
		@rm -rf vgcore*
		@rm -rf *.gcda
		@rm -rf *.gcno

fclean:	clean
		@make -C ./tests fclean
		@rm -rf $(EXE)

re:	fclean all

unit_tests:
			@make -C ./tests

tests_run:	unit_tests
			./tests/mysh_test
