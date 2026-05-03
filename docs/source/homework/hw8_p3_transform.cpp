#include <algorithm>
#include <iostream>
#include <vector>

int main() {

    std::vector<double> is{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    double xmin{1.0};
    double xmax{2.0};
    double dx = (xmax - xmin) / (is.size() - 1);

    std::ranges::transform(is, is.begin(),
                           [=] (int i) {return i * dx + xmin;});

    for (auto e : is) {
        std::cout << e << std::endl;
    }

}
