#include <iostream>
#include <vector>

int main() {

    std::vector<double> container{1.0, 2.0, 3.0, 4.0};

    for (auto e : container) {
        std::cout << e << std::endl;
    }

}
