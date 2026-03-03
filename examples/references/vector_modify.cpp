#include <iostream>
#include <vector>

int main() {

    std::vector<double> container(10, 0.0);

    // here "e" is just a double that is initialized via a copy to the
    // current element of container.  Since it is not a reference, it
    // is disconnected completely from container.

    for (auto e : container) {
        e = 1.0;
    }

    std::cout << "current vector: ";
    for (auto e : container) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // now we create a reference (double&) to the current element in
    // the container.  This means that "e" is sharing the exact memory
    // in the vector as the current element, so if we modify it,
    // container is modified too.

    for (auto& e : container) {
        e = 2.0;
    }

    std::cout << "current vector: ";
    for (auto e : container) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

}
