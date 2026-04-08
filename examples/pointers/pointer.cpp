#include <iostream>

int main() {

    int *a = nullptr;

    int b{};

    a = &b;

    std::cout << a << std::endl;
    std::cout << *a << std::endl;

}
