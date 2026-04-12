#include <iostream>
#include <format>

long fac(long N) {

    if (N < 0) {
        return 0;
    }

    if (N == 0) {
        return 1;
    } else {
        return N * fac(N-1);
    }

}

int main() {

    int A{5};
    std::cout << std::format("{}! = {}\n", A, fac(A));
}
