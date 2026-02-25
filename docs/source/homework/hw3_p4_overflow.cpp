#include <iostream>
#include <limits>

int main() {

    short int x = std::numeric_limits<short int>::max();

    x++;

    std::cout << "x is now: " << x << std::endl;

}
