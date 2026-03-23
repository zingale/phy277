#include <iostream>
#include <functional>
#include <cmath>

namespace Roots {
    const double ATOL = 1.e-10;   // absolute tolerance
    const double RTOL = 1.e-10;   // relative tolerance
    const int MAX_ITER = 100;
}

// Apply bisection to find a root of f(x) in the range [xleft, xright]
// Return value is 0 if root found, non-zero if there was an error

int bisection(double xleft, double xright,
              std::function<double(double)> f,
              double& root) {

    int ierr{0};

    double fleft = f(xleft);
    double fright = f(xright);

    if (fleft * fright > 0) {
        std::cout << "no root in interval [xleft, right]" << std::endl;
        ierr = 1;
        return ierr;
    } else if (fleft == 0 || fright == 0) {
        std::cout << "root is one of bounds" << std::endl;
        ierr = 1;
        return ierr;
    }

    double xmid = 0.5 * (xleft + xright);

    int iter{0};

    while (iter < Roots::MAX_ITER) {
        double fmid = f(xmid);

        if (fleft * fmid > 0.0) {
            // root is in [fmid, fright]
            xleft = xmid;
        } else {
            // root is in [fleft, fmid]
            xright = xmid;
        }

        double err = std::abs(xright - xleft);
        xmid = 0.5 * (xleft + xright);

        if (err < Roots::RTOL * std::abs(xmid) + Roots::ATOL) {
            ierr = 0;
            break;
        }

        iter++;
    }

    root = xmid;

    return ierr;
}

double f(double x) {
    return std::pow(x, 3.0) + std::pow(x, 2.0) - 1.0;
}

int main() {

    int ierr{0};
    double root{0.0};

    // bisection on f(x) = x^3 + x^2 - 1

    std::cout << "trying bisection on f(x) = x^3 + x^2 - 1" << std::endl;

    ierr = bisection(-5.0, 5.0, f, root);

    if (ierr == 0) {
        std::cout << root << std::endl;
    } else {
        std::cout << "root not found" << std::endl;
    }
    std::cout << std::endl;

}

