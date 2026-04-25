#include <vector>
#include <iostream>
#include <algorithm>
#include <format>

int main() {

    std::vector<double> temp_vec{0.1, 0.2, 0.5, 1.0, 2.0,
                                 3.0, 4.0, 5.0, 7.5, 10.0};

    {
        // a point inbetween elements in our vector

        double T0{1.2};
        auto it = std::ranges::lower_bound(temp_vec, T0);
        auto idx = std::distance(temp_vec.begin(), it);

        std::cout
            << std::format("{} is at index {}; in ({}, {}]\n",
                           T0, idx, temp_vec[idx-1], temp_vec[idx]);
    }

    {
        // a point matching an element in our vector

        double T0{3.0};
        auto it = std::ranges::lower_bound(temp_vec, T0);
        auto idx = std::distance(temp_vec.begin(), it);

        std::cout
            << std::format("{} is at index {}; in ({}, {}]\n",
                           T0, idx, temp_vec[idx-1], temp_vec[idx]);
    }

    {
        // a point less than any element in our vector

        double T0{0.05};
        auto it = std::ranges::lower_bound(temp_vec, T0);
        auto idx = std::distance(temp_vec.begin(), it);

        std::cout
            << std::format("{} is at index {}\n", T0, idx);
    }

    {
        // a point greater than any element in our vector

        double T0{20.0};
        auto it = std::ranges::lower_bound(temp_vec, T0);
        auto idx = std::distance(temp_vec.begin(), it);

        std::cout
            << std::format("{} is at index {}\n", T0, idx);
    }

}
