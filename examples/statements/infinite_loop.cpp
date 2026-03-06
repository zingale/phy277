#include <iostream>
#include <string>
#include <format>

int main() {

    std::string word{};

    while (true) {

        std::cout << "Enter a word (0 to exit): ";
        std::cin >> word;

        if (word == "0") {
            break;
        }

        std::cout << std::format("{} has {} characters\n", word, word.size());
    }

}
