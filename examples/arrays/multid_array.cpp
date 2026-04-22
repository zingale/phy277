#include <iostream>
#include <array>
#include <format>

int main() {

    // create an array with 3 rows, each with
    // 4 columns
    std::array<std::array<double, 4>, 3> M{};

    double val{0.0};
    for (auto &r : M) {
        for (auto &c : r) {
            c = val++;
        }
    }

    for (auto r : M) {
        for (auto c : r) {
            std::cout << std::format("{:4} ", c);
        }
        std::cout << std::endl;
    }
}
