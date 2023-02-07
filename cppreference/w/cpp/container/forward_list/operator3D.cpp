#include <forward_list>
#include <iterator>
#include <iostream>

#ifndef __clang__
void print(auto const comment, auto const& container)
{
    auto size = std::ranges::distance(container);
    std::cout << comment << "{ ";
    for (auto const& element: container)
        std::cout << element << (--size ? ", " : " ");
    std::cout << "}\n";
}
#endif

int main()
{
    std::forward_list<int> x { 1, 2, 3 }, y, z;
    const auto w = { 4, 5, 6, 7 };
#ifndef __clang__
    std::cout << "Initially:\n";
    print("x = ", x);
    print("y = ", y);
    print("z = ", z);
 
    std::cout << "Copy assignment copies data from x to y:\n";
    y = x;
    print("x = ", x);
    print("y = ", y);
 
    std::cout << "Move assignment moves data from x to z, modifying both x and z:\n";
    z = std::move(x);
    print("x = ", x);
    print("z = ", z);
 
    std::cout << "Assignment of initializer_list w to z:\n";
    z = w;
    print("w = ", w);
    print("z = ", z);
#endif
}