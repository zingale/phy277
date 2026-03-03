#include <array>
#include <iostream>

int main() {

    std::array<int, 10> arr{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "size of array is " << arr.size() << std::endl;

    for (auto e : arr) {
        std::cout << e << std::endl;
    }

}
