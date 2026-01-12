#include <cmath>
#include <iostream>

int main() {

    double x{2.0};

    // compute x**3
    std::cout << "x**3 = " << std::pow(x, 3.0) << std::endl;
    std::cout << std::endl;

    // compute x**0.5
    std::cout << "x**0.5 = " << std::pow(x, 0.5) << std::endl;
    std::cout << "       = " << std::sqrt(x) << std::endl;
    std::cout << std::endl;

    // compute x**(1./3.)
    std::cout << "x**(1./3.) = " << std::pow(x, 1.0 / 3.0) << std::endl;
    std::cout << "           = " << std::cbrt(x) << std::endl;
    std::cout << std::endl;

}
