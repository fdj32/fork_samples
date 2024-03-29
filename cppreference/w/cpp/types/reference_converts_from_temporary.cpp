
 #include <type_traits>
#include <iostream>

int main()
{
    std::cout << std::boolalpha
        << std::reference_converts_from_temporary_v<int&&, int> << '\n'
        << std::reference_converts_from_temporary_v<const int&, int> << '\n'
        << std::reference_converts_from_temporary_v<int&&, int&&> << '\n'
        << std::reference_converts_from_temporary_v<const int&, int&&> << '\n'
        << std::reference_converts_from_temporary_v<int&&, long&&> << '\n';
        << std::reference_converts_from_temporary_v<int&&, long> << '\n';
}
