
 #include <iostream>
#include <initializer_list>

int main()
{
    std::initializer_list<int> empty_list;
    std::cout << "empty_list.size(): " << empty_list.size() << '\n';

    // create initializer lists using list-initialization
    std::initializer_list<int> digits {1, 2, 3, 4, 5};
    std::cout << "digits.size(): " << digits.size() << '\n';

    // special rule for auto means 'fractions' has the
    // type std::initializer_list<double>
    auto fractions = {3.14159, 2.71828};
    std::cout << "fractions.size(): " << fractions.size() << '\n';

    // create constexpr initializer list (since C++14)
    static constexpr auto ab = {'a', 'b'};
    static_assert(ab.size() == 2 and *ab.begin() == 'a');
}
