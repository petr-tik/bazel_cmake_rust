#include <iostream>
#include "bar.h"
#include "lib.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    hello_world();
    if (my_math() == 10) {
        std::cout << "my_math returns 10" << std::endl;
    }
    return my_math();
}
