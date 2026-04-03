#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool size_compare(const std::string& a, const std::string& b) {
    return a.size() < b.size();
}

int main() {

    std::vector<std::string> titles{"a new hope",
                                    "the empire strikes back",
                                    "return of the jedi",
                                    "the phantom menace",
                                    "attack of the clones",
                                    "revenge of the sith",
                                    "the force awakens",
                                    "the last jedi",
                                    "the rise of skywalker"};

    std::ranges::sort(titles);

    for (const auto& e : titles) {
        std::cout << e << std::endl;
    }
    std::cout << std::endl;

    // now sort by string length

    std::ranges::sort(titles, size_compare);

    for (const auto& e : titles) {
        std::cout << e << std::endl;
    }
    std::cout << std::endl;

}

