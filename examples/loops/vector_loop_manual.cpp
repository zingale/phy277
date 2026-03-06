#include <format>
#include <iostream>
#include <vector>

int main() {

    std::vector<int> vec{1, 2, 4, 8, 16, 32, 64, 128};

    for (std::size_t i = 0; i < vec.size(); ++i) {
        std::cout << std::format("element {} is {}\n", i, vec[i]);
    }

}
