#include <iostream>
#include <vector>
#include <cmath>
#include <format>

struct Planet
{
    std::string name{};
    double a{};            // semi-major axis
    double e{};            // eccentricity
};

int main() {

    const std::vector<Planet> planets{{.name="Mercury", .a=0.3871, .e=0.2056},
                                      {.name="Venus",   .a=0.7233, .e=0.0068},
                                      {.name="Earth",   .a=1.0000, .e=0.0167},
                                      {.name="Mars",    .a=1.5237, .e=0.0934},
                                      {.name="Jupiter", .a=5.2029, .e=0.0484},
                                      {.name="Saturn",  .a=9.5370, .e=0.0539},
                                      {.name="Uranus",  .a=19.189, .e=0.0473},
                                      {.name="Neptune", .a=30.070, .e=0.0086}};

    for (const auto& p : planets) {
        std::cout << std::format("{} has a period of {:.2f} years\n",
                                 p.name, std::sqrt(std::pow(p.a, 3)));
    }

}
