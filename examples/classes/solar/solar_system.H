#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include <vector>
#include <cassert>

#include "planet.H"

struct SolarSystem {

    double star_mass;
    std::vector<Planet> planets;

    SolarSystem(const double mass)
       : star_mass{mass}
    {
        assert(mass > 0.0);
    }

    void add_planet(const std::string& name,
                    const double a, const double e=0.0) {

        // make sure a planet with that name doesn't already exist
        // if the pointer returned here is not null, then the planet exists

        for (auto p : planets) {
            if (name == p.name) {
                std::cout << "planet already exists" << std::endl;
                return;
            }
        }

        Planet p{.name=name, .a=a, .e=e};
        planets.push_back(p);
    }

    void print_planets() {

        for (const auto& p : planets) {
            std::cout << p << std::endl;
        }
    }
};
#endif
