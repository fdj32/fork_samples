
 #include<experimental/reflect>
#include<iostream>

using refl = std::experimental::reflect;

float f;
struct P{};

int main()
{
    std::cout << refl::get_source_line_v<reflexpr(f)> << '\n';
    std::cout << refl::get_source_line_v<reflexpr(P)> << '\n';
}
