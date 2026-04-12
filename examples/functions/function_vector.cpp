#include <iostream>
#include <vector>

// take a vector as input and return a new vector
std::vector<double> f1(const std::vector<double>& v_in) {

    std::vector<double> v_out;

    for (auto e : v_in) {
        v_out.push_back(2.0 * e);
    }

    return v_out;

}

// update a vector through the argument list
void f2(const std::vector<double>& v_in,
        std::vector<double>& v_out) {

    // erase any stored contents
    v_out.clear();

    for (auto e : v_in) {
        v_out.push_back(2.0 * e);
    }

}

// attempt to return a reference to our vector
std::vector<double>& f3(const std::vector<double>& v_in) {

    std::vector<double> v_out;

    for (auto e : v_in) {
        v_out.push_back(2.0 * e);
    }

    return v_out;

}

int main() {

    std::vector<double> v_old{0.0, 1.0, 2.0, 3.0, 4.0, 5.0};

    // method 1: new vector is returned

    auto v_new1 = f1(v_old);

    for (auto e : v_new1) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // method 2: pass the new vector as an argument
    // and it is updated

    std::vector<double> v_new2{};

    f2(v_old, v_new2);

    for (auto e : v_new2) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // method 3: try to get a reference to a vector
    // created in the function.  This will not work.

    auto v_new3 = f3(v_old);

    for (auto e : v_new3) {
        std::cout << e << " ";
    }
    std::cout << std::endl;


}
