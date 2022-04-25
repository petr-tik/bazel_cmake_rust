#include "bar.h"

extern "C" int complex_maths(int);

int my_math() {
    return 10;
}

int combine_my_math_and_rust(int input) {
    int input_by_ten = my_math() * input;

    return complex_maths(input_by_ten);
}
