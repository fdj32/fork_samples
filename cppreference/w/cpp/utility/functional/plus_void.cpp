
 #include <functional>
#include <iostream>

int main()
{
    std::string a = "Hello ";
    const char* b = "world";
    std::cout << std::plus<>{}(a, b) << '\n';
}
