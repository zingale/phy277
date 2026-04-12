#include <iostream>
#include <vector>
#include <format>

int main() {

    std::vector<int> nums{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int previous{};
    for (auto &n : nums) {
        n += previous;
        previous = n;
    }

    int i{};
    for (auto n : nums) {
        std::cout << std::format("{:2} : {:3}\n", i, n);
        i++;
    }

}
