#include <iostream>
#include <vector>

struct SimpleContainer {

    // member data
    std::vector<double> vec{};

    // constructor
    SimpleContainer() {}

    // member functions
    void add_item(double x) {
        vec.push_back(x);
    }

    double sum() {
        double _sum{};
        for (auto e : vec) {
            _sum += e;
        }
        return _sum;
    }
};

int main() {

    SimpleContainer a;

    a.add_item(10);
    a.add_item(20);

    auto total = a.sum();

    std::cout << "the sum of elements is " << total << std::endl;
}
