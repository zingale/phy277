#include <iostream>
#include <numbers>
#include <format>

struct Circle {

    // member data
    double radius{};

    // constructor
    Circle(double r) {
        radius = r;
    }

    // member functions
    double circumference() {
        return 2.0 * std::numbers::pi * radius;
    }

    double area() {
        return std::numbers::pi * radius * radius;
    }

};

int main() {

    Circle c(3.0);
    std::cout << std::format("circle with radius {:6.3f} has circumference {:6.3f} and area {:6.3f}\n",
                             c.radius, c.circumference(), c.area());

}
