#include <iostream>
#include <iomanip>
#include <format>
#include <vector>
#include <algorithm>

struct Planet
{
    std::string name{};
    double a{};            // semi-major axis
    double e{};            // eccentricity
};

std::ostream& operator<< (std::ostream& os, const Planet& p) {

    os << std::format("{:12} : ({:8}, {:8}))", p.name, p.a, p.e);
    return os;
}

int main() {

    std::vector<Planet> planets{{.name="Mercury", .a=0.3871, .e=0.2056},
                                {.name="Venus",   .a=0.7233, .e=0.0068},
                                {.name="Earth",   .a=1.0000, .e=0.0167},
                                {.name="Mars",    .a=1.5237, .e=0.0934},
                                {.name="Jupiter", .a=5.2029, .e=0.0484},
                                {.name="Saturn",  .a=9.5370, .e=0.0539},
                                {.name="Uranus",  .a=19.189, .e=0.0473},
                                {.name="Neptune", .a=30.070, .e=0.0086}};

    std::sort(planets.begin(), planets.end(),
              [] (const Planet& a, const Planet& b) {return a.e < b.e;});

    for (const auto& p : planets) {
        std::cout << p << std::endl;
    }

}
