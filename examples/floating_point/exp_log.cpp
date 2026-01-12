#include <cmath>
#include <iostream>

int main() {

    double x{123456.789};

    double ln_x = std::log(x);
    double log10_x = std::log10(x);

    std::cout << "ln(x)    = " << ln_x << std::endl;
    std::cout << "log10(x) = " << log10_x << std::endl;
    std::cout << std::endl;

    // notice that we use { } here to "scope" this
    // meaning that x_recovered is not defined outside
    // of this block.

    {
        double x_recovered = std::exp(ln_x);

        std::cout << "exp(ln(x)) = " << x_recovered << std::endl;
        std::cout << "difference = " << x - x_recovered << std::endl;

        std::cout << std::endl;
    }

    {
        double x_recovered = std::pow(10.0, log10_x);

        std::cout << "10**log10(x) = " << x_recovered << std::endl;
        std::cout << "difference = " << x - x_recovered << std::endl;

        std::cout << std::endl;
    }
}
