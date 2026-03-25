#include <iostream>
#include <functional>
#include <numbers>
#include <cmath>
#include <format>


// the integrand / function we are integrating
double f(double x) {
    return 1.0 + 0.25 * x * std::sin(std::numbers::pi * x);
}


// the analytic integral of f(x) over our limits
double I_analytic() {
    return 1.0 - 1.0 / (2.0 * std::pow(std::numbers::pi, 2.0));
}


// trapezoid rule for numerical integration
double simpsons(double a, double b, int N,
                std::function<double(double)> func) {

    // width of single interval
    double dx = (b - a) / static_cast<double>(N);

    double I{};

    // loop over pairs of intervals
    for (int n = 0; n < N/2; ++n) {

        double xl = a + dx * 2 * n;
        double fl = func(xl);

        double xm = a + dx * (2 * n + 1);
        double fm = func(xm);

        double xr = a + dx * (2 * n + 2);
        double fr = func(xr);

        //std::cout << std::format("n = {}, xl = {}, xm = {}, xr = {}\n",
        //                         n, xl, xm, xr);

        I += dx * (fl + 4.0 * fm + fr) / 3.0;

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

    for (auto N : {2 , 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384}) {
        auto I = simpsons(a, b, N, f);
        auto I_exact = I_analytic();
        double err = std::abs(I - I_exact);

        std::cout << std::format("{:3} {:10.5f} {:12.5e}\n",
                                 N, I, err);
    }
}
