/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** tests_errors
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <stdio.h>
#include "redcode.h"
#include "my.h"

void redirect_all_std(void);

Test(lexer, lexer_cant_load, .init=redirect_all_std)
{
    infos_t infos = {0};
    char *filename = "../tests/assets/src/zebi_name.s";
    char *load_err = "lexer error on line: 0; file couldn't be load\n";

    fflush(stdout);
    cr_assert_eq(lexer(&infos), FAILURE);
    cr_assert_stdout_eq_str(load_err);
}

Test(lexer, lexer_wrong_separator, .init=redirect_all_std)
{
    infos_t infos = {0};
    char *filename = "../tests/assets/src/zebi_name.s";
    char **err = "lexer error on line: 12; instructions not separated correctly.\n";

    infos.input_name = filename;
    cr_assert_eq(lexer(&infos), FAILURE);
    cr_assert_stdout_eq_str(err);
}

Test(lexer, lexer_null, .init=redirect_all_std)
{
    cr_assert_eq(lexer(NULL), FAILURE);
}

Test(lexer, wrong_arguments_parser, .init=redirect_all_std)
{
    char * const argv[] = {"haha", "../tests/assets/src/wrong_arguments.s"};
    int argc = 2;

    cr_assert_eq(launch(argc, argv), FAILURE);
}
