
 #include <iostream>
#include <memory>

class Foo {};

int main()
{
    auto p = std::make_unique<Foo>();
    std::cout << p << '\n';
    std::cout << p.get() << '\n';
}
