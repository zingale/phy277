#include <cmath>
#include <format>
#include <functional>
#include <iostream>
#include <numbers>
#include <vector>

std::vector<double> fill(const std::vector<double>& x,
                         std::function<double(double)> f) {

    std::vector<double> vec;
    for (auto e : x) {
        vec.push_back(f(e));
    }

    return vec;
}


double f_test(double x) {
    return std::sin(x);
}


int main() {

    std::vector<double> x{0.0,
                          std::numbers::pi / 4.0,
                          std::numbers::pi / 2.0,
                          3.0 * std::numbers::pi / 4.0,
                          std::numbers::pi};

    auto fvec = fill(x, f_test);

    for (std::size_t i = 0; i < fvec.size(); ++i) {
        std::cout << std::format("f({:.4f}) = {:.4f}\n", x[i], fvec[i]);
    }

}
