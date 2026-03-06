#include <iostream>

int main() {

    int n{};

    std::cout << "Enter an integer: ";
    std::cin >> n;

    if (n % 2 == 0 && n % 3 == 0) {
        std::cout << "your number is divisible by 2 and 3" << std::endl;
    }

}
