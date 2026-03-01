#include <iostream>
#include <format>

struct Planet
{
    std::string name{};
    double a{};            // semi-major axis
    double e{};            // eccentricity
};

int main() {

    // create empty Planet and initialize later
    Planet p1{};
    p1.name = "Mercury";
    p1.a = 0.3871;
    p1.e = 0.2056;

    // use initialization list
    Planet p2{"Venus", 0.7233, 0.0068};

    // specify components in initialization list
    Planet p3{.name="Earth", .a=1.0000, .e=0.0167};

    std::cout << std::format("Planet {} has a = {} AU and e = {}\n",
                             p1.name, p1.a, p1.e);

    std::cout << std::format("Planet {} has a = {} AU and e = {}\n",
                             p2.name, p2.a, p2.e);

    std::cout << std::format("Planet {} has a = {} AU and e = {}\n",
                             p3.name, p3.a, p3.e);

}
