#include <iostream>
#include <vector>

int main() {

    std::vector<double> vec{1.0, 2.2, 10.5, 21.3, 25.4, 6.6, 4.2};

    double sum{};
    for (auto e : vec) {
        sum += e;
    }

    double avg = sum / vec.size();

    std::cout << "The average is: " << avg << std::endl;

}
