##
## EPITECH PROJECT, 2020
## cpp
## File description:
## Makefile cpp with Unit tests
##

SRCDIR = src/

SRC_SRC	=	main.c\
			cut.c\

SRC =	$(addprefix $(SRCDIR), $(SRC_SRC))

CRITDIR = tests/

CRT_SRC	=	redirect.c\

CRT = $(addprefix $(CRITDIR), $(CRT_SRC))

NAME	=	test

all:	$(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) -I ./include/ -g3

tests_run:
		gcc $(SRC) $(CRT) -o unit_tests  -I ./include/ --coverage -lcriterion
		rm -rf *.gcda *.gcno
		./unit_tests
		gcovr

clean:
	rm -rf *.gcda *.gcno

fclean:	clean
	rm -f $(NAME)

re:	fclean all
