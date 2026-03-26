#include <iostream>
#include <vector>
#include <numbers>
#include <cmath>
#include <format>

struct Projectile {
    double t{};
    double x{};
    double y{};
};

int main() {

    std::vector<Projectile> trajectory{};

    double angle{};
    double vmag{};
    double dt{};

    std::cout << "# Enter angle (degrees), velocity (m/s), and time interval (s): ";
    std::cin >> angle >> vmag >> dt;
    std::cout << std::endl;

    // convert angle to radians
    angle *= std::numbers::pi / 180.0;

    // initial conditions
    double t{};
    double x0{};
    double y0{};

    const double g = -9.81;

    trajectory.push_back(Projectile{.t=t, .x=x0, .y=y0});

    while (trajectory[trajectory.size()-1].y >= 0.0) {
        t += dt;
        double xnew = x0 + vmag * std::cos(angle) * t;
        double ynew = y0 + vmag * std::sin(angle) * t + 0.5 * g * std::pow(t, 2.0);

        trajectory.push_back(Projectile{.t=t, .x=xnew, .y=ynew});
    }

    for (const auto& e : trajectory) {
        std::cout << std::format("{:7.4f} {:8.5f} {:8.5f}\n",
                                 e.t, e.x, e.y);
    }

}
