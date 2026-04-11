#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> int_vec{100, 200, 300};

    auto it = std::ranges::find(int_vec, 200);

    int_vec.insert(it, 150);

    for (auto e : int_vec) {
        std::cout << e << std::endl;
    }

}
