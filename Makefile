##
## EPITECH PROJECT, 2020
## cpp
## File description:
## Makefile cpp with Unit tests
##

SRCDIR = src/

SRC_SRC	=	init_list.c\
			sizeof_mem_attr.c\
			enlarge_memory.c\
			malloc.c\
			is_pow_of_two.c\
			find_and_split.c\
			split.c\
			add_new_node.c\

SRC =	$(addprefix $(SRCDIR), $(SRC_SRC))

CRITDIR = tests/

CRT_SRC	=	redirect.c\
			sizeof_mem_attr.test.c\

CRT = $(addprefix $(CRITDIR), $(CRT_SRC))

NAME	=	test

all:	$(NAME)

$(NAME):
	gcc $(SRC) src/main.c -o $(NAME) -I ./include/ -lm -g3

tests_run:
		gcc -o unit_tests $(SRC) $(CRT) -I include/ -lm --coverage -lcriterion
		./unit_tests
		gcovr
		rm -rf *.gcda *.gcno unit_tests

clean:
	rm -rf *.gcda *.gcno

fclean:	clean
	rm -f $(NAME)

re:	fclean all
