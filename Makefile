##
## EPITECH PROJECT, 2020
## cpp
## File description:
## Makefile cpp with Unit tests
##

SRCDIR =	src/

SRC_SRC	=	add_new_node.c			\
			calloc.c				\
			enlarge_memory.c		\
			find_freed_node.c		\
			free_from_the_head.c	\
			free_from_the_middle.c	\
			get_size_list.c			\
			init_list.c				\
			malloc.c				\
			my_put_nbr.c			\
			realloc_array.c			\
			realloc.c				\
			shrink_memory.c			\
			split.c					\

SRC2	=	src/sizeof_mem_attr.c	\
			src/is_pow_of_two.c		\

SRC =	$(addprefix $(SRCDIR), $(SRC_SRC))

CRITDIR = tests/

CRT_SRC		=	redirect.c\
			sizeof_mem_attr.test.c\

OBJ		=	$(SRC:.c=.o)	\
			$(SRC2:.c=.o)	\

CPPFLAGS	+=	-I include

CFLAGS		+=	-fPIC	-Wall

CRT = $(addprefix $(CRITDIR), $(CRT_SRC))

NAME	=	libmy_malloc.so

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -shared -Wl,-soname,$(NAME) -o $(NAME) $(OBJ)

test:
	gcc src/main.c $(SRC) $(SRC2) -o test  -lm -g3 -I include
	# ./test
	# rm -f test
	#if want to compile you need to use LD_LIBRARY_PATH

tests_run:
		gcc -o unit_tests $(SRC2) $(CRT) -I include/ -lm --coverage -lcriterion
		./unit_tests
		gcovr
		rm -rf *.gcda *.gcno unit_tests

clean:
	rm -rf $(OBJ)
	rm -rf *.gcda *.gcno

fclean:	clean
	rm -f $(NAME)

re:	fclean all
