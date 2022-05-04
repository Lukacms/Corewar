##
## EPITECH PROJECT, 2022
## tetris
## File description:
## Makefile
##

SRC	=	src/corewar.c

SRC_ARGS	=

SRC_APP	=

OBJ	=	$(SRC:.c=.o)
OBJ	+=	$(SRC_ARGS:.c=.o)
OBJ	+=	$(SRC_APP:.c=.o)

SRC_MAIN	=	src/main.c

OBJ_MAIN	=	$(SRC_MAIN:.c=.o)

SRC_TESTS	=

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

NAME_TESTS	=	unit_test

NAME	=	corewar

LIBMY	=	../lib/libmy.a

CC	=	gcc

override CFLAGS	=	-W -Wall -Wextra -Wpedantic

override CPPFLAGS	=	-I./../include

override LDFLAGS	=	-L./../lib

override LDLIBS	=	-lmy -lncurses

all:	$(NAME)
.PHONY:	all

$(LIBMY):
	@make -C ../lib/my

$(NAME):	$(LIBMY) $(OBJ_MAIN) $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LDFLAGS) $(LDLIBS)

debug: fclean
debug: CFLAGS += -g
debug: $(NAME)
.PHONY:	debug

clean:
	@rm -f $(OBJ) $(OBJ_MAIN) $(OBJ_TESTS)
	@make clean -C ../lib/my
	@find -name "*.gcno" -delete
	@find -name "*.gcda" -delete
.PHONY:	clean

fclean:	clean
	@rm -f $(NAME)
	@rm -f $(NAME_TESTS)
.PHONY:	fclean

tests_run:	CPPFLAGS	+=	--coverage
tests_run:	CFLAGS	+=	-fprofile-arcs -ftest-coverage
tests_run:	LDLIBS	+=	-lcriterion -lgcov -lmy
tests_run:	fclean $(OBJ) $(OBJ_TESTS) $(LIBMY)
	gcc -o $(NAME_TESTS) $(OBJ) $(OBJ_TESTS) $(LDFLAGS) $(LDLIBS)
	-./$(NAME_TESTS)
.PHONY:	tests_run

coverage:
	gcovr --exclude tests
	gcovr --exclude tests --branches
.PHONY:	coverage

re	::	fclean
re	::	all
.PHONY:	re
