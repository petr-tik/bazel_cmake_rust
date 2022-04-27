#include <iostream>
#include <fmt/color.h>
#include "bar.h"
#include "lib.hpp"


using namespace std;

int main(int argc, char *argv[]) {
    hello_world_from_cmake();
    if (my_math() == 10) {
        std::cout << "my_math returns 10" << std::endl;
    }
    std::cout << "The result of add_three_in_cmake_lib(my_math()) = " << add_three_in_cmake_lib(my_math()) << std::endl;

    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "Colourful hello {}!\n", "world");
    return my_math();
}
