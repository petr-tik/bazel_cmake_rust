#include <gtest/gtest.h>
#include "bar.h"

extern "C" char *string_from_rust(int);

using namespace std;

TEST(CppAndRust, combinemaths) {
    int input = 5;
    int expected = 503;

    ASSERT_EQ(expected, combine_my_math_and_rust(input));
}

TEST(CppAndRust, get_string_from_rust) {
    int input = 5;

    std::string expected = "Rust is passing this string with number: 5\n";
    ASSERT_EQ(expected, string_from_rust(input));
}
