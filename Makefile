##
## EPITECH PROJECT, 2023
## B-CPE-200-LYN-2-1-dante-axel.chypre
## File description:
## Makefile
##

all:
		@make -C ./solver
		@make -C ./generator

clean:
		@make -C ./solver clean
		@make -C ./generator clean

fclean:
		@make -C ./solver fclean
		@make -C ./generator fclean

re:
		@make -C ./solver re
		@make -C ./generator re
