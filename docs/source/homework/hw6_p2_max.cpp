#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

double max_element(const std::vector<double>& vec) {

    double max{std::numeric_limits<double>::lowest()};

    for (auto e : vec) {
        max = std::max(e, max);
    }

    return max;

}


int max_index(const std::vector<double>& vec) {

    double max{std::numeric_limits<double>::lowest()};
    int idx{-1};

    for (int i = 0; i < static_cast<int>(vec.size()); ++i) {
        if (vec[i] > max) {
            max = vec[i];
            idx = i;
        }
    }

    return idx;

}

int main() {

    std::vector<double> vec{-100.3, 5.64, -25.3, 10.9, 50.3, -2.4, 13.9};

    double max_val = max_element(vec);
    int idx = max_index(vec);

    std::cout << "max element is " << max_val << std::endl;
    std::cout << "index of max element is " << idx << std::endl;

    if (vec[idx] == max_val) {
        std::cout << "our functions agree" << std::endl;
    }

}
