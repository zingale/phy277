#include <iostream>

int main() {

    std::cout << "Enter a number: ";

    double x{};
    std::cin >> x;

    std::cout << "You entered " << x << std::endl;

    // if std::cin.fail() is 1, then the read failed
    std::cout << "Failed? " << std::cin.fail() << std::endl;
}
