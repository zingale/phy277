import math

class Planet:
    def __init__(self, name, a=1, e=0):
        self.name = name
        self.a = a
        self.e = e

    def __str__(self):
        return f"{self.name:10} : {self.a:5.3f}, {self.e:5.3f}"


class SolarSystem:

    def __init__(self, mass):
        assert mass > 0
        self.star_mass = mass
        self.planets = []

    def add_planet(self, name, a, e=0.0):
        if any(p.name == name for p in self.planets):
            raise ValueError("planet already exists")

        self.planets.append(Planet(name, a, e))

    def print_planets(self):
        for p in self.planets:
            print(p)

    def get_planet(self, name):
        p = [p for p in self.planets if p.name == name]
        if len(p) > 0:
            return p[0]
        print(f"planet {name} does not exist")

        return None

    def get_period(self, name):
        p = self.get_planet(name)
        if p:
            return math.sqrt(p.a**3 / self.star_mass)
        return None

if __name__ == "__main__":

    ss = SolarSystem(2.0)

    ss.add_planet("alpha", 1.0)
    ss.add_planet("beta", 1.5, 0.1)
    ss.add_planet("gamma", 3.0, 0.24)

    ss.print_planets()
    print(f"period of alpha = {ss.get_period('alpha')}")

    # note that get_planet returns a reference to the Planet in our
    # solar system, so if we update it, we the change is reflected

    print()
    print("changing eccentricity of beta")

    p = ss.get_planet("beta")
    p.e = 0.9

    ss.print_planets()

    # and what happens if we try to get a planet that doesn't exist?

    print()
    print("accessing a planet that doesn't exist")

    p2 = ss.get_planet("earth")
    print(p2)

