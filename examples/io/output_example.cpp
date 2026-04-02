#include <iostream>
#include <fstream>
#include <format>
#include <vector>

struct Planet
{
    std::string name;
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

    std::ofstream of("planets.txt");

    for (const auto& p : planets) {
        of << std::format("{:12} {:6.3f} {:6.3f}\n",
                          p.name, p.a, p.e);
    }

    of.close();

}
