#include <gtest/gtest.h>
#include "bar.h"


TEST(CppAndRust, combinemathsPanic) {
    int input = 50000000;
    EXPECT_ANY_THROW(combine_my_math_and_rust(input));
}
