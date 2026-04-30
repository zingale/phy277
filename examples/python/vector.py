import math


class Vector:
    """ a general two-dimensional vector """

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return f"({self.x} î + {self.y} ĵ)"

    def __repr__(self):
        return f"Vector({self.x}, {self.y})"

    def __add__(self, other):
        if isinstance(other, Vector):
            return Vector(self.x + other.x, self.y + other.y)
        # it doesn't make sense to add anything but two vectors
        print(f"we don't know how to add a {type(other)} to a Vector")
        raise NotImplementedError

    def __sub__(self, other):
        if isinstance(other, Vector):
            return Vector(self.x - other.x, self.y - other.y)
        # it doesn't make sense to add anything but two vectors
        print(f"we don't know how to add a {type(other)} to a Vector")
        raise NotImplementedError

    def __mul__(self, other):
        if isinstance(other, (int, float)):
            # scalar multiplication changes the magnitude
            return Vector(other*self.x, other*self.y)
        print("we don't know how to multiply two Vectors")
        raise NotImplementedError

    def __matmul__(self, other):
        # a dot product
        if isinstance(other, Vector):
            return self.x*other.x + self.y*other.y
        print("matrix multiplication not defined")
        raise NotImplementedError

    def __rmul__(self, other):
        return self.__mul__(other)

    def __truediv__(self, other):
        # we only know how to multiply by a scalar
        if isinstance(other, (int, float)):
            return Vector(self.x/other, self.y/other)
        print("we don't know how to divide two Vectors")
        raise NotImplementedError

    def __abs__(self):
        return math.sqrt(self.x**2 + self.y**2)

    def __neg__(self):
        return Vector(-self.x, -self.y)

    def cross(self, other):
        # a vector cross product -- we return the magnitude, since it will
        # be in the z-direction, but we are only 2-d
        return abs(self.x*other.y - self.y*other.x)
