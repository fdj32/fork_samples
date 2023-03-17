
 #include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>

namespace stb {
void println(auto, auto const& d)
{
    std::ranges::copy(d, std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}
}

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};
    std::deque<int> d;

    std::copy(v.begin(), v.end(),
              std::front_insert_iterator<std::deque<int>>(d));
              // or std::front_inserter(d)

    stb::println("{}", d);
}
