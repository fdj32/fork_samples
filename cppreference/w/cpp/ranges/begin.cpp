
 #include <iostream>
#include <vector>
#include <ranges>

int main() 
{
    std::vector<int> v = { 3, 1, 4 };
    auto vi = std::ranges::begin(v);
    std::cout << *vi << '\n';
    *vi = 42; // OK

    int a[] = { -5, 10, 15 };
    auto ai = std::ranges::begin(a);
    std::cout << *ai << '\n';
    *ai = 42; // OK
}
