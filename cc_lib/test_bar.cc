#include <gtest/gtest.h>
#include "bar.h"

TEST(CppAndRust, combinemaths) {
    int input = 5;
    int expected = 503;

    ASSERT_EQ(expected, combine_my_math_and_rust(input));
}
