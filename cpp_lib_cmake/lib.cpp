#include "lib.hpp"

#include <iostream>

void hello_world()
{
    std::cout << "Hello world!" << std::endl;
}

int add_three_in_cmake_lib(int input) {
    return input + 3;
}
