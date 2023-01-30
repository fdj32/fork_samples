#include <iostream>
#include <chrono>
 
int main()
{
    constexpr std::chrono::month m1{6};
    constexpr std::chrono::month m2{8};
 
    std::cout << std::boolalpha
        << (m1 < m2) << ' ' << (m1 == m1) << ' ' << (m1 <= m2) << ' '
        << (m2 > m1) << ' ' << (m2 != m1) << ' ' << (m2 >= m1) << '\n';
}