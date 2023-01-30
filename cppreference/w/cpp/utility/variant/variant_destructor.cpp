#include <variant>
#include <cstdio>
 
int main()
{
    struct X { ~X() { puts("X::~X();"); } };
    struct Y { ~Y() { puts("Y::~Y();"); } };
 
    {
        puts("entering block #1");
        std::variant<X,Y> var;
        puts("leaving block #1");
    }
 
    {
        puts("entering block #2");
        std::variant<X,Y> var{ std::in_place_index_t<1>{} }; // constructs var(Y)
        puts("leaving block #2");
    }
}