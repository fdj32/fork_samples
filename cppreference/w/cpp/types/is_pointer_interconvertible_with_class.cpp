#include <type_traits>
#include <iostream>
 
struct Foo { int x; };
struct Bar { int y; };
 
struct Baz : Foo, Bar {}; // not standard-layout
 
int main()
{
    #ifndef __clang__
    std::cout << std::boolalpha
        << std::is_same_v<decltype(&Baz::x), int Baz::*> << '\n'
        << std::is_pointer_interconvertible_with_class(&Baz::x) << '\n'
        << std::is_pointer_interconvertible_with_class<Baz, int>(&Baz::x) << '\n';
    #endif
}