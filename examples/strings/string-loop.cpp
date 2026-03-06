#include <iostream>
#include <string>

int main() {

    std::string a{"May the force be with you."};

    for (auto c : a) {
        std::cout << c << std::endl;
    }
}
