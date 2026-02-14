#include <iostream>
#include <limits>

int main() {

    std::cout << "double: " << std::endl;
    std::cout << "  smallest value = " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "  lowest value = " << std::numeric_limits<double>::lowest() << std::endl;
    std::cout << "  largest value = " << std::numeric_limits<double>::max() << std::endl;

    std::cout << "int: " << std::endl;
    std::cout << "  smallest value = " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "  lowest value = " << std::numeric_limits<int>::lowest() << std::endl;
    std::cout << "  largest value = " << std::numeric_limits<int>::max() << std::endl;

}
