##
## EPITECH PROJECT, 2022
## asm
## File description:
## Makefile
##

SRC	=	src/asm.c	\
		src/help/display_help.c	\

SRC_ERRORS	=	src/errors/check_args.c	\
				src/errors/print_error.c	\
				src/errors/check_in_file.c	\

SRC_LEXER	=	src/lexer/lexer.c	\
				src/lexer/array_size.c	\

SRC_PARSER	=	src/parser/parser.c	\
				src/parser/is_label.c	\
				src/parser/add_opnode.c	\
				src/parser/count_node_size.c	\
				src/parser/infos_in_opnode.c	\
				src/parser/params/get_params.c	\
				src/parser/params/param_infos.c	\
				src/parser/params/add_param_node.c	\
				src/parser/params/handler/dir_handler.c	\
				src/parser/params/handler/ind_handler.c	\
				src/parser/params/handler/reg_handler.c	\
				src/parser/params/handler/check_param_pos.c	\
				src/parser/params/handler/combination_handler.c	\

SRC_COMPILE	=	src/compile/compile.c	\
				src/compile/compile_line.c	\
				src/compile/create_header.c	\
				src/compile/put_parameters_type.c	\
				src/compile/params/compile_direct.c	\
				src/compile/params/compile_indirect.c	\
				src/compile/params/compile_register.c	\

SRC_UTILS	=	src/utils/my_strcmp_insensitive.c	\
				src/utils/load_file.c	\
				src/utils/str_sep_to_array.c	\
				src/utils/reverse_int_bytes.c	\

OBJ	=	$(SRC:.c=.o)
OBJ	+=	$(SRC_ERRORS:.c=.o)
OBJ	+=	$(SRC_LEXER:.c=.o)
OBJ	+=	$(SRC_PARSER:.c=.o)
OBJ	+=	$(SRC_COMPILE:.c=.o)
OBJ	+=	$(SRC_UTILS:.c=.o)

SRC_MAIN	=	src/main.c

OBJ_MAIN	=	$(SRC_MAIN:.c=.o)

SRC_TESTS	=	../tests/asm/tests_args.c	\
				../tests/asm/tests_files.c

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

NAME_TESTS	=	unit_test

NAME	=	asm

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
