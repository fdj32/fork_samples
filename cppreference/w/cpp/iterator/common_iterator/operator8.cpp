
 #include <algorithm>
#include <complex>
#include <iostream>
#include <iterator>
#include <initializer_list>
using std::complex_literals::operator""i;
int main() {
    const auto il = {1i,3.14+2i,3i,4i,5i};
    using CI = std::common_iterator<
        std::counted_iterator<decltype(il)::iterator>,
        std::default_sentinel_t>;
    CI ci { std::counted_iterator{
        std::next(begin(il), 1), ssize(il) - 1} };
    std::cout << *ci << ' ' << ci->real() << '\n';
}
