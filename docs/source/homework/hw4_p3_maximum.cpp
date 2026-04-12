#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int main() {

    std::vector<double> vec{-100.3, 5.64, -25.3, 10.9, 50.3, -2.4, 13.9};

    double max{std::numeric_limits<double>::lowest()};

    for (auto e : vec) {
        max = std::max(e, max);
    }

    std::cout << "the maximum element is " << max << std::endl;
}
