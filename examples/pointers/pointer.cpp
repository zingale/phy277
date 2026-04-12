#include <iostream>

int main() {

    int *a = nullptr;

    int b{};

    a = &b;

    std::cout << "pointer value (memory location) = "
              << a << std::endl;
    std::cout << "value of what we are pointing to (dereferencing pointer) = "
              << *a << std::endl;

}
