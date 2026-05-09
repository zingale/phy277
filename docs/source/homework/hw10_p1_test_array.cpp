#include <iostream>

#include "array.H"

int main() {

    Array a(5, 4);

    // there are a few ways we can initialize this we could just have
    // 20 lines where we use the () operator with the row, column
    // manually and set it to the value.  That would be fine.

    // a little nicer is something like this:

    std::vector<double> vals{-20.0, 4.5, 1.45, 7.9,
                             -1.2, -10.4, 8.9, 6.49,
                             12.7, 14.4, 6.5, -10.9,
                             -2.4, 2.15, 1.15, 20.4,
                             -22.5, 64.5, -1.8, -7.1};

    // and then we make use of the fact that _data is contiguous
    for (int i = 0; i < static_cast<int>(vals.size()); ++i) {
        a._data[i] = vals[i];
    }

    std::cout << "our array is: " << std::endl;
    std::cout << a << std::endl;

    std::cout << "sum of elements is " << a.sum() << std::endl;

    std::cout << "max element is " << a.max() << std::endl;
    std::cout << "min element is " << a.min() << std::endl;

}
