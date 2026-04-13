#include <vector>
#include <algorithm>
#include <iostream>


int main() {

    std::vector<int> a{1, 3, 5, 7, 9, 11, 13};
    std::vector<int> b{1, 3, 5, 6, 7, 9, 11, 13};

    auto test = std::ranges::any_of(a, [] (int e) {return e % 2 == 0;});
    std::cout << "any of a are even? " << test << std::endl;

    auto test2 = std::ranges::any_of(b, [] (int e) {return e % 2 == 0;});
    std::cout << "any of b are even? " << test2 << std::endl;

}
