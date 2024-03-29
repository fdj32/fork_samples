#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
 
void visualize_this(const auto& v, int min = 1, int max = 9) {
    for (auto i{min}; i <= max; ++i) {
#ifndef __clang__
        std::ranges::binary_search(v, i) ? std::cout << i : std::cout << '.';
#endif
        std::cout << ' ';
    }
    std::cout << '\n';
}
 
int main()
{
    const auto in1 = {1, 3, 4,    6, 7, 9};
    const auto in2 = {1,    4, 5, 6,    9};
 
    std::vector<int> out;
#ifndef __clang__
    std::ranges::set_symmetric_difference(in1, in2, std::back_inserter(out));
#endif
    visualize_this(in1);
    visualize_this(in2);
    visualize_this(out);
}