#include <iostream>
#include <format>
#include <cmath>
#include <functional>

double Dc(std::function<double(double)> f, double x0, double dx) {
    return 0.5 * (f(x0 + dx) - f(x0 - dx)) / dx;
}

double f(double x) {
    return std::sin(x);
}

double fprime(double x) {
    return std::cos(x);
}

int main() {

    const double x0 = 1.0;

    for (auto dx : {0.1, 0.05, 0.025, 0.0125}) {
        auto diff = Dc(f, x0, dx);
        double error = std::abs(diff - fprime(x0));
        std::cout << std::format("{:7.4f} {:8.5f} {:9.5e}\n",
                                 dx, diff, error);
    }

}
