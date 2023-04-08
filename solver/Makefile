##
## EPITECH PROJECT, 2023
## project
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/solver.c \
		src/display.c \
		src/read_map.c \
		src/file_info.c \
		src/resources/init_resources.c \
		src/resources/free_resources.c \
		src/resources/init_node.c \
		src/list_mod.c \
		src/manhattan.c \
		src/algorithm.c \
		src/fill_maze.c \
		src/astar_solve.c \
		src/algorithm_next.c


OBJ_FOLDER	=	obj
OBJ	=	$(SRC:.c=.o)
OBJ_FILES	=	$(addprefix $(OBJ_FOLDER)/, $(notdir $(OBJ)))

CC	=	gcc
CFLAGS	=
FLAGS	=
SANITIZE	=	-g3
EXE	=	solver

all:	$(EXE)

%.o:	%.c
		@$(CC) -o $(OBJ_FOLDER)/$(notdir $@) -c $^ $(CFLAGS) $(FLAGS) -g3

$(EXE):	$(OBJ)
		$(CC) -o $(EXE) $(OBJ_FILES) $(LIB) $(CFLAGS) $(FLAGS)

clean:
		@make -C ./tests clean
		@rm -rf $(OBJ_FILES)
		@rm -rf vgcore*
		@rm -rf *.gcda
		@rm -rf *.gcno

fclean:	clean
		@make -C ./tests fclean
		@rm -rf $(EXE)

valgrind:	$(OBJ)
			$(CC) -o $(EXE) $(OBJ_FILES) $(CFLAGS) $(FLAGS) -g3

re:	fclean all

unit_tests:
			@make -C ./tests

tests_run:	unit_tests
			./tests/unit_tests
