#ifndef VECTOR_3D_H
#define VECTOR_3D_H

#include <iostream>

class Vector3d {

private:

    // our member data

    double x;
    double y;
    double z;

public:

    // default constructor

    Vector3d()
        : x{0.0}, y{0.0}, z{0.0}
    {}

    // another constructor

    Vector3d(double _x, double _y, double _z)
        : x{_x}, y{_y}, z{_z}
    {}

    // setters

    inline void set_x(double _x) {x = _x;}

    inline void set_y(double _y) {y = _y;}

    inline void set_z(double _z) {z = _z;}

    // operators

    // add two vectors

    Vector3d operator+(const Vector3d& vec) {
        return Vector3d(x + vec.x, y + vec.y, z + vec.z);
    }

    // subtract two vectors

    Vector3d operator-(const Vector3d& vec) {
        return Vector3d(x - vec.x, y - vec.y, z - vec.z);
    }

    // unary minus

    Vector3d operator-() {
        return Vector3d(-x, -y, -z);
    }

    // << is not a class member, but needs access to the member data

    friend std::ostream& operator<< (std::ostream& os, const Vector3d& v);
};

inline
std::ostream& operator<< (std::ostream& os, const Vector3d& v)
{
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

#endif
