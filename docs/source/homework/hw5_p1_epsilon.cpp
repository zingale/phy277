#include <iostream>

int main() {

    double epsilon{1.0};

    while (1.0 + epsilon != 1.0) {
        epsilon /= 2.0;
    }

    std::cout << "epsilon ~ " << epsilon << std::endl;

}
