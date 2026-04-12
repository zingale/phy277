#include <iostream>

double square1(double x) {
    return x * x;
}

void square2(double &x) {
    x *= x;
}

int main() {

    double x{2.0};
    auto xsq = square1(x);
    std::cout << "result is " << xsq << std::endl;

    square2(x);
    std::cout << "updated x is " << x << std::endl;

}
