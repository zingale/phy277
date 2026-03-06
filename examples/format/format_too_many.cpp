#include <iostream>
#include <format>
#include <string>

int main() {

    int x{10};
    double y{1.23e-4};
    double z{-10.5};
    std::string a{"test"};

    std::cout << std::format("x = {}; y = {}; a = {}\n", x, y, a, z);


}
