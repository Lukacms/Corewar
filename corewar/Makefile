##
## EPITECH PROJECT, 2022
## Corewar
## File description:
## Makefile
##

SRC	=	src/corewar.c	\
		src/battlefield.c	\
		src/lexing/lexer.c	\
		src/instrution/ld.c	\
		src/misc/read_file.c	\
		src/instrution/sub.c	\
		src/instrution/add.c	\
		src/instrution/sti.c	\
		src/instrution/live.c	\
		src/instrution/zjump.c	\
		src/create_vm/create_vm.c	\
		src/misc/fill_registers.c	\
		src/misc/get_len_of_name.c	\
		src/misc/from_byte_to_nbr.c	\
		src/misc/get_size_of_file.c	\
		src/create_vm/create_warrior.c	\
		src/warriors/generate_warriors.c	\
		src/instrution/which_instruction.c	\
		src/place_warriors/set_warriors_in_mem.c	\
		src/argument_handling/check_parameters.c	\

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
