#ifndef VECTOR_2D_H
#define VECTOR_2D_H

#include <iostream>
#include <cmath>

class Vector2d {

private:

    // our member data

    double x;
    double y;

public:

    // default constructor

    Vector2d()
        : x{0.0}, y{0.0}
    {}

    // another constructor

    Vector2d(double _x, double _y)
        : x{_x}, y{_y}
    {}

    // setters

    inline void set_x(double _x) {x = _x;}

    inline void set_y(double _y) {y = _y;}

    // operators

    // add two vectors

    Vector2d operator+(const Vector2d& vec) {
        return Vector2d(x + vec.x, y + vec.y);
    }

    // subtract two vectors

    Vector2d operator-(const Vector2d& vec) {
        return Vector2d(x - vec.x, y - vec.y);
    }

    // unary minus

    Vector2d operator-() {
        return Vector2d(-x, -y);
    }

    // multiplication

    Vector2d operator*(double a) {
        return Vector2d(x * a, y * a);
    }

    friend Vector2d operator*(double a, const Vector2d& v);

    // division

    Vector2d operator/(double a) {
        return Vector2d(x / a, y / a);
    }

    // special vector operations

    double dot(const Vector2d& v) {
        return x * v.x + y * v.y;
    }

    double cross(const Vector2d& v) {
        return x * v.y - y * v.x;
    }

    double abs() {
        return std::sqrt(x * x + y * y);
    }

    // equality

    bool operator==(const Vector2d& v) const = default;

    // stream operators -- not class members

    friend std::ostream& operator<< (std::ostream& os, const Vector2d& v);
    friend std::istream& operator>> (std::istream& is, Vector2d& v);

};

inline
Vector2d operator*(double a, const Vector2d& v) {
    return Vector2d(v.x * a, v.y * a);
}

inline
std::ostream& operator<< (std::ostream& os, const Vector2d& v)
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

inline
std::istream& operator>> (std::istream& is, Vector2d& v)
{
   is >> v.x >> v.y;
   return is;
}

#endif
