#include <iostream>

int main() {

    double h{0.1};
    double sum{0.0};

    // later well learn how to do a loop, but for now
    // we'll explicitly add 10 h's

    sum += h;
    sum += h;
    sum += h;
    sum += h;
    sum += h;
    sum += h;
    sum += h;
    sum += h;
    sum += h;
    sum += h;

    std::cout << "sum == 1:        "
              << (sum == 1.0) << std::endl;

    std::cout << "|sum - 1| < tol: "
              << (std::abs(sum - 1.0) < 1.e-10)
              << std::endl;

}
