#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main() {

    const std::vector<int> container{100, 200, 300, 400, 500, 600};

    // search through the entire vector to find the first instance of the
    // element "400"

    auto pos = std::ranges::find(container, 400);

    if (pos == container.end()) {
        std::cout << "element not found\n";
        return 0;
    }

    std::cout << "element found: " << *pos << '\n';

    // output the remaining elements after the one we searched for

    for (int value : std::ranges::subrange(std::next(pos), container.end())) {
        std::cout << value << '\n';
    }
}
