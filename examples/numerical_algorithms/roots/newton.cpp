#include <iostream>
#include <functional>
#include <cmath>
#include <format>

namespace Roots {
    const double ATOL = 1.e-10;   // absolute tolerance
    const double RTOL = 1.e-10;   // relative tolerance
    const int MAX_ITER = 100;
}

// Apply Newtons's method to find a root of f(x) starting with the initial
// guess x0.  In addition to f(x) we need to supply the derivative, dfdx(x).
// Return value is 0 if root found, non-zero if there was an error

int newton(double x0,
           std::function<double(double)> f,
           std::function<double(double)> dfdx,
           double& root) {

    int ierr{1};

    int iter{0};
    while (iter < Roots::MAX_ITER ) {

        double f0 = f(x0);
        double dfdx0 = dfdx(x0);

        double dx = -f0/dfdx0;

        if (std::abs(dx) < Roots::RTOL * std::abs(x0) + Roots::ATOL) {
            ierr = 0;
            break;
        }

        x0 += dx;
        iter++;
    }

    root = x0;
    return ierr;
}

double f(double x) {
    return x * x;
}

double dfdx(double x) {
    return 2.0 * x;
}

int main() {

    std::cout << "trying Newton's method on f(x)" << std::endl;

    double root{};

    auto ierr = newton(-1.0, f, dfdx, root);

    if (ierr == 0) {
        std::cout << std::format("x_0 = {}; f(x_0) = {}\n",
                                 root, f(root));
    } else {
        std::cout << "root not found" << std::endl;
    }
    std::cout << std::endl;

}

