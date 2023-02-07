#include <algorithm>
#include <iostream>
#include <iterator>
namespace rng = std::ranges;
 
int main() {
    const auto v = { 3, 9, 1, 4, 1, 2, 5, 9 };
#ifndef __clang__
    const auto [min, max] = rng::minmax_element(v);
    std::cout
        << "min = " << *min << ", at [" << rng::distance(v.begin(), min) << "]\n"
        << "max = " << *max << ", at [" << rng::distance(v.begin(), max) << "]\n";
#endif
}