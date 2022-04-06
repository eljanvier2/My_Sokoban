##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## task 01
##

SRC_MAIN =	./src/main_file.c

SRC	=	./src/my_putstr.c	\
		./src/map_init.c	\
		./src/map_info.c	\
		./src/error_handling.c	\
		./src/moving_utils.c	\
		./src/map_read.c	\
		./src/char_finders.c	\
		./src/moving_checks.c	\
		./src/run.c	\
		./src/win_utils.c	\
		./src/locked_checking.c	\
		./src/my_strlen.c	\
		./src/printer.c	\
		./src/my_strcmp.c	\
		./src/outcomes_check.c	\
		./src/usage.c

NAME 	=	my_sokoban

CPPFLAGS =	-I./include
CPPFLAGS += -lncurses
CFLAGS =	-W -Wall -Wextra

LDFLAGS =

TESTS_FLAGS = --coverage -lcriterion
TESTS_FLAGS += -I./include

TESTS_SRC =	./src/my_put_nbr.c	\
			./tests/unit_tests.c	\
			./tests/init_tests.c

OBJ	=	$(SRC:.c=.o)
OBJ_GCDA =	$(SRC:.c=.gcda)
OBJ_GCNO =	$(SRC:.c=.gcno)
OBJ_MAIN =	$(SRC_MAIN:.c=.o)
OBJ_TEST = 	$(TESTS_SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJ_MAIN)
	gcc -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CPPFLAGS) $(CFLAGS)

debug:	CFLAGS += -g
debug:	fclean $(NAME)

clean:
	rm -rf $(OBJ) $(OBJ_MAIN) $(OBJ_TEST) $(OBJ_GCDA) $(OBJ_GCNO)
	rm -rf unit*
	rm -rf vgcore*
	rm -rf .cache
	rm -rf tests/*.gcno
	rm -rf tests/*.gcda

fclean: clean
	rm -rf $(NAME)

re:	fclean all

tests_run: CFLAGS += -fprofile-arcs -ftest-coverage
tests_run: LDFLAGS += -lcriterion -lgcov
tests_run:	fclean $(OBJ) $(OBJ_TEST)
	rm -rf unit*
	echo $(OBJ_TEST)
	gcc -o unit_tests $(OBJ) $(OBJ_TEST) $(LDFLAGS) $(CFLAGS)  $(CPPFLAGS) -g
	./unit_tests
	gcovr

cover:
	mkdir -p crit_result
	gcovr --exclude tests/ --html --html-details -o crit_result/cov.html
	gcovr --branches --exclude tests/

auteur:
	echo $(USER) > auteur

.PHONY:	all clean fclean re auteur debug tests_run cover
