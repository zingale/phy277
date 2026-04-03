#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

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

        if (std::ranges::any_of(planets,
                                [=] (const Planet& p) {return p.name == name;})) {
            std::cout << "planet already exists" << std::endl;
            return;
        }

        Planet p{.name=name, .a=a, .e=e};
        planets.push_back(p);
    }

    void print_planets() {

        for (const auto& p : planets) {
            std::cout << p << std::endl;
        }
    }

    Planet* get_planet(const std::string& name) {

        auto it = std::ranges::find_if(planets,
                                       [&] (const Planet& p) {return p.name == name;});

        if (it != planets.end()) {
            return &(*it);
        }

        return nullptr;
    }

    double get_period(const std::string& name) {

        double period{-1.0};

        const auto *p = get_planet(name);

        if (p) {
            period = std::sqrt(std::pow(p->a, 3.0) / star_mass);
        }

        return period;
    }

};
#endif
