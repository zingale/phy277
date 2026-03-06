#include <iostream>
#include <cmath>

int main() {

    const int n_max = 100;

    for (int n = 2; n <= n_max; ++n) {

        bool is_prime{true};

        int max_factor = static_cast<int>(std::sqrt(n));

        for (int q = 2; q <= max_factor; ++q) {
            if (n % q == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            std::cout << n << " is prime!" << std::endl;
        }

    }

}
