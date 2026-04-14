#include <iostream>
#include <ranges>

int main() {

    double x{1.0};

    for (auto e : std::views::iota(0, 5)) {
        double x;
        x += e;
    }

    std::cout << x << std::endl;
}
