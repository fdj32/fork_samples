#include <span>
#include <iostream>
 
int main()
{
    constexpr char str[] = "ABCDEF\n";
 
    const std::span sp{str};
 
    for (auto n{sp.size()}; n != 2; --n) {
        std::cout << sp.last(n).data();
    }
}