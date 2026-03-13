#include <cmath>
#include <format>
#include <iostream>
#include <vector>

struct Point {
    double x;
    double y;
};

int main() {

    std::vector<Point> points{Point{.x=1.5, .y=2.3},
                              Point{.x=3.2, .y=1.6},
                              Point{.x=5.3, .y=0.1},
                              Point{.x=8.6, .y=2.5}};

    for (auto p : points) {
        double dist = std::sqrt(std::pow(p.x, 2.0) + std::pow(p.y, 2.0));
        std::cout << std::format("Point ({:5.2f}, {:5.2f}) is {:6.3f} from the origin.\n",
                                 p.x, p.y, dist);

    }

}
