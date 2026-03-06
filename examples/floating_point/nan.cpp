#include <iostream>
#include <cmath>

int main() {

    double x{-1.0};

    double y = std::sqrt(x);

    std::cout << y << std::endl;
    std::cout << std::isnan(y) << std::endl;

}
