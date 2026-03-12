#include <cmath>
#include <format>
#include <iostream>
#include <vector>

int main() {

    std::vector<double> vec{1.0, 2.2, 10.5, 21.3, 25.4, 6.6, 4.2};

    double sum{};
    for (auto e : vec) {
        sum += e;
    }

    double avg = sum / vec.size();

    double sigma{};

    for (auto e : vec) {
        sigma += std::pow(e - avg, 2.0);
    }
    sigma = std::sqrt(sigma / vec.size());

    std::cout << std::format("The average / std dev is: {:.3f} +/- {:.3f}\n",
                             avg, sigma);

}
