#include "bar.h"
#include "lib.hpp"
#include <fmt/color.h>
#include <iostream>

extern "C" int maths_in_rust(int);
extern "C" char* string_from_rust(int);

using namespace std;

int my_math() {
    return 10;
}

int combine_my_math_and_rust(int input) {
    int input_by_ten = my_math() * input;
    return add_three_in_cmake_lib(maths_in_rust(input_by_ten));
}

void pretty_print_a_rust_string(int input) {
    std::string rust_str = string_from_rust(input);

    fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, rust_str);
}
