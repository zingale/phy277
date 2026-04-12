#include <iostream>
#include <numeric>
#include <vector>

int main() {

    std::vector<int> vec{10, -1, -50, 101, 4, 2, 800, -250, 277, 8, 12};

    auto sum = std::accumulate(vec.begin(), vec.end(), 0.0);

    std::cout << "the sum is " << sum << std::endl;

    auto prod = std::accumulate(vec.begin(), vec.end(), 1,
                                [] (const int& a, const int& b) {return a * b;});

    std::cout << "the product is " << prod << std::endl;

}
