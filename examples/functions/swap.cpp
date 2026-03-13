#include <iostream>
#include <format>

void swap(double& a, double& b) {
    double tmp = a;
    a = b;
    b = tmp;
}

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}


int main() {

    double x{1.0};
    double y{2.0};

    std::cout << std::format("x = {}, y = {}\n", x, y);

    swap(x, y);

    std::cout << std::format("x = {}, y = {}\n", x, y);

    int a{-100};
    int b{100};

    std::cout << std::format("a = {}, b = {}\n", a, b);

    swap(a, b);

    std::cout << std::format("a = {}, b = {}\n", a, b);
}
