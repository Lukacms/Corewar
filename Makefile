##
## EPITECH PROJECT, 2021
## B-PSU-100-BDX-1-1-bsmyls-chloe.camus
## File description:
## Makefile
##

NAME_ASM	=	asm

NAME_COREWAR	=	corewar

NAME_TESTS	=	unit_test

all: $(NAME_ASM) $(NAME_COREWAR)

$(NAME_ASM):
	@make -C asm
.PHONY:	$(NAME_ASM)

$(NAME_COREWAR):
	@make -C corewar
.PHONY:	$(NAME_COREWAR)

debug:
	@make debug -C asm
	@make debug -C corewar
.PHONY:	debug

tests_run:
	@make tests_run -C corewar
	@make tests_run -C asm
.PHONY:	tests_run

coverage:
	gcovr --exclude tests
	gcovr --exclude tests --branches
.PHONY:	coverage

clean:
	@make clean -C asm
	@make clean -C corewar
	@make clean -C lib/my
	@find -name *.o -delete
	@find -name *.gcno -delete
	@find -name *.gcda -delete
.PHONY:	clean

fclean:	clean
	@make fclean -C asm
	@make fclean -C corewar
	@rm -f $(NAME_TESTS)
.PHONY:	fclean

re: fclean
	@make re -C asm
	@make re -C corewar
.PHONY:	re
