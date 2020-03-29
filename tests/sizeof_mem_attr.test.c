#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "compute.h"

// void redirect_all_stdout(void);

Test(sizeof_mem_attr, test_1)
{
    cr_assert_eq(sizeof_mem_attr(1), 1);
    cr_assert_eq(sizeof_mem_attr(16), 16);
    cr_assert_eq(sizeof_mem_attr(17), 32);
    cr_assert_eq(sizeof_mem_attr(1024), 1024);
    cr_assert_eq(sizeof_mem_attr(1024), 1024);
}
