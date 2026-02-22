#include <iostream>
#include <format>
#include <string>

int main() {

    int x{10};
    double y{1.23e-6};
    double z{10.25};
    std::string a{"test"};

    std::cout << std::format("(x = {:03d}; y = {:8.3g}; z = {:4.1f} a = {:10})\n", x, y, z, a);

}
