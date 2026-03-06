class Planet:
    def __init__(self, name, a, e):
        self.name = name
        self.a = a
        self.e = e

    def __str__(self):
        ostr = f"{self.name:12} : ({self.a:8}, {self.e:8})"
        return ostr


def main():

    planets = [Planet("Mercury",  0.3871, 0.2056),
               Planet("Venus",    0.7233, 0.0068),
               Planet("Earth",    1.0000, 0.0167),
               Planet("Mars",     1.5237, 0.0934),
               Planet("Jupiter",  5.2029, 0.0484),
               Planet("Saturn",   9.5370, 0.0539),
               Planet("Uranus",  19.189,  0.0473),
               Planet("Neptune", 30.070,  0.0086)]

    planets.sort(key=lambda p: p.e)

    for p in planets:
        print(p)


if __name__ == "__main__":
    main()
