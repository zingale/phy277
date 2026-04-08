#include <iostream>
#include <ranges>

int main() {

    for (auto e : std::views::iota(0, 5)) {
        std::cout << e << std::endl;
    }

}
