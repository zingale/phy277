#include <iostream>
#include <format>
#include <cmath>

// the function we are differentiating
double f(double x) {
    return std::pow(x, 4.0) + std::pow(x, 2.0) + 1.0;
}

// the analytic second-derivative of f(x)
double df2dx2(double x) {
    return 12.0 * x * x + 2.0;
}

int main() {

    // the x-value where we want to compute the second-derivative
    double x0{1.5};

    // the analytic second derivative at x0
    double df2dx2_true = df2dx2(x0);

    // output a header -- note the use of "^" to center these headings
    // in the column
    std::cout << std::format("{:^12} {:^12} {:^12}\n",
                             "dx", "d2f/dx2", "error");

    for (double dx : {0.1, 0.05, 0.025, 0.0125}) {

        // our 2nd-order accurate second-derivative finite-difference
        double df2dx2_approx = (f(x0 + dx) - 2.0 * f(x0) + f(x0 - dx)) /
            (dx * dx);

        // the absolute error
        double err = std::abs(df2dx2_true - df2dx2_approx);

        std::cout << std::format("{:12.6g} {:12.6g} {:12.6g}\n",
                                 dx, df2dx2_approx, err);
    }

}
