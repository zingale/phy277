class Planet:
    """Create a Planet

    Parameters
    ----------
    name: str
        The name of the planet
    a : float
        The semi-major axis
    e : float
        The eccentricity

    """

    def __init__(self, name, a=1, e=0):
        self.name = name
        self.a = a
        self.e = e

    def __str__(self):
        return f"{self.name:10} : {self.a:5.3f}, {self.e:5.3f}"


planets = [Planet("Mercury", a=0.3871, e=0.2056),
           Planet("Venus", a=0.7233, e=0.0068),
           Planet("Earth", a=1.0000, e=0.0167),
           Planet("Mars", a=1.5237, e=0.0934),
           Planet("Jupiter", a=5.2029, e=0.0484),
           Planet("Saturn", a=9.5370, e=0.0539),
           Planet("Uranus", a=19.189, e=0.0473),
           Planet("Neptune", a=30.070, e=0.0086)]

for p in planets:
    print(p)
