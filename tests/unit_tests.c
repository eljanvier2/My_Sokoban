/*
** EPITECH PROJECT, 2022
** unit tests
** File description:
** unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout ();
    cr_redirect_stderr ();
}

Test(my_strcmp, comp_test1, .init = redirect_all_std)
{
    char *s1 = "Bonjour";
    char *s2 = "Bonjour";

    my_put_nbr((my_strcmp(s1, s2)));
    cr_assert_stdout_eq_str("0");
}

Test(my_strcmp, comp_test2, .init = redirect_all_std)
{
    char *s1 = "Bonjour";
    char *s2 = "Bonjo";

    my_put_nbr((my_strcmp(s1, s2)));
    cr_assert_stdout_eq_str("1");
}

Test(my_strcmp, comp_test3, .init = redirect_all_std)
{
    char *s1 = "Bon";
    char *s2 = "Bonjo";

    my_put_nbr((my_strcmp(s1, s2)));
    cr_assert_stdout_eq_str("-1");
}

Test(my_putstr, putstr, .init = redirect_all_std)
{
    char *str = "bonjour";

    my_putstr(str);
    cr_assert_stdout_eq_str("bonjour");
}