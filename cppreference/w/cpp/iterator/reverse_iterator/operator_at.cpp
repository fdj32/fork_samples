
 #include <array>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main()
{
    int a[]{0, 1, 2, 3};
    std::reverse_iterator<int*> iter1{std::rbegin(a)};
    for (std::size_t i{}; i != std::size(a); ++i)
        std::cout << iter1[i] << ' '; // decltype(iter1[i]) is `int&`
    std::cout << '\n';

    std::vector v{0, 1, 2, 3};
    std::reverse_iterator<std::vector<int>::iterator> iter2{std::rbegin(v)};
    for (std::size_t i{}; i != std::size(v); ++i)
        std::cout << iter2[i] << ' '; // decltype(iter2[i]) is `int&`
    std::cout << '\n';

    // constexpr context
    constexpr static std::array<int, 4> z{0, 1, 2, 3};
    constexpr std::reverse_iterator<decltype(z)::const_iterator> iter3{std::crbegin(z)};
    static_assert(iter3[1] == 2);

    std::list li{0, 1, 2, 3};
    std::reverse_iterator<std::list<int>::iterator> iter4{std::rbegin(li)};
    *iter4 = 42;   // OK
//  iter4[0] = 13; // compilation error: the underlying iterator
                   // does not model the random access iterator
}
