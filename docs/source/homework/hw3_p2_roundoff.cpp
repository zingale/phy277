#include <iostream>
#include <cmath>

int main() {

    double x{1.e-4};

    double f = 1.0 / (std::sqrt(std::pow(x, 3.0) + 1.0) - 1.0);

    // multiplying and dividing f by (sqrt(x^3 + 1) + 1) and
    // simplifying
    double g = (std::sqrt(std::pow(x, 3.0) + 1.0) + 1.0) /
        std::pow(x, 3.0);

    std::cout << x << " " << f << " " << g << std::endl;


    x = 1.e-5;

    f = 1.0 / (std::sqrt(std::pow(x, 3.0) + 1.0) - 1.0);
    g = (std::sqrt(std::pow(x, 3.0) + 1.0) + 1.0) /
        std::pow(x, 3.0);

    std::cout << x << " " << f << " " << g << std::endl;


    x = 1.e-6;

    f = 1.0 / (std::sqrt(std::pow(x, 3.0) + 1.0) - 1.0);
    g = (std::sqrt(std::pow(x, 3.0) + 1.0) + 1.0) /
        std::pow(x, 3.0);

    std::cout << x << " " << f << " " << g << std::endl;


}
