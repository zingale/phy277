#include <cstdlib>
#include <iostream>
#include <vector>

int main() {

    std::vector<long> fib{0, 1};

    std::cout << "How many terms of the Fibonacci sequence to compute? (N > 2) ";

    int N{};
    std::cin >> N;

    if (N <= 2) {
        // we already have that -- abort
        std::cout << "too few" << std::endl;
        std::exit(1);
    }

    // add to the sequence

    while (static_cast<int>(fib.size()) < N) {
        auto s = fib.size();
        fib.push_back(fib[s-1] + fib[s-2]);
    }

    // now output

    for (auto e : fib) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

}

