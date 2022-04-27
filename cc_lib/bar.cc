#include "bar.h"
#include "lib.hpp"
#include <iostream>

extern "C" int maths_in_rust(int);
extern "C" char* string_from_rust(int);

int my_math() {
    return 10;
}

int combine_my_math_and_rust(int input) {
    int input_by_ten = my_math() * input;

    return add_three_in_cmake_lib(maths_in_rust(input_by_ten));
}

