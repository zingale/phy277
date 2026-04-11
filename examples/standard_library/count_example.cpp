#include <algorithm>
#include <vector>
#include <iostream>

int main() {

    std::vector<int> v{1, 1, 4, 6, 10, 1, 3, -2, -8, 0};

    auto num = std::ranges::count(v, 1);
    std::cout << "the number of times 1 appears in v is " << num << std::endl;

}
