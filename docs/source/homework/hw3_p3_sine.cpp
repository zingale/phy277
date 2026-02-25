#include <iostream>
#include <cmath>
#include <numbers>

int main() {

    double pi = std::numbers::pi;

    double angle_degrees = 5.0;
    double angle_radians = angle_degrees * pi / 180.0;
    double sine = std::sin(angle_radians);

    std::cout << angle_degrees << " "
              << angle_radians << " "
              << sine << " "
              << std::abs(sine - angle_radians) << std::endl;


    angle_degrees = 10.0;
    angle_radians = angle_degrees * pi / 180.0;
    sine = std::sin(angle_radians);

    std::cout << angle_degrees << " "
              << angle_radians << " "
              << sine << " "
              << std::abs(sine - angle_radians) << std::endl;


    angle_degrees = 20.0;
    angle_radians = angle_degrees * pi / 180.0;
    sine = std::sin(angle_radians);

    std::cout << angle_degrees << " "
              << angle_radians << " "
              << sine << " "
              << std::abs(sine - angle_radians) << std::endl;


    angle_degrees = 40.0;
    angle_radians = angle_degrees * pi / 180.0;
    sine = std::sin(angle_radians);

    std::cout << angle_degrees << " "
              << angle_radians << " "
              << sine << " "
              << std::abs(sine - angle_radians) << std::endl;


}
