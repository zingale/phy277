#include <iostream>

int main() {

    std::cout << "Enter a number: ";
    int n{};
    std::cin >> n;

    if (n < 0) {
        std::cout << "you entered a negative number" << std::endl;
    } else if (n > 0) {
        std::cout << "you entered a positive number" << std::endl;
    } else {
        std::cout << "you entered zero" << std::endl;
    }

}
