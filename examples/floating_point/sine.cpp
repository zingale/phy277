#include <cmath>
#include <iostream>
#include <numbers>

int main() {

    double angle_degrees{60.0};
    double angle_radians = angle_degrees * std::numbers::pi / 180.0;
    double sine_angle = std::sin(angle_radians);

    std::cout << sine_angle << std::endl;

}
