#include <iostream>
#include <format>

#include "rectangle.H"


int main() {

    Rectangle r(1.0, 2.0);
    std::cout << std::format("Rectangle: P = {}, A = {}, is_square = {}\n",
                             r.perimeter(), r.area(), r.is_square());
    Rectangle s(3.0);
    std::cout << std::format("Square: P = {}, A = {}, is_square = {}\n",
                             s.perimeter(), s.area(), s.is_square());

}
