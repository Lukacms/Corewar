/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** tests_help
*/

#define FALSEHELP "tests/assets/falsehelp.txt"
#define STDOUT_STR "oui\n"
#define NONEXISTING "nope"
#define FALSE_ERROR_CODE 157

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "redcode.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(display_help, fake_file)
{
    cr_assert_eq(display_help(FALSE_ERROR_CODE, NULL), FALSE_ERROR_CODE);
    cr_assert_eq(display_help(FALSE_ERROR_CODE, NONEXISTING), FALSE_ERROR_CODE);
}

Test(display_help, good_file, .init=redirect_all_std)
{
    fflush(stdout);
    cr_assert_eq(display_help(SUCCESS, "../tests/assets/help/falsehelp.txt"), SUCCESS);
    cr_assert_stdout_eq_str(STDOUT_STR);
}
