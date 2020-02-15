##
## EPITECH PROJECT, 2020
## cpp
## File description:
## Makefile cpp with Unit tests
##

SRCDIR = src/

SRC_SRC	=	sizeof_mem_attr.c\
			is_pow_of_two.c\
			my_put_nbr.c\
			enlarge_memory.c\
			init_list.c\
			malloc.c\
			shrink_memory.c\
			free_from_the_head.c\
			split.c\
			find_freed_node.c\

SRC =	$(addprefix $(SRCDIR), $(SRC_SRC))

CRITDIR = tests/

CRT_SRC	=	redirect.c\
			sizeof_mem_attr.test.c\

CRT = $(addprefix $(CRITDIR), $(CRT_SRC))

NAME	=	libmy_malloc.so

all:	$(NAME)

$(NAME):
		gcc -Wall -fPIC -c $(SRC) -I include/
		gcc -shared -Wl,-soname,$(NAME) -o $(NAME) *.o

test:
	gcc src/main.c -o test -lm -g3
	LD_PRELOAD=./libmy_malloc.so ./test

test2:
	gcc src/main.c $(SRC) -o test2 -I include -lm -g3
	./test2
	valgrind ./test2
	rm test2

tests_run:
		gcc -o unit_tests $(SRC) $(CRT) -I include/ -lm --coverage -lcriterion
		valgrind ./unit_tests
		gcovr
		rm -rf *.gcda *.gcno unit_tests

clean:
	rm -rf *.o
	rm -rf *.gcda *.gcno

fclean:	clean
	rm -f $(NAME)

re:	fclean all
