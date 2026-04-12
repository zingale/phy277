#include <iostream>
#include <functional>
#include <cmath>
#include <format>

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
            // root is in [xmid, xright]
            xleft = xmid;
            fleft = fmid;
        } else {
            // root is in [xleft, xmid]
            xright = xmid;
            // fright = fmid;  // we don't use fright
        }

        double err = std::abs(xright - xleft);
        xmid = 0.5 * (xleft + xright);

        // check if we've converged
        if (err < Roots::RTOL * std::abs(xmid) + Roots::ATOL) {
            ierr = 0;
            break;
        }

        iter++;
    }

    // check to see if we took too many iterations
    if (iter == Roots::MAX_ITER) {
        std::cout << "too many iterations" << std::endl;
        ierr = 1;
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
        std::cout << std::format("x_0 = {}; f(x_0) = {}\n",
                                 root, f(root));
    } else {
        std::cout << "root not found" << std::endl;
    }
    std::cout << std::endl;

}
