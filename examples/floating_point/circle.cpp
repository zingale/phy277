#include <iostream>
#include <cmath>
#include <numbers>

int main() {

    double r{2.0};

    double area = std::numbers::pi * std::pow(r, 2.0);

    std::cout << "area = " << area << std::endl;

}
