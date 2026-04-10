#include <iostream>
#include <vector>
#include <ranges>

int main() {

    std::vector<int> vec{1, 2, 4, 8, 16};

    for (auto e : std::views::reverse(vec)) {
        std::cout << e << std::endl;
    }

}
