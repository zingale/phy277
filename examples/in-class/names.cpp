#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main() {

    std::vector<std::string> names{"luke",
                                   "leia",
                                   "han",
                                   "chewy",
                                   "obi-wan",
                                   "yoda",
                                   "vader",
                                   "lando"};

    for (auto &nm : names) {
        nm[0] = std::toupper(nm[0]);
    }


    for (const auto &nm : names) {
        std::cout << nm << std::endl;
    }

}
