#include <iostream>
#include <vector>

double sum(const std::vector<double>& vec) {

    double s{};
    for (auto e : vec) {
        s += e;
    }

    return s;
}

int main() {

    std::vector<double> v{1.0, 2.0, 3.0, 4.0, 5.0};

    auto s = sum(v);

    std::cout << "the sum is " << s << std::endl;

}
