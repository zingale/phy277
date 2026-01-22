#include <iostream>
#include <limits>

int main() {

    double x{1.0};
    double eps{1.11e-16};

    // is x + eps the same as x?

    bool test = x + eps == x;

    std::cout << "x + eps == x: " << test << std::endl;

    // the C++ standard library can also tell us epsilon

    std::cout << "epsilon = " << std::numeric_limits<double>::epsilon() << std::endl;

}
