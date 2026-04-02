#ifndef PLANET_H
#define PLANET_H

#include <string>
#include <iostream>
#include <format>

struct Planet
{
    std::string name{};
    double a{};            // semi-major axis
    double e{};            // eccentricity
};

std::ostream& operator<< (std::ostream& os, const Planet& p) {
    os << std::format("{:12} : ({:6.3f}, {:6.3f})",
                      p.name, p.a, p.e);
    return os;
}


#endif
