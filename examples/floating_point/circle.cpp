#include <iostream>
#include <numbers>

int main() {

    double r{2.0};

    // we'll compute r**2 as r * r
    double area = std::numbers::pi * r * r;

    std::cout << "area = " << area << std::endl;

}
