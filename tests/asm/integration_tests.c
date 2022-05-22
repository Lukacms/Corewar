/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** integration_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "redcode.h"

void redirect_all_std(void);

Test(launch, full_valid_test)
{
    char * const argv[] = {"hehe", "../tests/assets/src/abel.s"};
    int argc = 2;

    cr_assert_eq(launch(argc, argv), SUCCESS);
}
