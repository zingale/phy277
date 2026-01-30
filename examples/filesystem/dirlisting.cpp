#include <iostream>
#include <filesystem>
#include <cstdlib>

int main() {

    std::cout << "current directory is: " << std::filesystem::current_path() << std::endl;

    // change to home directory
    auto home_dir = std::getenv("HOME");
    std::filesystem::current_path(home_dir);
    auto pwd = std::filesystem::current_path();

    std::cout << "current directory is: " << pwd << std::endl;

    // print out files in directory
    for (const auto& entry : std::filesystem::directory_iterator(pwd)) {
        if (is_directory(entry)) {
            std::cout << entry.path().string() << std::endl;
        }
    }

}
