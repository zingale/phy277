#include <iostream>
#include <format>

#include "planet.H"

std::ostream& operator<< (std::ostream& os, const Planet& p) {
    os << std::format("{:12} : ({:8}, {:8}))", p.name, p.a, p.e);
    return os;
}
