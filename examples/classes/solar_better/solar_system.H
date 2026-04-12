#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include <vector>
#include <cassert>
#include <cmath>

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

        for (auto p : planets) {
            std::cout << p << std::endl;
        }
    }

    int get_planet(const std::string& name, Planet& p_return) {

        // istatus = 1 means the planet doesn't exist

        int istatus = 1;

        for (auto p: planets) {
            if (p.name == name) {
                p_return.name = p.name;
                p_return.a = p.a;
                p_return.e = p.e;
                istatus = 0;
                break;
            }
        }

        return istatus;
    }

    double get_period(const std::string& name) {

        double period = -1;

        Planet p;
        int istatus = get_planet(name, p);

        if (! istatus) {
            period = std::sqrt(std::pow(p.a, 3.0) / star_mass);
        }

        return period;
    }

};
#endif
