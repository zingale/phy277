#include <iostream>
#include <cmath>

bool is_prime(int N) {

    bool prime{true};

    int max_factor = static_cast<int>(std::sqrt(N));

    for (int q = 2; q <= max_factor; ++q) {
        if (N % q == 0) {
            prime = false;
            break;
        }
    }

    return prime;
}

int main() {

    const int n_max = 100;

    for (int n = 2; n <= n_max; ++n) {
        if (is_prime(n)) {
            std::cout << n << " is prime!" << std::endl;
        }
    }

}
