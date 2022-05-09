/*
** EPITECH PROJECT, 2022
** tests_args
** File description:
** tests_args
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "redcode.h"

Test(launch, not_enough_arguments_numbers)
{
    int ac = 1;
    char *av[2] = {"./asm/asm", NULL};

    cr_assert_eq(launch(ac, av), 84);
}

Test(launch, too_many_arguments_numbers)
{
    int ac = 3;
    char *av[4] = {"./asm/asm", "file.s", "test", NULL};

    cr_assert_eq(launch(ac, av), 84);
}

Test(launch, wrong_file_extension)
{
    int ac = 2;
    char *av[3] = {"./asm/asm", "file.txt", NULL};

    cr_assert_eq(launch(ac, av), 84);
}

Test(launch, file_does_not_exist)
{
    int ac = 2;
    char *av[3] = {"./asm/asm", "file.s", NULL};

    cr_assert_eq(launch(ac, av), 84);
}
