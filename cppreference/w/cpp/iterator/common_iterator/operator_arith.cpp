
 #include <algorithm>
#include <iostream>
#include <iterator>
#include <initializer_list>

int main()
{
    const auto il = {1, 2, 3, 4, 5, 6};

    using CI = std::common_iterator<
                   std::counted_iterator<std::initializer_list<int>::iterator>,
                   std::default_sentinel_t
                   >;

    CI first { std::counted_iterator{ std::begin(il), std::ssize(il) - 2 } };
    CI last { std::default_sentinel };

    while (first != last)
    {
        std::cout << *first;
        std::cout << (++first != last ? ", " : "\n");
    }
}
