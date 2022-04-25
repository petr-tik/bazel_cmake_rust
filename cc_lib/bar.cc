#include "bar.h"
#include "lib.hpp"

extern "C" int complex_maths(int);

int my_math() {
    return 10;
}

int combine_my_math_and_rust(int input) {
    int input_by_ten = my_math() * input;

    return add_three_in_cmake_lib(complex_maths(input_by_ten));
}
