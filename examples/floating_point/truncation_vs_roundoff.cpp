#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <vector>
#include <format>

double f(double x) {
    return std::sin(x);
}

double dfdx_true(double x) {
    return std::cos(x);
}

struct point {
    double dx;
    double err;
};

int main() {

    double dx = 0.1;
    double x0 = 1.0;

    std::vector<point> data;

    while (dx > std::numeric_limits<double>::epsilon()) {

        point p;
        p.dx = dx;

        double dfdx_approx = (f(x0 + dx) - f(x0)) / dx;
        double err = std::abs(dfdx_approx - dfdx_true(x0));

        p.err = err;

        data.push_back(p);

        dx /= 2.0;
    }

    std::cout << std::setprecision(8) << std::scientific;

    for (const auto p : data) {
        std::cout << std::format("{:12.6g} {:12.6g}\n", p.dx, p.err);
    }
}
