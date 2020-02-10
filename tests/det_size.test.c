#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "node.h"

// void redirect_all_stdout(void);

Test(determine_node_size, test_1)
{
    cr_assert_eq(determine_node_size(1), 32);
    cr_assert_eq(determine_node_size(16), 32);
    cr_assert_eq(determine_node_size(17), 64);
}
