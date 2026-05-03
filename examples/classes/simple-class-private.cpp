#include <iostream>
#include <numbers>
#include <format>

class Circle {

    // member data
    double radius{};

public:

    // constructor
    Circle(double r) {
        radius = r;
    }

    // member functions
    double r() {
        return radius;
    }

    double circumference() {
        return 2.0 * std::numbers::pi * radius;
    }

    double area() {
        return std::numbers::pi * radius * radius;
    }

};

int main() {

    Circle c(3.0);
    std::cout
        << std::format("circle: r = {:.3f}; C = {:.3f}; A = {:.3f}\n",
                       c.r(), c.circumference(), c.area());

}
