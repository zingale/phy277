#include <string>
#include <iostream>

int main() {

    std::string a{"π"};

    std::cout << "our string requires " << a.size() << " bytes" << std::endl;
    std::cout << a[0] << std::endl;

}
