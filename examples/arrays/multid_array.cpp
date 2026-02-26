#include <iostream>
#include <array>
#include <format>

using row_arr_t = std::array<double, 4>;
using fixed_mat_t = std::array<row_arr_t, 3>;

int main() {

    fixed_mat_t M{0.0};

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
