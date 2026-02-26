#include <iostream>
#include <cmath>
#include <numbers>
#include <vector>
#include <format>

int main() {

    double pi = std::numbers::pi;

    std::vector<double> angles_deg{5.0, 10.0, 20.0, 40.0};

    std::cout << std::format("{:10} : {:10} {:10} {:10}\n",
                             "angle (d)", "angle (r)", "sine", "err");

    for (auto a : angles_deg) {

        double angle_rad = a * pi / 180;
        double sine = std::sin(angle_rad);
        double err = std::abs(sine - angle_rad);

        std::cout << std::format("{:10.2f} : {:10.3f} {:10.5f} {:10.5g}\n",
                                 a, angle_rad, sine, err);

    }
}
