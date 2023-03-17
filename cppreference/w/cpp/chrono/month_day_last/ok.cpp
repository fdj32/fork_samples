
 #include <iostream>
#include <chrono>

int main()
{
    std::cout << std::boolalpha;

    auto mdl {std::chrono::February/std::chrono::last};
    std::cout << (mdl.ok()) << ' ';
    mdl = {std::chrono::month(42)/std::chrono::last};
    std::cout << (mdl.ok()) << '\n';
}
