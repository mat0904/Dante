##
## EPITECH PROJECT, 2023
## project
## File description:
## Makefile
##

SRC	=	basic_test.c \
		../src/solver.c \
		../src/display.c \
		../src/read_map.c \
		../src/file_info.c \
		../src/resources/init_resources.c \
		../src/resources/free_resources.c \
		../src/resources/init_node.c \
		../src/list_mod.c \
		../src/manhattan.c \
		../src/algorithm.c \
		../src/fill_maze.c \
		../src/astar_solve.c \
		../src/algorithm_next.c

OBJ_FOLDER	=	../obj
OBJ	=	$(SRC:.c=.o)
OBJ_FILES	=	$(addprefix $(OBJ_FOLDER)/, $(notdir $(OBJ)))

CC	=	gcc
CFLAGS	=
FLAGS	=
TEST_FLAGS	=	--coverage -lcriterion
EXE	=	unit_tests

all:	$(EXE)

$(EXE):
		$(CC) -o $(EXE) $(SRC) $(TEST_FLAGS) $(CFLAGS) $(FLAGS)

clean:
		@rm -rf *.gcda
		@rm -rf *.gcno

fclean:	clean
		@rm -rf $(EXE)

re:	fclean all
