#include <iostream>
#include <algorithm>
#include <vector>

int main() {

    std::vector<int> vec{10, -1, -50, 101, 4, 0, 800, -250, 277, 8, 12};

    auto it_max = std::ranges::max_element(vec);

    std::cout << "maximum is " << *it_max << std::endl;

    // now find what index it is

    auto index = std::ranges::distance(vec.begin(), it_max);

    std::cout << "the index is " << index << std::endl;

}
