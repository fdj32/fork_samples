
 #include <iostream>
#include <memory>

class Foo {};

int main()
{
    auto sp = std::make_shared<Foo>();
    std::cout << sp << '\n';
    std::cout << sp.get() << '\n';
}
