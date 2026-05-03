#include <cassert>
#include <iostream>

#include "vector2d.H"

int main() {

    // create 2 vectors

    Vector2d v1(1, 2);
    Vector2d v2(2, 4);

    // ask for input for a third:
    Vector2d v_user{};
    std::cout << "Enter x and y for a vector: ";
    std::cin >> v_user;
    std::cout << "Your vector is: " << v_user << std::endl;
    std::cout << std::endl;

    // output our vectors

    std::cout << "test vectors: " << std::endl;
    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;
    std::cout << std::endl;

    // output their sum

    auto v_add = v1 + v2;
    assert(v_add == Vector2d(3, 6));
    std::cout << "v1 + v2 = " << v_add << std::endl;

    // create a new vector from subtracting our two vectors

    auto v_sub = v1 - v2;
    assert(v_sub == Vector2d(-1, -2));
    std::cout << "v1 - v2 = " << v_sub << std::endl;
    std::cout << std::endl;

    // test multiplication
    auto v_mul1 = v1 * 10;
    auto v_mul2 = 10 * v1;
    assert (v_mul1 == v_mul2);
    std::cout << "v1 * 10 = " << v_mul1 << std::endl;
    std::cout << "10 * v1 = " << v_mul2 << std::endl;
    std::cout << std::endl;

    // test division
    auto v_div = v2 / 2;
    assert (v_div == v1);
    std::cout << "v2 / 2 = " << v_div << std::endl;
    std::cout << std::endl;

    // test vector products
    auto v_dot = v1.dot(v2);
    assert(v_dot == 10);
    std::cout << "v1 . v2 = " << v_dot << std::endl;

    auto v_cross = v1.cross(v2);
    assert(v_cross == 0);
    std::cout << "v1 x v2 = " << v_cross << std::endl;

    auto v_mag = v1.abs();
    assert(std::abs(v_mag - std::sqrt(5)) < 1.e-14);
    std::cout << "|v1| = " << v_mag << std::endl;

}
