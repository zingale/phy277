#include <iostream>
#include <vector>

std::vector<double> linspace(double xmin, double xmax, int N) {

    // compute spacing between points
    double dx = (xmax - xmin) / static_cast<double>(N - 1);

    // create an empty vector
    std::vector<double> xvec{};

    // loop over point, compute x, add to the vector
    for (int i = 0; i < N; ++i) {
        double x = xmin + i * dx;
        xvec.push_back(x);
    }

    // return new vector
    return xvec;

}


int main() {

    auto v = linspace(0.0, 1.0, 11);

    for (auto e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

}
