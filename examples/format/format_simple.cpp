#include <iostream>
#include <format>

int main() {

    int x{10};
    double y{1.23e-4};
    std::string a{"test"};

    std::string formatted = std::format("x = {}; y = {}; a = {}\n", x, y, a);

    std::cout << formatted;

}
