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

    auto num2 = std::ranges::count_if(vec,
                                      [] (int x)
                                          {int xroot = static_cast<int>(std::sqrt(x));
                                           return x == xroot * xroot;});

    std::cout << "there are " << num << " perfect squares in vec" << std::endl;
    std::cout << "there are " << num2 << " perfect squares in vec" << std::endl;

}
