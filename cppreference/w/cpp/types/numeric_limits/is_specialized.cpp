
 #include <iostream>
#include <limits>
#include <type_traits>

int main()
{
    enum E{};

    std::cout << std::boolalpha
              << std::numeric_limits<bool>::is_specialized << '\n'
              << std::numeric_limits<long long>::is_specialized << '\n'
              << std::numeric_limits<std::true_type>::is_specialized << '\n'
              << std::numeric_limits<E>::is_specialized << '\n';
}
