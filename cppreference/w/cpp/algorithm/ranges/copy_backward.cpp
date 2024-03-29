#include <algorithm>
#include <iostream>
#include <ranges>
#include <string_view>
#include <vector>

#ifndef __clang__
void print(std::string_view rem, std::ranges::forward_range auto const& r) {
    for (std::cout << rem << ": "; auto const& elem : r)
        std::cout << elem << ' ';
    std::cout << '\n';
}
#endif

int main()
{
#ifndef __clang__
    const auto src = {1, 2, 3, 4};
    print("src", src);
 
    std::vector<int> dst (src.size() + 2);
    std::ranges::copy_backward(src, dst.end());
    print("dst", dst);
 
    std::ranges::fill(dst, 0);
    const auto [in, out] =
        std::ranges::copy_backward(src.begin(), src.end() - 2, dst.end());
    print("dst", dst);
 
    std::cout
        << "(in - src.begin) == " << std::distance(src.begin(), in) << '\n'
        << "(out - dst.begin) == " << std::distance(dst.begin(), out) << '\n';
#endif
}