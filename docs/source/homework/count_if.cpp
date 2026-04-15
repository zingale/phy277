#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

bool is_perfect_square(int x) {
    int xroot = static_cast<int>(std::sqrt(x));
    return x == xroot * xroot;
}

int main() {

    std::vector<int> vec{1, 5, 9, 16, 21, 32, 36, 49, 60, 64};

    auto num = std::ranges::count_if(vec, is_perfect_square);

    std::cout << "there are " << num << " perfect squares in vec" << std::endl;

}
