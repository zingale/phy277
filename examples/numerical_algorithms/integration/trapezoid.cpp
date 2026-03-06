#include <iostream>
#include <functional>
#include <numbers>
#include <cmath>
#include <format>

double f(double x) {
    return 1.0 + 0.25 * x * std::sin(std::numbers::pi * x);
}


double I_analytic() {
    return 1.0 - 1.0 / (2.0 * std::pow(std::numbers::pi, 2.0));
}

double trapezoid(double a, double b, int N,
                 std::function<double(double)> func) {

    double dx = (b - a) / static_cast<int>(N);

    double I{};

    // loop over intervals
    for (int n = 0; n < N; ++n) {
        double xl = a + dx * n;
        double xr = a + dx * (n+1);

        double fl = func(xl);
        double fr = func(xr);

        I += 0.5 * dx * (fl + fr);
    }

    return I;

}


int main() {

    // perform trapezoid integration on f(x) for a variety on N and
    // compute the error compared to the analytic solution

    double a = 0.5;
    double b = 1.5;

    std::cout << std::format("{:^3} {:^10} {:^12}\n",
                             "N", "I", "error");

    for (auto N : {2, 4, 8, 16, 32, 64, 128}) {
        auto I = trapezoid(a, b, N, f);
        auto I_exact = I_analytic();
        double err = std::abs(I - I_exact);

        std::cout << std::format("{:3} {:10.5f} {:12.5e}\n",
                                 N, I, err);
    }
}

