#include <iostream>
#include <string_view>
int main()
{
    std::string_view v = "Hello, world";
    v = v.substr(7);
    std::cout << v << '\n';
}