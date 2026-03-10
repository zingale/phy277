#include <iostream>

void f(double &x) {
    x += 1;
    std::cout << "in the function, x = " << x << std::endl;
}

int main() {

    double z{};
    f(z);
    std::cout << "after calling the funciton, z = " << z << std::endl;

}
